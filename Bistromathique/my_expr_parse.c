/*
** my_expr_parse.c for eval_expr in /home/carle_s/evalexp
** 
** Made by Carle Sacha
** Login   <carle_s@epitech.net>
** 
** Started on  Wed Oct 22 14:41:20 2014 Carle Sacha
** Last update Thu Oct 30 14:20:41 2014 Carle Sacha
*/

#include <stdlib.h>
#include "./include/my_parse.h"
#include "./include/my.h"

char	*my_strborn(char *expr, int a, int b)
{
  int	i;
  char	*str;

  str = malloc(sizeof(char) * (b - a + 2));
  if (str == NULL)
    return (0);
  i = 0;
  while (a + i != b && expr[a + i] != '\0')
    {
      str[i] = expr[a + i];
      i = i + 1;
    }
  str[i] = '\0';
  return (str);
}

char	*clean_par(char *str, char left, char right)
{
  char	*ret;

  ret = my_strdup(str);
  if (ret[0] != left)
    return (ret);
  else if (ret[my_strlen(ret) - 1] != right)
    return (ret);
  if (ret[pass_par_right(ret, 0, left, right)] != '\0')
    return (ret);
  ret = my_strborn(ret, 1, my_strlen(ret) - 1);
  return (ret);
}

int	pass_par_right(char *expr, int i, char left, char right)
{
  int	count;

  if (expr[i] != left)
    return (i + 1);
  count = 1;
  i = i + 1;
  while (count != 0)
    {
      if (expr[i] == left)
	count = count + 1;
      else if (expr[i] == right)
	count = count - 1;
      i = i + 1;
    }
  return (i);
}

int	pass_par_left(char *expr, int i, char left, char right)
{
  int	count;

  if (expr[i] != right)
    return (i - 1);
  i = i - 1;
  count = 1;
  while (count != 0)
    {
      if (expr[i] == right)
	count = count + 1;
      else if (expr[i] == left)
	count = count - 1;
      i = i - 1;
    }
  return (i + 1);
}
