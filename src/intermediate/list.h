#ifndef _UTIL_H_
#define _UTIL_H_

#include "quad.h"

typedef struct liste {
  size_t quad_eti; //index d'un quad dans quad_table, obtenu avec 'nextquad'
  struct liste *next; //vers NULL si elt unique, vers elt suivant sinon
} liste;

typedef struct interval{
  int inf; //borne inferieure de l'intervalle
  int sup; //borne superieure de l'intervalle
  int taille; //taille du tableau, sup-inf +1
  struct interval* next; 
}interval_list;

typedef struct arrind{
  quadop quadop;
  struct arrind* next;
} arrind;

typedef struct identifierlist{
  char *name;
  struct identifierlist* next;
} identifierlist;


/*La fonction va creer une liste contenant 1 seul element, l'adresse d'un quad 
dans quad_table. next va pointer vers NULL*/
liste *creelist(size_t eti);

/*La fonction va créer une nouvelle liste qui sera la 
concatenation des listes l1 et l2*/
liste *concat(liste *l1, liste *l2);
liste *concat3(liste *l1, liste *l2, liste *l3);

// renvoie 1 si eti est dans l, 0 sinon
int contains(liste *l, size_t eti);

// renvoie le dernier element de la liste
// precondition : l ne doit pas etre vide
int last(liste *l);

/*La fonction complete les quad (dont les adresse se situent dans la liste l) 
avec l'etiquette eti*/
void complete(liste *l, size_t eti);

/*La fonction va liberer la mémoire alloué par une liste*/
void free_list(liste *l);

/*La fonction print_liste va afficher les elements d'une liste*/
void print_liste(liste *l);

/*La fonction va un nouveau interval_list et renvoyer un pointeur 
vers cette nouvelle liste*/
interval_list* cree_interval(int inf, int sup);

/*La fonction concatene deux listes d'intervalles et renvoie un pointeur sur 
la nouvelle liste*/
interval_list* concat_interval(interval_list* range1, interval_list* range2);


arrind* cree_arrind(quadop quadop);
arrind* concat_arrind(arrind* a1, arrind* a2);


identifierlist *creeidentlist(char *name);
identifierlist *concatidentlist(identifierlist *l1, identifierlist *l2);

#endif
