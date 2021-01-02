#include <stdio.h>
#include "quad.h"
#include "list.h"
#include "symbol_table.h"
#include "yacc_util.h"
#include "context.h"
#include "errors.h"

#define CODECHUNK 16

int cpt_var_temp = 0;

struct expr_s arithmetique_expr(struct expr_s op1, operation_type_e operation, struct expr_s op2) {

  if (op1.typedesc.type != TYPE_INT || op2.typedesc.type != TYPE_INT)
    type_error();

  if (op1.quadop.type==QO_NAME)
    update_use(op1.quadop.u.name, current_context->nextquad);
  if (op2.quadop.type==QO_NAME)
    update_use(op2.quadop.u.name, current_context->nextquad);
  quadop t = newtemp();
  quad q = quad_make(operation, op1.quadop, op2.quadop, t, current_context->nextquad);
  gencode(q);

  return (struct expr_s){.quadop = t, .typedesc.type = TYPE_INT};
}

struct expr_s bool_expr(struct expr_s op1, operation_type_e operation, struct expr_s op2) {

  struct expr_s expr;

  if (op1.typedesc.type != TYPE_INT || op2.typedesc.type != TYPE_INT)
    type_error();

  expr.true = creelist(current_context->nextquad);
  quad q = quad_make(operation, op1.quadop, op2.quadop, emp, current_context->nextquad);
  gencode(q);
  expr.false = creelist(current_context->nextquad);
  q = quad_make(Q_GOTO, emp, emp, emp, current_context->nextquad);
  gencode(q);
  expr.typedesc.type = TYPE_BOOL;

  return expr;
}

// cette fonction utilise 4 registres temporaires!
// consequence ? voir getRegTemp() ou on va plus que jusqu'a 11
// en fait jsp peut etre qu'on s'en fout mdr
struct expr_s array_expr(char *op1, operation_type_e operation, arrind* op2)
{
  entry *e = lookup(op1);
  if (e == NULL)
    lookup_error(op1);

  quadop t0, t1, t2, t3;
  quad q;
  interval_list *copybis = e->rangelist;
  interval_list *copy;
  quadop lasttemp;


  /* on genere le code mips qui calcul l'addresse de l'element dans le tableau */

  t2 = newtemp();
  lasttemp = t2;

  // t2 := 0
  q = quad_make(Q_PLUS, quadop_cst(0), quadop_cst(0), t2, current_context->nextquad);
  gencode(q);

  for (int i = 0; (i < e->nb_dim) && (copybis != NULL); i++)
  {
    copy = copybis;
    t0 = newtemp();

    // t0 := sup(i) - indice(i)
    q = quad_make(Q_MOINS, quadop_cst(copy->sup), op2->quadop, t0, current_context->nextquad);
    gencode(q);

    q = quad_make(Q_SUPEQ, t0, quadop_cst(copy->taille), quadop_label("SEGFAULT"), current_context->nextquad);
    gencode(q);
    q = quad_make(Q_INF, t0, quadop_cst(0), quadop_label("SEGFAULT"), current_context->nextquad);
    gencode(q);

    if (i == e->nb_dim - 1)
    {
      t2 = newtemp();

      // t2 := t2 + t0
      q = quad_make(Q_PLUS, lasttemp, t0, t2, current_context->nextquad);
      gencode(q);
      lasttemp = t2;
    }
    else if (i == e->nb_dim - 2)
    {
      t1 = newtemp();

      // t1 := t0 * taille de la derniere dimension
      q = quad_make(Q_FOIS, t0, quadop_cst(copy->next->taille), t1, current_context->nextquad);
      gencode(q);

      t2 = newtemp();
      // t2 := t2 + t1
      q = quad_make(Q_PLUS, lasttemp, t1, t2, current_context->nextquad);
      gencode(q);
      lasttemp = t2;
    }
    else
    {
      copy = copy->next;

      t1 = newtemp();

      // t1 = taille(i+1) * taille(i+2)
      q = quad_make(Q_FOIS, quadop_cst(copy->taille), quadop_cst(copy->next->taille), t1, current_context->nextquad);
      gencode(q);

      copy = copy->next->next;

      for (int j=i+1; (j<e->nb_dim) && (copy != NULL); j++)
      {
        // t1 = t1 * taille(j)
        q = quad_make(Q_FOIS, t1, quadop_cst(copy->taille), t1, current_context->nextquad);
        gencode(q);

        copy = copy->next;
      }

      // t2 := t2 + t1
      t2 = newtemp();
      q = quad_make(Q_PLUS, lasttemp, t1, t2, current_context->nextquad);
      gencode(q);
      lasttemp = t2;
    }

    op2 = op2->next;
    copybis = copybis->next;
  }

  copy = e->rangelist;

  // t2 := 4 * t2
  t2 = newtemp();
  q = quad_make(Q_FOIS, lasttemp, quadop_cst(4), t2, current_context->nextquad);
  gencode(q);
  lasttemp = t2;

  // t2 := TAB + t2
  t2 = newtemp();
  q = quad_make(Q_PLUS, quadop_name(op1), lasttemp, t2, current_context->nextquad);
  gencode(q);
  lasttemp = t2;

  if (operation == Q_ACCESS_ELEM_ARR)
  {
    t3 = newtemp();
    q = quad_make(operation, lasttemp, emp, t3, current_context->nextquad);
    gencode(q);
    return (struct expr_s){.quadop = t3, .typedesc.type = e->valtype};
  }

  lasttemp.for_tab = 1;
  return (struct expr_s){.quadop = lasttemp, .typedesc.type = e->valtype};
}


quadop newtemp() {
  size_t size = 10;
  char *temp = (char *) malloc(size*sizeof(char)); //il faut free apres

  if (temp==NULL) {
    fprintf(stderr, "Erreur malloc, fonction newtemp\n");
    exit(EXIT_FAILURE);
  }
  if (snprintf(temp, size, "t%d", cpt_var_temp) >= (int) size) {
    fprintf(stderr, "Erreur snprintf dans newtemp(), chaine tronqué\n");
    exit(EXIT_FAILURE);
  }

  cpt_var_temp++;
  if (lookup(temp) == NULL)
    newname(temp);

  return quadop_name(temp);
}

void gencode(quad q) {
  if (current_context->nextquad%CODECHUNK==0) {
    size_t ns = current_context->nextquad + CODECHUNK;
    current_context->quad_table = realloc(current_context->quad_table, ns*sizeof(quad));
  }
  current_context->quad_table[current_context->nextquad++] = q;
}
