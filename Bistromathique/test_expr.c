/*
** test_expr.c for bistro in /home/carle_s/depot/bistro/bistro4
** 
** Made by Carle Sacha
** Login   <carle_s@epitech.net>
** 
** Started on  Sun Nov  2 14:12:12 2014 Carle Sacha
** Last update Sun Nov  2 14:33:37 2014 Carle Sacha
*/

#include "./bistromathique.h"
#include "./include/struct.h"
#include "./include/my_parse.h"

int	count_par(char *expr, char left, char right)
{
  int	i;
  int	c;

  i = 0;
  c = 0;
  while (expr[i] != '\0')
    {
      if (expr[i] == left)
	c = c + 1;
      else if (expr[i] == right)
	c = c - 1;
      if (c < 0)
	return (c);
      i = i + 1;
    }
  return (c);
}

int	test_op(char *expr, PARAM p)
{
  int	i;

  i = 0;
  while (expr[i + 1] != '\0')
    {
      if (is_char_in(p->op, expr[i]) == 1 && (expr[i + 1] == p->right_sep
	 || is_char_in(p->prior, expr[i + 1]) == 1))
	return (1);
      if ((expr[i] == p->right_sep && expr[i + 1] == p->left_sep) ||
	       (expr[i] == p->left_sep &&
		(expr[i + 1] == p->right_sep ||
		 is_char_in(p->prior, expr[i + 1]) == 1)))
	return (1);
      if ((i == 0 || expr[i + 1] == p->right_sep)
	       && is_char_in(p->prior, expr[i]))
	return (1);
      i = i + 1;
    }
  if (is_char_in(p->op, expr[i]) == 1
      || (is_char_in(p->base, expr[0]) == 0 &&  my_strlen(expr) == 1))
    return (1);
  return (0);
}

int	test_valid_expr(char *expr, PARAM param)
{
  if (test_op(expr, param) != 0
      || count_par(expr, param->left_sep, param->right_sep) != 0)
    {
      my_putstr(SYNTAXE_ERROR_MSG);
      return (0);
    }
  return (1);
}
