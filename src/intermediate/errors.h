#ifndef ESCALE_PAS_PARSER_SRC_ERRORS_TABLE_H_
#define ESCALE_PAS_PARSER_SRC_ERRORS_TABLE_H_

/*La fonction affiche un message d'erreur sur stderr et fait un exit(1).
Utilisé losrqu'on rencontre une erreur lors d'un lookup() dans la table 
des symboles*/
void lookup_error(char *symbol);

/*La fonction affiche un message d'erreur sur stderr et fait exit(1).
Utilisé lorsqu'on rencontre une erreur de types */
void type_error(void);

/*La fonction affiche un message d'erreur sur stderr et fait un exit(1).
Utilisé lorsque le nombre de parametres n'est pas correct dans une 
fonction*/
void nb_args_error(int params, int args);

#endif
