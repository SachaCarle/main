/*
** node_test.c for bistromatique in /home/carle_s/eval_expr
** 
** Made by Carle Sacha
** Login   <carle_s@epitech.net>
** 
** Started on  Mon Oct 27 14:36:17 2014 Carle Sacha
** Last update Wed Nov  5 15:56:23 2014 david_h
*/

#include "./include/my_calc.h"

int	is_one_nbr(char *expr)
{
  int	i;

  i = 0;
  while ((expr[i] > '9' || expr[i] < '0') && expr[i] != '\0')
    {
      i = i + 1;
    }
  if (expr[i] == '\0')
    return (0);
  while (expr[i] <= '9' && expr[i] >= '0' && expr[i] != '\0')
    {
      i = i + 1;
    }
  if (expr[i] == '\0')
    return (1);
  while ((expr[i] > '9' || expr[i] < '0') && expr[i] != '\0')
    {
      i = i + 1;
    }
  if (expr[i] != '\0')
    return (0);
  return (1);
}

int	is_one_base(char *expr, PARAM param)
{
  int	i;

  i = 0;
  while (is_base(expr[i], param) == 0 && expr[i] != '\0')
    i = i + 1;
  if (expr[i] == '\0')
    return (0);
  while (is_base(expr[i], param) && expr[i] != '\0')
    i = i + 1;
  if (expr[i] == '\0')
    return (1);
  while (is_base(expr[i], param) == 0 && expr[i] != '\0')
    i = i + 1;
  if (expr[i] != '\0')
    return (0);
  return (1);
}

int	find_first_oper(char *expr, char *op)
{
  int	i;

  i = 0;
  while (expr[i] != '\0')
    {
      if (is_char_in(op, expr[i]) == 1)
	return (i);
      i = pass_par_right(expr, i);
    }
  return (0);
}
