/*
** my_subb.c for bistro in /home/carle_s/depot/bistro/bistro2
** 
** Made by Carle Sacha
** Login   <carle_s@epitech.net>
** 
** Started on  Fri Oct 31 21:58:03 2014 Carle Sacha
** Last update Wed Nov  5 15:54:28 2014 david_h
*/

#include <stdlib.h>
#include "./include/struct.h"
#include "./include/my.h"
#include "./include/my_parse.h"
#include "./include/my_calc.h"

NBR	return_add(NBR n1, NBR n2, int sign, PARAM param)
{
  char	*val;
  val = my_add(n1->val, n2->val, param);
  return (newnbr(val, sign));
}

NBR	return_subb(NBR n1, NBR n2, int sign, PARAM param)
{
  char	*val;

  val = my_subb(n1->val, n2->val, param);
  return (newnbr(val, sign));
}

NBR	do_subb(NBR n1, NBR n2, PARAM param)
{
  NBR	temp;

  temp = newnbr(n2->val, n2->sign * -1);
  return (do_add(n1, temp, param));
}

char	*malloc_len(int *len, int len1, int len2)
{
  char	*ret;

  if (len1 > len2)
    {
      *len = len1;
    }
  else
    *len = len2;
  ret = malloc(sizeof(char) * (*len + 1));
  if (ret == NULL)
    {
      my_putstr("Could not malloc.\nexit.\n");
      exit(1);
    }
  return (ret);
}
