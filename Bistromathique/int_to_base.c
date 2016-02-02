/*
** my_putnbr_base.c for my_putnbr_base in /home/carle_s/j06
** 
** Made by Carle Sacha
** Login   <carle_s@epitech.net>
** 
** Started on  Wed Oct  8 10:21:39 2014 Carle Sacha
** Last update Wed Nov  5 15:45:48 2014 david_h
*/

#include <stdlib.h>
#include "./include/my_parse.h"
#include "./include/my.h"

void	int_to_base(int nbr, char *base, int *i, char *ret)
{
  int	nc;

  nc = nbr % my_strlen(base);
  if (nbr / my_strlen(base) != 0)
    int_to_base(nbr / my_strlen(base), base, i, ret);
  ret[*i] = base[nc];
  *i = *i + 1;
}

char	*put_zero(char *nbr1, char *nbr2, char *base)
{
  char *ret;

  ret = my_strdup(nbr1);
  if (my_strlen(ret) < my_strlen(nbr2) || my_strlen(ret) % 2 == 1)
    {
      ret = my_inschar(ret, 0, base[0]);
    }
  if (my_strlen(ret) < my_strlen(nbr2))
    {
      ret = put_zero(ret, nbr2, base);
    }
  return (ret);
}

void	clean_kara(char **nbr1, char **nbr2, PARAM p)
{
  if (my_strlen(*nbr1) != 1 || my_strlen(*nbr2) != 1)
    {
      *nbr1 = put_zero(*nbr1, *nbr2, p->base);
      *nbr2 = put_zero(*nbr2, *nbr1, p->base);
    }
  if (my_strlen(*nbr1) != my_strlen(*nbr2))
    {
       clean_kara(nbr1, nbr2, p);
    }
}

void	div_kara(char *nbr, char **left, char **right)
{
  int	sep;

  sep = my_strlen(nbr) / 2;
  *left = my_strborn(nbr, 0, sep);
  *right = my_strborn(nbr, sep, my_strlen(nbr));
}
