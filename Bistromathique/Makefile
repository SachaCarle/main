##
## Makefile for Makefile in /home/david_h/rendu/Piscine_C_eval_expr
## 
## Made by David Sullivan
## Login   <david_h@epitech.net>
## 
## Started on  Sun Oct 26 20:01:47 2014 David Sullivan
## Last update Tue Feb  2 17:21:35 2016 Sacha Carle
##

NAME	= calc

LIB	= ./lib/my/libmy.a

HEADER	= ./include/struct.h \
	  ./include/my.h \
	  ./include/my_parse.h \
	  ./include/my_calc.h \
	  ./bistromathique.h

SRC	= main.c \
	  tree.c \
	  is_char_in_str.c \
	  my_expr_parse.c \
	  expr_sign.c \
	  my_instr.c \
	  str_to_tree.c \
	  node_test.c \
	  op_eq.c \
	  my_parse.c \
	  my_add.c \
	  my_subb.c \
	  base.c \
	  base_parse.c \
	  test_bistro.c \
	  int_to_base.c \
	  my_mult.c \
	  my_divmod.c \
	  eval_expr.c \
	  test_expr.c \

OBJ	= $(SRC:.c=.o)

TEST	= -fprofile-arcs -ftest-coverage

TESTCOV = ./test.sh

GCDA	= $(SRC:.c=.gcda)

GCNO	= $(SRC:.c=.gcno)

GCOV	= $(SRC:.c=.c.gcov)

all: $(NAME)

$(NAME): $(OBJ)
	cd lib/my ; make re
	gcc -o $(NAME) $(OBJ) $(HEADER) $(LIB)

malloc_test:
	LD_PRELOAD=~/PSU_2015_malloc/libmy_malloc.so ./test.sh

test: 
	cd lib/my ; make re
	gcc -c $(SRC) $(TEST)
	gcc -o $(NAME) $(OBJ) $(HEADER) $(LIB) $(TEST) 

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

tclean: clean
	rm -f $(GCDA) $(GCNO)

covclean: tclean
	  rm -f $(GCOV)

dotest: test
	$(TESTCOV)
	gcov $(GCDA)

re: fclean all

purge: tclean fclean covclean

retest: tclean covclean dotest
