#ifndef ESCALE_PAS_PARSER_SRC_YACC_UTIL_H_
#define ESCALE_PAS_PARSER_SRC_YACC_UTIL_H_

#include <stdio.h>
#include "quad.h"
#include "list.h"
#include "symbol_table.h"

extern int cpt_var_temp;
extern FILE *yyout;

struct expr_s {
  quadop quadop;
  struct typedesc typedesc;
  liste *true;
  liste *false;
};


struct expr_s arithmetique_expr(struct expr_s op1, operation_type_e operation, struct expr_s op2);

struct expr_s bool_expr(struct expr_s op1, operation_type_e operation, struct expr_s op2);

struct expr_s array_expr(char *op1, operation_type_e operation, arrind* op2);

/*La fonction cree un identificateur pour une variable temporaire, 
rajoute la variable temporaire dans la table des symboles, 
cree un quadop de type QO_NAME et renvoie ce quadop*/
quadop newtemp();

/*La fonction prend en parametre un quadruplet, le rajoute s'il y a 
de la place dans quad_table. Sinon un realloc est fait pour creer
plus de place dans quad_table et le quadruplet est rajouté.
A la fin la variable nextquad est incrementé*/
void gencode(quad q);

/*Parametres: descripteur de fichier vers lequel la sortie sera dirigée.
La fonction va creer du code assembleur à partir du tableau quad_table*/
//void genmips(FILE* file);

struct typedesc concat_types(type_e type, struct typedesc typedesc);

#endif
