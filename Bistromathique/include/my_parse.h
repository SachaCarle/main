/*
** my_parse.h for bistro in /home/carle_s/depot/bistro/bistro1/include
** 
** Made by Carle Sacha
** Login   <carle_s@epitech.net>
** 
** Started on  Thu Oct 30 14:12:38 2014 Carle Sacha
** Last update Tue Nov  4 21:05:00 2014 Carle Sacha
*/

#ifndef MY_PARSE_H_
#define MY_PARSE_H_

#include "./struct.h"

int	get_pos_right_val(char *expr, int i, PARAM param);
int	get_pos_left_val(char *expr, int i, PARAM param);
char	*format_par(char *expr, char *prio, int i, PARAM param);
char	*format_par_nbr(char *expr, PARAM param);
char	*my_instr(char *str, int i, char *ins);
char	*my_inschar(char *str, int i, char c);
char	*my_strborn(char *expr, int a, int b);
char	*clean_par(char *str, char left, char right);
int	pass_par_right(char *expr, int i, char left, char right);
int	pass_par_left(char *expr, int i, char left, char right);
ARBRE	str_to_tree(char *expr, PARAM param);
ARBRE	do_node(char *expr, PARAM param);
NBR	tree_to_nbr(ARBRE dad, PARAM param);
PARAM	parse_param(char *base, char *op);
void    int_to_base(int nbr, char *base, int *i, char *ret);
char	*put_zero(char *nbr1, char *nbr2, char *base);
void	div_kara(char *nbr, char **left, char **right);
char	*clean_zero(char *expr, char c);
void	clean_kara(char **nbr1, char **nbr2, PARAM p);
char	*mult_inschar(char *str, int i, char c, int nbr);
char	*format_sign(char *expr, PARAM p);
void	exit_malloc_failure(char *str);
char	*char_replace_str(char *str, int a, int b, char c);
char	*format_par_sign(char *expr, PARAM p);

#endif /* MY_PARSE_H_ */
