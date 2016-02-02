/*
** base.c for bistro in /home/carle_s/depot/bistro/bistro2
** 
** Made by Carle Sacha
** Login   <carle_s@epitech.net>
** 
** Started on  Fri Oct 31 10:45:07 2014 Carle Sacha
** Last update Fri Oct 31 21:48:10 2014 Carle Sacha
*/

#include <stdlib.h>
#include "./include/struct.h"

int	valbase(char c, char *base)
{
  int	i;

  i = 0;
  while (base[i] != '\0')
    {
      if (base[i] == c)
	{
	  return (i);
	}
      i = i + 1;
    }
  return (-1);
}

int	expr_sup(char *nbr1, char *nbr2, PARAM param)
{
  int	i;
  int	test;

  i = 0;
  if (my_strlen(nbr1) > my_strlen(nbr2))
    return (1);
  else if (my_strlen(nbr1) < my_strlen(nbr2))
    return (-1);
  while (nbr1[i] != '\0' && nbr2[i] != '\0')
    {
      test = valbase(nbr1[i], param->base) > valbase(nbr2[i], param->base);
      if (test == 1)
	return (1);
      else if (nbr1[i] != nbr2[i])
	return (-1);
      i = i + 1;
    }
  if (nbr1[i] == '\0' && nbr2[i] == '\0')
    return (0);
  else if (nbr1[i] == '\0')
    return (-1);
  else
    return (1);
}

NBR	newnbr(char *val, int signe)
{
  NBR	nbr;

  nbr = malloc(sizeof(struct s_number));
  nbr->val = val;
  nbr->sign = signe;
  return (nbr);
}

void	my_putbase_nbr(NBR nbr)
{
  if (nbr->sign == -1)
    my_putchar('-');
  my_putstr(nbr->val);
}
