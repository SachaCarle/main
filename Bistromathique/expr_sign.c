/*
** expr_sign.c for bistromathique in /home/carle_s/
** 
** Made by Carle Sacha
** Login   <carle_s@epitech.net>
** 
** Started on  Tue Oct 28 17:33:55 2014 Carle Sacha
** Last update Mon Nov  3 23:24:53 2014 Carle Sacha
*/

#include <stdlib.h>
#include "./include/struct.h"
#include "./include/my_parse.h"
#include "./include/my.h"

void	exit_malloc_failure(char *str)
{
  if (str == NULL)
    {
      my_putstr("Could not malloc.\n");
      exit(1);
    }
}

char	*char_replace_str(char *str, int a, int b, char c)
{
  char	*ret;
  int	i;
  int	j;

  ret = malloc(sizeof(char) * (my_strlen(str) - (b - a) + 1));
  exit_malloc_failure(ret);
  i = 0;
  j = 0;
  while (i < a && str[i] != '\0')
    {
      ret[i] = str[i];
      i = i + 1;
    }
  while (j < b - a && str[i + j] != '\0')
    j = j + 1;
  ret[i] = c;
  i = i + 1;
  while (str[i + j] != '\0')
    {
      ret[i] = str[i + j];
      i = i + 1;
    }
  ret[i] = '\0';
  return (ret);
}

char	*format_sign(char *expr, PARAM p)
{
  int	i;
  char	*ret;

  i = 0;
  ret = my_strdup(expr);
  while (ret[i] != '\0' && ret[i + 1] != '\0')
    {
      if (is_char_in(p->bad_prior, ret[i]) == 1
	  && is_char_in(p->bad_prior, ret[i + 1]) == 1)
	{
	  if (ret[i] == ret[i + 1])
	    {
	      ret = char_replace_str(ret, i, i + 1, p->bad_prior[0]);
	      i = 0;
	    }
	  else
	    {
	      ret = char_replace_str(ret, i, i + 1, p->bad_prior[1]);
	      i = 0;
	    }
	}
      i = i + 1;
    }
  return (ret);
}

char	*format_par_sign(char *expr, PARAM p)
{
  char	*ret;
  int	i;
  int	right;

  i = 0;
  ret = my_strdup(expr);
  if (ret[my_strlen(ret) - 1] == '\n')
    ret = my_strborn(ret, 0, my_strlen(ret) - 2);
  while (expr[i] != '\0' && expr[i + 1] != '\0')
    {
      if (is_char_in(p->prior, ret[i]) == 1
	  && is_char_in(p->bad_prior, ret[i + 1]) == 1)
	{
	  right = get_pos_right_val(expr, i + 1, p);
	  ret = my_inschar(ret, i + 1, p->left_sep);
	  ret = my_inschar(ret, right, p->right_sep);
	  i = 0;
	}
      i = i + 1;
    }
  return (ret);
}
