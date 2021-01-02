#ifndef ESCALE_PAS_PARSER_UTIL_H_
#define ESCALE_PAS_PARSER_UTIL_H_

#include <stdio.h>
#include "../intermediate/symbol_table.h"
#include "../intermediate/yacc_util.h"
#include "../intermediate/context.h"

/*Fonction à appeler au debut, fait toutes les declarations et initialisation*/
void genDebutMips(context_t *context);

/*Genere le code assembleur pour une operation arithmetique*/
void arithmetique(quad q, int place, char *fct);

/*Genere le code assembleur pour le calcul d'une puissance*/
void puissance(quad q, int place);

/*Genere le conde assembleur pour une affectation*/
void affectation(quad q, int place, liste *reg_temp_utilise);

/*Genere le code assembleur pour effectuer une lecture sur l'entree standard*/
void lecture(quad q);

/*Genere le code assembleur pour effectuer une ecriture sur la sortie 
standard et renvoie le nouveau compteur pour les declaration de string*/ 
int ecriture(quad q, int place, int cpt_label_str, liste *reg_temp_utilise);

/*Genere le code assembleur pour les expressions conditionelles*/
void conditionnelle(quad q, char *fct);

/*Genere le code assembleur pour l'acces à un element du tableau 
ex. x = y[i]*/
void acces_element_tableau(quad q, int place);

/*Genere le code assembleur pour la sauvegarde d'un element du tableau
ex. y[i] = x*/
void sauvegarde_element_tableau(quad q);

#endif