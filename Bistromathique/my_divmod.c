/*
** my_div.c for bistro in /home/carle_s/depot/bistro/bistro4
** 
** Made by Carle Sacha
** Login   <carle_s@epitech.net>
** 
** Started on  Sun Nov  2 15:58:05 2014 Carle Sacha
** Last update Wed Nov  5 15:52:54 2014 david_h
*/

#include <stdlib.h>
#include "./include/struct.h"
#include "./include/my.h"
#include "./include/my_parse.h"
#include "./include/my_calc.h"

char	*simple_div(char *nbr1, char *nbr2, PARAM p, char **rest)
{
  int	div;
  int	i;
  char *ret;

  *rest = my_strdup(nbr1);
  ret = malloc(sizeof(nbr1));
  div = 0;
  while (expr_sup(*rest, nbr2, p) != -1)
    {
      *rest = my_subb(*rest, nbr2, p);
      div = div + 1;
    }
  i = 0;
  int_to_base(div, p->base, &i, ret);
  return (ret);
}

int	get_best_mult(char *nbr1, char *nbr2, PARAM p)
{
  if (valbase(nbr1[0], p) > valbase(nbr2[0], p))
    return (my_strlen(nbr1) - my_strlen(nbr2) - 1);
  if (my_strlen(nbr1) - 1 == my_strlen(nbr2))
    return (0);
  return (my_strlen(nbr1) - my_strlen(nbr2) - 2);
}

char	*my_div(char *nbr1, char *nbr2, PARAM p, char **rest)
{
  char	*mult;
  char	*res;

  if (my_strlen(nbr1) < 3 && my_strlen(nbr2) < 3)
    return (simple_div(nbr1, nbr2, p, rest));
  *rest = my_inschar("", 0, p->base[0]);
  if (expr_sup(nbr1, nbr2, p) == 0)
    return (my_inschar("", 0, p->base[1]));
  *rest = my_strdup(nbr1);
  if (expr_sup(nbr1, nbr2, p) == -1)
    return (my_inschar("", 0, p->base[0]));
  mult = mult_inschar(nbr2, -1, p->base[0], get_best_mult(nbr1, nbr2, p));
  res = simple_div(nbr1, mult, p, rest);
  res = mult_inschar(res, -1, p->base[0], get_best_mult(nbr1, nbr2, p));
  return (my_add(res, my_div(my_strdup(*rest), nbr2, p, rest), p));
}

NBR	do_div(NBR nbr1, NBR nbr2, PARAM p)
{
  char	*val;
  int	sign;
  char	*rest;

  if (expr_sup(nbr2->val, p->zero, p) == 0)
    {
      my_putstr("ERROR : Division by zero.\n");
      exit(1);
    }
  sign = nbr1->sign * nbr2->sign;
  val = my_div(nbr1->val, nbr2->val, p, &rest);
  return (newnbr(val, sign));
}

NBR	do_mod(NBR nbr1, NBR nbr2, PARAM p)
{
  char	*val;
  int	sign;

  if (expr_sup(nbr2->val, p->zero, p) == 0)
    {
      my_putstr("ERROR : Modulo by zero.\n");
      exit(1);
    }
  sign = nbr1->sign * nbr2->sign;
  my_div(nbr1->val, nbr2->val, p, &val);
  return (newnbr(val, sign));
}
