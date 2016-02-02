/*
** struct.h for eval_expr in /home/david_h/rendu/Piscine_C_eval_expr/include
** 
** Made by David Sullivan
** Login   <david_h@epitech.net>
** 
** Started on  Sun Oct 26 14:53:16 2014 David Sullivan
** Last update Mon Nov  3 23:21:48 2014 Carle Sacha
*/

#ifndef _STRUCT_H_
# define _STRUCT_H_

struct			s_number
{
  char			*val;
  int			sign;
};

typedef struct s_number *NBR;

typedef enum	{ADD, SUB, MULT, DIV, MOD, VALEUR} typeNoeud;

struct			model_noeud
{
  typeNoeud		type;
  struct model_noeud	*filsGauche;
  struct model_noeud	*filsDroit;
  union
  {
    NBR			nbr;
    char		*oper;
  } info;
};

typedef struct model_noeud NOEUD;
typedef NOEUD *ARBRE;

struct			s_param
{
  char			*base;
  int			base_leng;
  char			left_sep;
  char			right_sep;
  char			*op;
  char			*prior;
  char			*bad_prior;
  char			*zero;
};

typedef struct s_param t_param;
typedef t_param *PARAM;

ARBRE	newFeuille(NBR nbr);
ARBRE	newOper(typeNoeud type, ARBRE fg, ARBRE fd);

#endif /* _STRUCT_H */
