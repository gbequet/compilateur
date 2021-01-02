#include "assembler.h"
#include "util.h"
#include "../intermediate/symbol_table.h"
#include "../intermediate/yacc_util.h"

int next_reg = 8;
int next_mem = 0;
int cpt_label_str = 0;
liste *reg_utilise; // contient tout les registre qui sont encore utilisé
liste *reg_temp_utilise; // contient tout les registres $t qui sont encore utilisé
liste *reg_arg_utilise; // contient tout les registre $a qui sont encore utilisé

// renvoie le registre qu'on pourra utiliser pour le temp
int getRegTemp()
{
  int res;
  if (last(reg_temp_utilise) < 16) // il y a des registres tmp disponible
  {
    res = last(reg_temp_utilise) + 1;
    concat(reg_temp_utilise, creelist(res));
    return res;
  }
  else // tout les registres tmp 8-15 sont utilisés
  {
    // $15 contient le resultat intermediaire du calcul
    // on le move dans $8 pour pouvoir de nouveau utiliser des registres tmp
    fprintf(yyout, "move $8, $16\n");
    reg_temp_utilise = creelist(8);
    return 8;
  }
}

// met a jour les offset des variables dans la pile
void maj_addr_pile(entry symbol_table[], int depl)
{
  for (int i = 0; i < SIZE; i++)
  {
    if (symbol_table[i].id != NULL)
    {
      if (symbol_table[i].addr_pile != -1) // var deja declarée
      {
        symbol_table[i].addr_pile += (4 * depl);
      }
    }
  }
}

void genmips(context_t *context)
{
  size_t i, size_for_update_pile;
  quad q;
  char *symbol;
  int place;
  entry e;
  interval_list *copy;

  /* on commence avec aucun registre tmp utilisé
  si je met 7 ici c'est pour pas avoir le pb d'une liste NULL
  et la fonction getRegTemp() renvoie le plus grand element + 1
  du coup quand on voudra notre premier registre on aura le 8 */
  reg_temp_utilise = creelist(7);

  genDebutMips(context);

  fprintf(yyout, "\nmain:\n");

  // declaration de toutes les variables du contexte dans la pile
  // PB : si on est dans le contexte global on doit les mettre dans le .data
  for (i = 0; i < SIZE; i++)
  {
    e = context->symbol_table[i];
    if (e.id != NULL)
    {
      switch (e.typedesc.type)
      {
      case TYPE_INT:
        maj_addr_pile(context->symbol_table, 1);
        fprintf(yyout, "addi $sp, $sp, -4\n");
        context->symbol_table[i].addr_pile = 0;
        break;

      case TYPE_ARRAY:
        copy = e.rangelist;
        size_for_update_pile = 1;
        while (copy != NULL)
        {
          size_for_update_pile *= copy->taille;
          copy = copy->next;
        }
        fprintf(yyout, "addi $sp, $sp, -%lu\n", 4*size_for_update_pile);

        maj_addr_pile(context->symbol_table, size_for_update_pile);
        context->symbol_table[i].addr_pile = 0;
        break;

      case TYPE_STRING: // PB : les string on les mets dans le .data ou dans la pile?
        // fprintf(yyout, "%s: .asciiz \"\"\n", e.id);
        break;

      default:
        break;
      }
    }
  }

  for (i = 0; i < context->nextquad; i++)
  {
    q = context->quad_table[i];

    if (q.label == 1)
    {
      fprintf(yyout, "L%d:\n", q.ligne);
    }

    if (q.res.type == QO_NAME)
    {
      symbol = q.res.u.name;
      place = getRegTemp();
      concat(reg_temp_utilise, creelist(place));
      if (place > 100)
        update_mem(symbol, place - 100);
      else
        update_reg(symbol, place);
    }

    switch (q.type)
    {
    case Q_PLUS:
      arithmetique(q, place, "add");
      break;

    case Q_MOINS:
      arithmetique(q, place, "sub");
      break;

    case Q_FOIS:
      arithmetique(q, place, "mul");
      break;

    case Q_DIV:
      arithmetique(q, place, "div");
      break;

    case Q_POW:
      puissance(q, place);
      break;

    case Q_ACCESS_ELEM_ARR: // q.res := *q.op1
      acces_element_tableau(q, place);
      break;

    case Q_SAVE_ELEM_ARR: // *q.res := q.op1
      sauvegarde_element_tableau(q);
      break;

    case Q_AFFECT:
      affectation(q, place, reg_temp_utilise);
      reg_temp_utilise = creelist(7);
      break;

    case Q_WRITE:
      cpt_label_str = ecriture(q, place, cpt_label_str, reg_temp_utilise);
      break;

    case Q_READ:
      lecture(q);
      break;
    
    case Q_SUP:
      place = getRegTemp();
      concat(reg_utilise, creelist(place));

      conditionnelle(q, "bgt");
      break;

    case Q_SUPEQ:
      place = getRegTemp();
      concat(reg_utilise, creelist(place));

      conditionnelle(q, "bge");
      break;
    
    case Q_INF:
      place = getRegTemp();
      concat(reg_utilise, creelist(place));

      conditionnelle(q, "blt");
      break;
    
    case Q_INFEQ:
      place = getRegTemp();
      concat(reg_utilise, creelist(place));

      conditionnelle(q, "ble");
      break;

    case Q_EQ:
      place = getRegTemp();
      concat(reg_utilise, creelist(place));

      conditionnelle(q, "beq");
      break;
    
    case Q_DIFF:
      place = getRegTemp();
      concat(reg_utilise, creelist(place));

      conditionnelle(q, "bne");
      break;
    
    case Q_GOTO:
      fprintf(yyout, "j L%zu\n", q.res.u.etiquette);
      break;

    default:
      break;
    }
  }

  // exit propre
  fprintf(yyout, "\nL%zu:\n", context->nextquad);
  fprintf(yyout, "\nli $v0, 10\n");
  fprintf(yyout, "syscall\n");
}
