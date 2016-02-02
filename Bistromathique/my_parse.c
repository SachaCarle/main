/*
** my_parse.c for parse in /home/carle_s/eval_expr
** 
** Made by Carle Sacha
** Login   <carle_s@epitech.net>
** 
** Started on  Sun Oct 26 17:15:59 2014 Carle Sacha
** Last update Wed Nov  5 15:53:33 2014 david_h
*/

#include <stdlib.h>
#include "./include/struct.h"
#include "./include/my_parse.h"
#include "./include/my.h"
#include "./include/my_calc.h"

int	get_pos_right_val(char *expr, int i, PARAM param)
{
  while (expr[i] != param->left_sep && is_base(expr[i], param) == 0)
    i = i + 1;
  if (expr[i] == param->left_sep)
    return (pass_par_right(expr, i, param->left_sep, param->right_sep) + 1);
  else if (is_base(expr[i], param))
    {
      while (is_base(expr[i], param))
	{
	  i = i + 1;
	}
    }
  return (i + 1);
}

int	get_pos_left_val(char *expr, int i, PARAM param)
{
  while (expr[i] != param->right_sep && is_base(expr[i], param) == 0)
    {
      i = i - 1;
    }
  if (expr[i] == param->right_sep)
    return (pass_par_left(expr, i, param->left_sep, param->right_sep));
  else if (is_base(expr[i], param))
    {
      while (is_base(expr[i], param) && i > 0)
	{
	  i = i - 1;
	}
    }
  return (i + (i != 0) + (i < 0) );
}

char	*format_par(char *expr, char *prio, int i, PARAM param)
{
  char	*ret;
  int   left;
  int	right;

  ret = my_strdup(expr);
  if (one_of_them_in(prio, expr) == 0)
    return (ret);
  while (is_char_in(prio, expr[i]) != 1 && expr[i] != '\0')
    {
      i = i + 1;
    }
  left = get_pos_left_val(expr, i, param);
  right = get_pos_right_val(expr, i, param);
  ret = my_inschar(expr, left, param->left_sep);
  ret = my_inschar(ret, right, param->right_sep);
  if (one_of_them_in(prio, &ret[i + 2]) == 1)
    return (format_par(ret, prio, i + 2, param));
  else
    return (ret);
}

char	*format_par_nbr(char *expr, PARAM param)
{
  char *ret;
  int	i;

  ret = my_strdup(expr);
  i = 0;
  while (ret[i] != '\0')
    {
      if (is_base(ret[i], param))
	{
	  ret = my_inschar(ret, i, param->left_sep);
	  i = i + 1;
	  while (is_base(ret[i], param))
	    {
	      i = i + 1;
	    }
	  ret = my_inschar(ret, i, param->right_sep);
	  i = i + 1;
	}
      i = i + 1;
    }
  return (ret);
}
