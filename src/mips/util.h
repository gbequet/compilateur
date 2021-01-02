#ifndef ESCALE_PAS_PARSER_UTIL_H_
#define ESCALE_PAS_PARSER_UTIL_H_

#include <stdio.h>
#include "../intermediate/symbol_table.h"
#include "../intermediate/yacc_util.h"
#include "../intermediate/context.h"

void genDebutMips(context_t *context);

void arithmetique(quad q, int place, char *fct);

void puissance(quad q, int place);

void affectation(quad q, int place, liste *reg_temp_utilise);

void lecture(quad q);
// renvoie le nouveau compteur pour les declaration de string
int ecriture(quad q, int place, int cpt_label_str, liste *reg_temp_utilise);

void conditionnelle(quad q, char *fct);

void acces_element_tableau(quad q, int place);
void sauvegarde_element_tableau(quad q);

#endif