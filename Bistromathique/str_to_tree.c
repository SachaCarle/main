/*
** str_to_tree.c for bistromatique in /home/carle_s/eval_expr
** 
** Made by Carle Sacha
** Login   <carle_s@epitech.net>
** 
** Started on  Sun Oct 26 20:09:18 2014 Carle Sacha
** Last update Wed Nov  5 15:48:12 2014 david_h
*/

#include <stdlib.h>
#include "./include/struct.h"
#include "./include/my_parse.h"
#include "./include/my_calc.h"

void	put_arbre_res(ARBRE expr, PARAM p)
{
  NBR	n;

  printArbre(expr, p);
  my_putstr(" = ");
  n = tree_to_nbr(expr, p);
  if (n->sign == -1)
    my_putchar(p->op[1]);
  my_putstr(n->val);
  my_putstr("\n");
}

ARBRE	str_to_tree(char *expr, PARAM p)
{
  int	i;
  ARBRE	left;
  ARBRE	right;

  i = 0;
  while (expr[i] != '\0')
    {
      if (is_char_in(p->op, expr[i]) == 1)
	break;
      i = pass_par_right(expr, i, p->left_sep, p->right_sep);
    }
  if (expr[i] == '\0')
    {
      return (do_node(expr, p));
    }
  left = do_node(my_strborn(expr, get_pos_left_val(expr, i, p), i), p);
  right = do_node(my_strborn(expr, i + 1, get_pos_right_val(expr, i, p)), p);
  return (newOper(char_to_op(expr[i], p->op), left, right));
}

ARBRE	do_node(char *expr, PARAM param)
{
  NBR	nbr;
  ARBRE	ret;
  char	*str;

  if (my_strlen(expr) == 0)
    {
      nbr = newnbr(param->zero, 1);
      ret = newFeuille(nbr);
      return (ret);
    }
  else if (is_one_base(expr, param) == 1)
    {
      nbr = get_nbr_base(expr, param);
      ret = newFeuille(nbr);
      return (ret);
    }
  else
    {
      str = clean_par(expr, param->left_sep, param->right_sep);
      ret = str_to_tree(str, param);
      return (ret);
    }
}

NBR	tree_to_nbr(ARBRE node, PARAM param)
{
  NBR	left;
  NBR	right;

  if (node->type == VALEUR)
    return (node->info.nbr);
  else
    {
      left = tree_to_nbr(node->filsGauche, param);
      right = tree_to_nbr(node->filsDroit, param);
      if (node->type == ADD)
	return (do_add(left, right, param));
      else if (node->type == SUB)
	return (do_subb(left, right, param));
      else if (node->type == MULT)
	return (do_mult(left, right, param));
      else if (node->type == DIV)
	return (do_div(left, right, param));
      else
	return (do_mod(left, right, param));
    }
}
