/*
** my_instr.c for my_instr in /home/carle_s/projet/match
** 
** Made by Carle Sacha
** Login   <carle_s@epitech.net>
** 
** Started on  Fri Oct 10 10:44:59 2014 Carle Sacha
** Last update Tue Nov  4 21:19:37 2014 Carle Sacha
*/

#include <stdlib.h>
#include "./include/my.h"

char	*my_instr(char	*str, int i, char *ins)
{
  char	*ret;
  int	j, k;

  ret = malloc(sizeof(char) * (my_strlen(str) + my_strlen(ins) + 2));
  if (ret == NULL)
    return (0);
  j = 0, k = 0;
  while (j < i)
    {
      ret[j] = str[j];
      j = j + 1;
    }
  while (ins[k] != '\0')
    {
      ret[j] = ins[k];
      j = j + 1;
      k = k + 1;
    }
  while (str[j - k] != '\0')
    {
      ret[j] = str[j - k];
      j = j + 1;
    }
  ret[j] = '\0';
  return (ret);
}

char	*my_inschar(char *str, int i, char c)
{
  char *ret;
  int  j;

  ret = malloc(sizeof(char) * (my_strlen(str) + 3));
  if (ret == NULL)
    return (0);
  j = 0;
  while (j < i)
    {
      ret[j] = str[j];
      j = j + 1;
    }
  ret[j] = c;
  while (str[j] != '\0')
    {
      ret[j + 1] = str[j];
      j = j + 1;
    }
  ret[j + 1] = '\0';
  return (ret);
}

char	*mult_inschar(char *str, int i, char c, int nbr)
{
  char	*ret;

  ret = my_strdup(str);
  if (i < 0)
    i = my_strlen(str);
  while (nbr > 0)
    {
      ret = my_inschar(ret, i, c);
      nbr = nbr - 1;
    }
  return (ret);
}
