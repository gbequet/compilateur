NAME          =    scalpa

CC            =    gcc


DSRC          = src
DINTERMEDIATE = $(DSRC)/intermediate
DMIPS         = $(DSRC)/mips

SRC           = $(DINTERMEDIATE)/lex.yy.c \
			    $(DINTERMEDIATE)/list.c \
                $(DINTERMEDIATE)/yacc.tab.c \
                $(DINTERMEDIATE)/symbol_table.c \
                $(DINTERMEDIATE)/quad.c \
                $(DINTERMEDIATE)/yacc_util.c \
                $(DINTERMEDIATE)/context.c \
                $(DINTERMEDIATE)/errors.c \
                \
                $(DMIPS)/assembler.c \
                $(DMIPS)/util.c \

INC           = -I$(DINTERMEDIATE) -I$(DMIPS)

CFLAGS        = -Wall -W -Wextra -g $(INC)

MAIN          = $(DSRC)/main.c

OBJ           = $(SRC:.c=.o) $(MAIN:.c=.o)


all: pre $(NAME)

pre:
	bison -d $(DINTERMEDIATE)/yacc.y
	mv yacc.tab.c yacc.tab.h $(DINTERMEDIATE)
	lex -ts $(DINTERMEDIATE)/lex.lex > $(DINTERMEDIATE)/lex.yy.c

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) 

clean:
	rm -f $(OBJ) $(DINTERMEDIATE)/lex.yy.c $(DINTERMEDIATE)/yacc.tab.c $(DINTERMEDIATE)/yacc.tab.h

fclean: clean
	rm -f $(NAME)

re: fclean all

debug: CFLAGS += -g
debug: re
