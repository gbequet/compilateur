#ifndef ESCALE_PAS_PARSER_SRC_ASSEMBLER_TABLE_H_
#define ESCALE_PAS_PARSER_SRC_ASSEMBLER_TABLE_H_

#include "context.h"
#include "list.h"
/*Valeur entre 8 et 24
Parce que les registres temporaires vont de $8 à $25 mais on va prendre
t9 pour les adresses memoire donc on va utiliser les registre $8-$24*/
//extern int next_reg;

/*Initialisation à 0, valeurs allant de 0 à 8192(si je ne me trompe pas)
next_mem nous servira pour calculer l'offset qu'on utilisera pour acceder
un endroit en memoire.
Par exemple:
index = next_mem*4
index($t9) est l'equivalent de t9[next_mem]*/
//extern int next_mem;

/*La fonction getreg() va renvoyer le numero d'un registre temporaire libre 
s'il y'en a, si ils sont tous pris, la fonction va regarder "last_use" dans 
la table des symboles pour voir s'il y a des variables qui ne sont plus 
utilisées et va donc renvoyer le numero d'un registre qui n'est plus utilisé, 
sinon, la fonction va renvoyer une adresse memoire. Pour savoir distinguer 
s'il s'agit d'n numero de registre ou d'une adresse memoire, on va ajouter 100 
à la valeur de l'adresse memoire.
Parametres:
quadnum: le numero de ligne dans global_code où l'on se trouve au moment de 
l'appel de cete fonction
symbol: le nom de la variable pour laquelle on cherche un registre*/
int getreg(context_t *context, int quadnum, char *symbol);



/*Fonction pour generer du code MIPS*/
void genmips(context_t *context);


#endif
