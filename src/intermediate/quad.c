#include <stdio.h>
#include "quad.h"
#include "list.h"
#include "symbol_table.h"
#include "yacc_util.h"
#include "yacc.tab.h"

quadop quadop_cst(int cst) {
  quadop newop;
  newop.type = QO_CST;
  newop.u.cst = cst;

  return newop;
}

quadop quadop_bool(int bool) {
  quadop newop = quadop_cst(bool);
  newop.type = QO_BOOL;

  return newop;
}

quadop quadop_name(char *name) {
  quadop newop;
  newop.type = QO_NAME;
  newop.u.name = name;

  return newop;
}

quadop quadop_str(char *str) {
  quadop newop;
  newop.type = QO_STRING;
  newop.u.str = str;

  return newop;
}

quadop quadop_etiquette(size_t eti) {
  quadop newop;
  newop.type = QO_ETI;
  newop.u.etiquette = eti;

  return newop;
}

quadop quadop_label(char *label)
{
  quadop newop;
  newop.type = QO_LABEL;
  newop.u.name = label;

  return newop;
}

quadop quadop_empty() {
  quadop newop;
  newop.type = QO_EMPTY;

  return newop;
}

quad quad_make(operation_type_e op, quadop arg1, quadop arg2, quadop res, int ligne) {
  quad newquad;
  newquad.type = op; //operateur Q_PLUS, Q_MOINS...
  newquad.op1 = arg1;
  newquad.op2 = arg2;
  newquad.res = res;
  newquad.label = 0;
  newquad.ligne = ligne;

  return newquad;
}

void print_quad(quad *quad) {

  switch (quad->type) {
    case Q_PLUS:

      print_quadop(quad->res);
      printf(" := ");
      print_quadop(quad->op1);
      printf(" + ");
      print_quadop(quad->op2);
      break;

    case Q_MOINS:

      print_quadop(quad->res);
      printf(" := ");
      print_quadop(quad->op1);
      printf(" - ");
      print_quadop(quad->op2);
      break;

    case Q_FOIS:

      print_quadop(quad->res);
      printf(" := ");
      print_quadop(quad->op1);
      printf(" * ");
      print_quadop(quad->op2);
      break;

    case Q_DIV:

      print_quadop(quad->res);
      printf(" := ");
      print_quadop(quad->op1);
      printf(" / ");
      print_quadop(quad->op2);
      break;

    case Q_POW:

      print_quadop(quad->res);
      printf(" := ");
      print_quadop(quad->op1);
      printf(" ^ ");
      print_quadop(quad->op2);
      break;

    case Q_AFFECT:

      print_quadop(quad->res);
      printf(" := ");
      print_quadop(quad->op1);
      break;

    case Q_WRITE:

      printf("print ");
      print_quadop(quad->res);
      break;

    case Q_READ:

      printf("read ");
      print_quadop(quad->res);
      break;

    case Q_SUP:

      printf("if ");
      print_quadop(quad->op1);
      printf(" > ");
      print_quadop(quad->op2);
      printf(" goto ");
      print_quadop(quad->res);
      break;

    case Q_SUPEQ:

      printf("if ");
      print_quadop(quad->op1);
      printf(" >= ");
      print_quadop(quad->op2);
      printf(" goto ");
      print_quadop(quad->res);
      break;

    case Q_INF:

      printf("if ");
      print_quadop(quad->op1);
      printf(" < ");
      print_quadop(quad->op2);
      printf(" goto ");
      print_quadop(quad->res);
      break;

    case Q_INFEQ:

      printf("if ");
      print_quadop(quad->op1);
      printf(" <= ");
      print_quadop(quad->op2);
      printf(" goto ");
      print_quadop(quad->res);
      break;

    case Q_EQ:

      printf("if ");
      print_quadop(quad->op1);
      printf(" = ");
      print_quadop(quad->op2);
      printf(" goto ");
      print_quadop(quad->res);
      break;

    case Q_DIFF:

      printf("if ");
      print_quadop(quad->op1);
      printf(" <> ");
      print_quadop(quad->op2);
      printf(" goto ");
      print_quadop(quad->res);
      break;

    case Q_GOTO:

      printf("goto ");
      print_quadop(quad->res);
      break;

    case Q_CALL:

      print_quadop(quad->res);
      printf(" := call ");
      print_quadop(quad->op1);
      printf(", ");
      print_quadop(quad->op2);
      break;

    case Q_PARAM:

      printf("param ");
      print_quadop(quad->op1);
      break;

    case Q_ACCESS_ELEM_ARR:

      print_quadop(quad->res);
      printf(" := ");
      printf("*");
      print_quadop(quad->op1);
      break;

    case Q_SAVE_ELEM_ARR:

      printf("*");
      print_quadop(quad->op1);
      printf(" := ");
      print_quadop(quad->res);
      break;

    default:

      printf("quad enum not handled");
      break;

  }
}

void print_quadop(quadop quadop) {
  switch (quadop.type) {
    case QO_BOOL:

      printf("%s", quadop.u.cst == 1 ? "true" : "false");
      break;

    case QO_CST: printf("%d", quadop.u.cst);
      break;

    case QO_NAME: printf("%s", quadop.u.name);
      break;

    case QO_STRING: printf("%s", quadop.u.str);
      break;

    case QO_ETI: printf("%zu", quadop.u.etiquette);
      break;

    case QO_LABEL: printf("%s", quadop.u.name);
      break;

    case QO_EMPTY: printf("<empty quadop>");
      break;

    default: printf("quadop enum not handled");
      break;
  }

}
