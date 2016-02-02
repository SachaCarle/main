/*
** base_parse.c for bistro in /home/carle_s/depot/bistro/bistro4
** 
** Made by Carle Sacha
** Login   <carle_s@epitech.net>
** 
** Started on  Sat Nov  1 09:44:25 2014 Carle Sacha
** Last update Tue Nov  4 20:51:03 2014 Carle Sacha
*/

#include <stdlib.h>
#include "./include/struct.h"
#include "./include/my_parse.h"
#include "./include/my_calc.h"

int	is_base(char c, PARAM param)
{
  int	i;

  i = 0;
  while (param->base[i] != '\0')
    {
      if (c == param->base[i])
	return (1);
      i = i + 1;
    }
  return (0);
}

NBR	get_nbr_base(char *expr, PARAM param)
{
  int	i;
  int	j;
  int	sign;
  char	*val;

  i = 0;
  j = 0;
  sign = 0;
  while (is_base(expr[i], param) == 0)
    {
      if (expr[i] == param->op[1])
	sign = sign + 1;
      i = i + 1;
    }
  while (is_base(expr[i + j], param) && expr[i + j] != '\0')
    {
      j = j + 1;
    }
  val = my_strborn(expr, i, i + j);
  if (sign % 2 == 0)
    sign = 1;
  else if (sign % 2 == 1)
    sign = -1;
  return (newnbr(val, sign));
}

