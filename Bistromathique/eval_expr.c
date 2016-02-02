/*
** eval_expr.c for eval_expr in /home/david_h/rendu/Piscine_C_eval_expr
** 
** Made by David Sullivan
** Login   <david_h@epitech.net>
** 
** Started on  Sun Oct 26 14:37:02 2014 David Sullivan
** Last update Tue Nov  4 03:23:28 2014 Carle Sacha
*/

#include <stdlib.h>
#include "./include/struct.h"
#include "./include/my_parse.h"
#include "./include/my_calc.h"
#include "./include/my.h"

char	*pre_format(char *expr, PARAM param)
{
  char	*ret;

  ret = my_strdup(expr);
  if (ret[my_strlen(ret) - 1] == '\n')
    {
      ret = my_strborn(ret, 0, my_strlen(ret) - 1);
    }
  ret = my_inschar(ret, my_strlen(ret), param->op[0]);
  ret = my_inschar(ret, my_strlen(ret), param->base[0]);
  ret = my_inschar(ret, 0, param->op[0]);
  ret = my_inschar(ret, 0, param->base[0]);
  return (ret);
}

char	*eval_expr(char *base, char *ops, char *expr, unsigned int size)
{
  ARBRE	dad;
  PARAM param;
  NBR	res;
  char	*str;
  if (test_bistro(base, ops, expr) == 0)
    return ("");
  param = parse_param(base, ops);
  if (test_valid_expr(expr, param) == 0)
    return ("");
  str = pre_format(expr, param);
  str = format_sign(str, param);
  str = format_par_sign(str, param);
  str = format_par(str, param->prior, 0, param);
  str = format_par(str, param->bad_prior, 0, param);
  str = format_par_nbr(str, param);
  dad = str_to_tree(str, param);
  res = tree_to_nbr(dad, param);
  if (res->sign == 1)
    {
      return (res->val);
    }
  str = my_inschar(res->val, 0, param->op[1]);
  return (str);
}
