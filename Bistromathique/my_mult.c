/*
** my_mult.c for bistro in /home/carle_s/depot/bistro/bistro4
** 
** Made by Carle Sacha
** Login   <carle_s@epitech.net>
** 
** Started on  Sun Nov  2 15:58:05 2014 Carle Sacha
** Last update Wed Nov  5 15:56:38 2014 david_h
*/

#include <stdlib.h>
#include "./include/struct.h"
#include "./include/my.h"
#include "./include/my_parse.h"
#include "./include/my_calc.h"

char	*kara_base(char *val, PARAM p, int pos)
{
  char	*ret;
  int	i;

  i = 1;
  ret = my_inschar(val, my_strlen(val), p->base[0]);
  while (i < pos)
    {
      ret = my_inschar(ret, my_strlen(ret), p->base[0]);
      i = i + 1;
    }
  return (ret);
}

NBR	dsubb(NBR c1, NBR c2, PARAM p)
{
  char	*val;
  int	sign;
  char	*C1;
  char	*C2;

  C1 = my_strdup(c1->val);
  C2 = my_strdup(c2->val);
  clean_kara(&C1, &C2, p);
  sign = c1->sign * c2->sign;
  val = kara(C1, C2, p);
  return (newnbr(val, sign));
}

NBR	*malloc_struct()
{
  int	i;
  NBR	*tab;

  tab = malloc(sizeof(NBR) * 15);
  i = 0;
  while (i < 15)
    {
      tab[i] = malloc(sizeof(struct s_number));
      tab[i]->val = malloc(sizeof(char) * 20);
      tab[i]->sign = 1;
      i = i + 1;
    }
  return (tab);
}

char	*kara(char *nbr1, char *nbr2, PARAM p)
{
  NBR	*nbr;
  int	i;
  int	val;

  nbr = malloc_struct();
  clean_kara(&nbr1, &nbr2, p);
  if (my_strlen(nbr1) == 1 && my_strlen(nbr2) == 1)
    {
      i = 0;
      val = valbase(nbr1[0], p->base) * valbase(nbr2[0], p->base);
      int_to_base(val, p->base, &i, nbr[0]->val);
      nbr[0]->val[i] = '\0';
      return (nbr[0]->val);
    }
  div_kara(nbr1, &nbr[1]->val, &nbr[2]->val);
  div_kara(nbr2, &nbr[3]->val, &nbr[4]->val);
  nbr[5]->val = kara(nbr[1]->val, nbr[3]->val, p);
  nbr[6]->val = kara(nbr[2]->val, nbr[4]->val, p);
  nbr[7] = dsubb(do_subb(nbr[1], nbr[2], p), do_subb(nbr[3], nbr[4], p), p);
  nbr[8]->val = kara_base(nbr[5]->val, p, (my_strlen(nbr1) / 2) * 2);
  nbr[9] = do_add(nbr[5], do_subb(nbr[6], nbr[7], p), p);
  nbr[9]->val = kara_base(nbr[9]->val, p, my_strlen(nbr1) / 2);
  nbr[0] = do_add(nbr[8], do_add(nbr[9], nbr[6], p), p);
  nbr[0]->val = clean_zero(nbr[0]->val, p->base[0]);
  return (clean_zero(nbr[0]->val, p->base[0]));
}

NBR	do_mult(NBR nbr1, NBR nbr2, PARAM p)
{
  char	*val;
  int	sign;

  if (expr_sup(nbr1->val, p->zero, p) == 0 ||
      expr_sup(nbr2->val, p->zero, p) == 0)
    {
      return (newnbr(p->zero, 1));
    }
  nbr1->val = clean_zero(nbr1->val, p->base[0]);
  nbr2->val = clean_zero(nbr2->val, p->base[0]);
  clean_kara(&nbr1->val, &nbr2->val, p);
  sign = nbr1->sign * nbr2->sign;
  val = kara(nbr1->val, nbr2->val, p);
  return (newnbr(val, sign));
}
