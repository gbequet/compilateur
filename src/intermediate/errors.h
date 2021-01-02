#ifndef ESCALE_PAS_PARSER_SRC_ERRORS_TABLE_H_
#define ESCALE_PAS_PARSER_SRC_ERRORS_TABLE_H_


void lookup_error(char *symbol);
void type_error(void);
void nb_args_error(int params, int args);

#endif
