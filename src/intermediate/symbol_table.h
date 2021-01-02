#ifndef ESCALE_PAS_PARSER_SRC_SYMBOL_TABLE_H_
#define ESCALE_PAS_PARSER_SRC_SYMBOL_TABLE_H_

#define SIZE 500
#include "list.h"

extern int nb_var; //commpteur nbr de variables dans symbol_table, cf newname()

typedef enum {
  TYPE_X,  //type inconnu, utilisé dans la tab des symboles pour les array
  TYPE_INT,
  TYPE_BOOL,
  TYPE_UNIT,
  TYPE_STRING,
  TYPE_ARRAY,
  TYPE_FUNC
} type_e;

struct typedesc {

  type_e type;

  type_e returntype;
  type_e params[7];
  int nb_params;
};

struct typelist {
  struct typedesc typelist[7]; /* max 7 args by function */
  int nb_types;
  arrind* array_indexes; 
};

struct entry {
  char *id; //l'identificateur de la variable
  struct typedesc typedesc; //type de l'identificateur
  int nbparams; //Si c'est une fonction on a besoin de vérifier le nombre de paramètres
  int reg;  //le registre ou la variable est stockée
  int mem_adr; //adresse memoire ou la var est stockée(n'est plus utilisé)
  int last_use; //derniere fois que l'element est utilisé dans global_code
  int addr_pile; // offset dans la pile $sp
  int nb_dim; //nombre de dimensions s'il s'agit d'un array
  interval_list* rangelist; //listes de intervalles pour chaque dimension
  type_e valtype; //Type des valeurs dans un array
};
typedef struct entry entry;

/* renvoie l'index du caractere dans symbol_table */
int hash(const char *symbol);

/*Fonction prend en parametre le nom de la variable
et renvoie tous ses attributs dans la table des symboles.
Renvoie NULL si le symbole n'est pas dans la table des symboles*/
entry *lookup(char *symbol);


/* Ajoute un nouvel identificateur a symbol_table*/
entry* newname(char *symbol);

/*La fonction verifie si les types des variables passées en parametre à 
une fonction sont du bon type*/
void check_function_type(struct typedesc functype, struct typelist args);

/*La fonction va afficher sur la sortie standard la table 
des symboles*/
void print_table();

/*La fonction va mettre la valeur numl pour l'attribut "last_use"
de la variable symbol dans la table des symboles*/
void update_use(char *symbol, int numl);

/*La fonction va mettre la valeur mem_adr pour l'attribut "mem_adr"
de la variable symbol dans la table des symboles*/
void update_mem(char *symbol, int mem_adr);

/*La fonction va mettre la valeur reg pour l'attribut "reg"
de la variable symbol dans la table des symboles*/
void update_reg(char *symbol, int reg);

#endif
