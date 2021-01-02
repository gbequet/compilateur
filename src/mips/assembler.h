#ifndef ESCALE_PAS_PARSER_SRC_ASSEMBLER_TABLE_H_
#define ESCALE_PAS_PARSER_SRC_ASSEMBLER_TABLE_H_

#include "context.h"
#include "list.h"


/*La fonction renvoie le numero de registre qu'on pourra utiliser pour 
stocker une variable temporaire*/
int getRegTemp();

/*Met à jour les offset des variables dans la pile*/
void maj_addr_pile(entry symbol_table[], int depl);

/*Fonction pour generer du code MIPS à partir du code 3 adresses*/
void genmips(context_t *context);


#endif
