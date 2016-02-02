/*
** my_calc.h for bistro in /home/carle_s/depot/bistro/bistro2
** 
** Made by Carle Sacha
** Login   <carle_s@epitech.net>
** 
** Started on  Fri Oct 31 21:54:54 2014 Carle Sacha
** Last update Wed Nov  5 15:49:14 2014 david_h
*/

#ifndef MY_CALC_H_
#define MY_CALC_H_

#include "./struct.h"

NBR	newnbr(char *val, int signe);
char	*my_add(char *nbr1, char *nbr2, PARAM param);
char	*my_subb(char *nbr1, char *nbr2, PARAM param);
NBR	return_add(NBR n1, NBR n2, int sign, PARAM param);
NBR	return_subb(NBR n1, NBR n2, int sign, PARAM param);
NBR	do_add(NBR n1, NBR n2, PARAM param);
NBR	do_subb(NBR n1, NBR n2, PARAM param);
NBR	get_nbr_base(char *expr, PARAM param);
char	*kara(char *nbr1, char *nbr2, PARAM p);
NBR	do_mult(NBR nbr1, NBR nbr2, PARAM p);
char	*kara_base(char *nbr1, PARAM p, int pos);
NBR	do_div(NBR nbr1, NBR nbr2, PARAM p);
NBR	do_mod(NBR nbr1, NBR nbr2, PARAM p);
char	*malloc_len(int *len, int len1, int len2);

#endif  /* MY_CALC_H_ */
