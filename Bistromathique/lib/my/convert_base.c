/*
** convert_base.c for convert_base in /home/david_h/rendu/Piscine_C_J08/ex_02
** 
** Made by David Sullivan
** Login   <david_h@epitech.net>
** 
** Started on  Wed Oct  8 14:06:25 2014 David Sullivan
** Last update Thu Oct 30 15:12:07 2014 david_h
*/

#include <stdlib.h>
#include "../../include/my.h"

char	*convert_base(char *nbr, char *base_from, char *base_to)
{
  char	*car;
  int	i;
  int	number;
  int	size;

  i = 0;
  car = malloc(sizeof(char) * 300);
  number = my_getnbr_base(nbr, base_from);
  while (number > 0)
    {
      size = my_strlen(base_to);
      car[i] = base_to[number % size];
      number = number / size;
      i = i + 1;
    }
  car[i] = '\0';
  car = my_revstr(car);
  return (car);
}
