/*
** test_bistro.c for bistro in /home/carle_s/depot/bistro/bistro4
** 
** Made by Carle Sacha
** Login   <carle_s@epitech.net>
** 
** Started on  Sun Nov  2 14:12:12 2014 Carle Sacha
** Last update Sun Nov  2 14:33:37 2014 Carle Sacha
*/

#include "./bistromathique.h"

int	test_str_contain_only(char *str, char *a, char *b)
{
  int	i;

  i = 0;
  while (str[i] != '\0' && str[i] != '\n')
    {
      if (is_char_in(a, str[i]) == 0 && is_char_in(b, str[i]) == 0)
	{
	  return (0);
	}
      i = i + 1;
    }
  return (1);
}

int	test_same_char(char *a, char *b)
{
  int	i;
  int	j;

  i = 0;
  while (a[i] != '\0')
    {
      j = 0;
      while (b[j] != '\0')
	{
	  if (b[j] == a[i])
	    {
	      return (0);
	    }
	  j = j + 1;
	}
      i = i + 1;
    }
  return (1);
}

int	test_doublon(char *str)
{
  int	i;
  int	j;

  i = 0;
  while (str[i] != '\0')
    {
      j = 0;
      while (str[j] != '\0')
	{
	  if (j != i && str[j] == str[i])
	    {
	      return (0);
	    }
	  j = j + 1;
	}
      i = i + 1;
    }
  return (1);
}

int	test_bistro(char *base, char *op, char *expr)
{
  if (test_doublon(base) == 0)
    {
      my_putstr(SYNTAXE_ERROR_MSG);
      return (0);
    }
  if (test_doublon(op) == 0)
    {
      my_putstr(SYNTAXE_ERROR_MSG);
      return (0);
    }
  if (test_same_char(base, op) == 0)
    {
      my_putstr(SYNTAXE_ERROR_MSG);
      return (0);
    }
  if (test_str_contain_only(expr, base, op) == 0)
    {
      my_putstr(SYNTAXE_ERROR_MSG);
      return (0);
    }
  return (1);
}
