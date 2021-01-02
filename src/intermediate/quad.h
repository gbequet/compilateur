#ifndef ESCALE_PAS_PARSER_SRC_QUAD_H_
#define ESCALE_PAS_PARSER_SRC_QUAD_H_

#include <stdlib.h>

typedef enum {
  QO_CST,
  QO_BOOL,
  QO_NAME,
  QO_STRING,
  QO_ETI,
  QO_LABEL,
  QO_EMPTY
} operand_type_e;

typedef union {
  int cst;
  char *name; //le nom de l'operande
  char *str; //le nom de l'operande
  size_t etiquette; // numéro de ligne du label
} operand_value_u;

typedef struct {

  operand_type_e type;
  operand_value_u u;

  int for_tab; // 1 si le temp est utilisé pour le calcul de l'acces ou le save d'un element d'un tableau

} quadop;

typedef enum
{
  Q_PLUS,
  Q_MOINS,
  Q_FOIS,
  Q_DIV,
  Q_POW,
  Q_AFFECT,
  Q_WRITE,
  Q_READ,
  Q_SUP,
  Q_SUPEQ,
  Q_INF,
  Q_INFEQ,
  Q_EQ,
  Q_DIFF,
  Q_GOTO,
  Q_CALL,
  Q_PARAM,
  Q_ACCESS_ELEM_ARR,
  Q_SAVE_ELEM_ARR
} operation_type_e;

typedef struct quad {

  operation_type_e type;
  quadop res;
  quadop op1;
  quadop op2;
  int label; // 1 si on peut arriver sur ce quad apres un branchement, 0 sinon
  int ligne; // ligne du quad

} quad;

/*Fonctions qui creent et renvoient un quadop de type:
QO_CST, QO_NAME, QO_ETI, QO_EMPTY etc.*/
quadop quadop_cst(int cst);
quadop quadop_name(char *name);
quadop quadop_str(char *str);
quadop quadop_bool(int bool);
quadop quadop_etiquette(size_t eti);
quadop quadop_label(char *label);
quadop quadop_empty();

#define emp quadop_empty()

/*Fonction qui cree et renvoie un quad*/
quad quad_make(operation_type_e op, quadop arg1, quadop arg2, quadop res, int ligne);

/*La fonction prend en parametre un quadruplet et l'affiche 
sur la sortie standard sous une forme plus comprehensible 
ex: (+,1,t0,c) => c = t0 + 1*/
void print_quad(quad *quad);

/*La fonction prend en parametre une operande et affiche la valeur 
stocké. QO_CST: un entier, QO_NAME: un string, QO_ETI: un entier etc.*/
void print_quadop(quadop quadop);

#endif
