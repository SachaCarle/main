/*
** my_add.c for bistro in /home/carle_s/depot/bistro/bistro2
** 
** Made by Carle Sacha
** Login   <carle_s@epitech.net>
** 
** Started on  Fri Oct 31 10:40:28 2014 Carle Sacha
** Last update Wed Nov  5 15:51:31 2014 david_h
*/

#include <stdlib.h>
#include "./include/struct.h"
#include "./include/my.h"
#include "./include/my_parse.h"
#include "./include/my_calc.h"

char	*clean_zero(char *expr, char c)
{
  int	i;
  char	*ret;

  i = 0;
  while (expr[i] == c && expr[i] != '\0')
    {
      i = i + 1;
    }
  if (expr[i - 1] == c && expr[i] == '\0')
    i = i - 1;
  else if (expr[i] == '\0')
    i = 0;
  ret = my_strborn(expr, i, my_strlen(expr));
  return (ret);
}

int	addval(char *nbr, int i, PARAM param)
{
  int	val;

  val = 0;
  if (i < 0)
    return (0);
  val = valbase(nbr[i], param->base);
  if (val == -1)
    return (0);
  return (val);
}

char	*my_add(char *nbr1, char *nbr2, PARAM p)
{
  int	leng1;
  int	leng2;
  int	len;
  char	*ret;
  int	mem;
  int	val;
  int	i;

  leng1 = my_strlen(nbr1);
  leng2 = my_strlen(nbr2);
  ret = malloc_len(&len, leng1, leng2);
  mem = 0;
  ret[len] = '\0';
  i = 1;
  while (leng1 - i >= 0 || leng2 - i >= 0 || mem > 0)
    {
      val = addval(nbr1, leng1 - i, p) + addval(nbr2, leng2 - i, p) + mem;
      mem = val >= p->base_leng;
      val = val - mem * p->base_leng;
      ret[len - i] = p->base[val];
      i = i + 1;
    }
  return (ret + len - i + 1);
}

char	*my_subb(char *nbr1, char *nbr2, PARAM p)
{
  int	leng1;
  int	leng2;
  int	len;
  char	*ret;
  int	mem;
  int	val;
  int	i;

  leng1 = my_strlen(nbr1);
  leng2 = my_strlen(nbr2);
  ret = malloc_len(&len, leng1, leng2);
  mem = 0;
  ret[len] = '\0';
  i = 1;
  while (leng1 - i >= 0 || leng2 - i >= 0 || mem > 0)
    {
      val = addval(nbr1, leng1 - i, p) - addval(nbr2, leng2 - i, p) - mem;
      mem = val < 0;
      val = val + mem * p->base_leng;
      ret[len - i] = p->base[val];
      i = i + 1;
    }
  ret = clean_zero(ret, p->base[0]);
  return (ret);
}

NBR	do_add(NBR n1, NBR n2, PARAM param)
{
  if (n1->sign == n2->sign)
    return (return_add(n1, n2, n1->sign, param));
  else
    {
      if (expr_sup(n1->val, n2->val, param) == 0)
	return (return_subb(n1, n2, 1, param));
      else if (expr_sup(n1->val, n2->val, param) == 1)
	{
	  if (n1->sign == 1)
	    return (return_subb(n1, n2, 1, param));
	  else if (n1->sign == -1)
	    return (return_subb(n1, n2, -1, param));
	}
      else
	{
	  if (n1->sign == 1)
	    return (return_subb(n2, n1, -1, param));
	  else if (n1->sign == -1)
	    return (return_subb(n2, n1, 1, param));
	}
    }
}
