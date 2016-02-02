##
## Makefile for libmy in /home/david_h/rendu/Piscine_C_J11/lib/my
## 
## Made by David Sullivan
## Login   <david_h@epitech.net>
## 
## Started on  Mon Oct 20 09:28:22 2014 David Sullivan
## Last update Thu Oct 30 15:13:07 2014 david_h
##

CFLAGS += -Wall
CFLAGS += -pedantic

NAME	= libmy.a

HEADER	= ../../include/my.h

SRC	= convert_base.c\
	  my_find_prime_sup.c\
	  my_getnbr.c\
	  my_isneg.c\
	  my_is_prime.c\
	  my_power_rec.c\
	  my_putchar.c\
	  my_put_nbr.c\
	  my_putstr.c\
	  my_revstr.c\
	  my_showmem.c\
	  my_showstr.c\
	  my_sort_int_tab.c\
	  my_square_root.c\
	  my_strcapitalize.c\
	  my_strcat.c\
	  my_strcmp.c\
	  my_strcpy.c\
	  my_str_isalpha.c\
	  my_str_islower.c\
	  my_str_isnum.c\
	  my_str_isprintable.c\
	  my_str_isupper.c\
	  my_strlcat.c\
	  my_strlen.c\
	  my_strlowcase.c\
	  my_strncat.c\
	  my_strncmp.c\
	  my_strncpy.c\
	  my_strstr.c\
	  my_strupcase.c\
	  my_strdup.c\
	  my_swap.c\
	  my_atoi.c

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@gcc -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@cp $(NAME) ../

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
