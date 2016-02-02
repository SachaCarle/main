/*
** op_eq.c for bistromatique in /home/carle_s/eval_expr
** 
** Made by Carle Sacha
** Login   <carle_s@epitech.net>
** 
** Started on  Tue Oct 28 17:33:55 2014 Carle Sacha
** Last update Mon Nov  3 23:24:53 2014 Carle Sacha
*/

#include <stdlib.h>
#include "./include/struct.h"
#include "./include/my.h"
#include "./include/my_parse.h"

typeNoeud	char_to_op(char operator, char *op)
{
  int		i;

  i = 0;
  while (op[i] != operator && op[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}

PARAM	parse_param(char *base, char *op)
{
  PARAM	param;

  param = malloc(sizeof(t_param));
  param->base = base;
  param->base_leng = my_strlen(base);
  param->left_sep = op[0];
  param->right_sep = op[1];
  param->op = my_strborn(op, 2, 7);
  param->prior = my_strborn(op, 4, 7);
  param->bad_prior = my_strborn(op, 2, 4);
  param->zero = malloc(sizeof(char) * 3);
  param->zero[0] = param->base[0];
  param->zero[1] = '\0';
  return (param);
}
