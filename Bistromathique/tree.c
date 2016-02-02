/*
** tree.c for eval_expr in /home/david_h/rendu/Piscine_C_eval_expr
** 
** Made by David Sullivan
** Login   <david_h@epitech.net>
** 
** Started on  Sun Oct 26 15:28:44 2014 David Sullivan
** Last update Wed Nov  5 15:40:45 2014 david_h
*/

#include <stdlib.h>
#include "./include/struct.h"
#include "./include/my_calc.h"

ARBRE   newFeuille(NBR nbr)
{
  ARBRE temp;

  temp = (ARBRE)malloc(sizeof(NOEUD));
  temp->info.nbr = nbr;
  temp->type = VALEUR;
  temp->filsGauche = NULL;
  temp->filsDroit = NULL;
  return (temp);
}

ARBRE   newOper(typeNoeud type, ARBRE fg, ARBRE fd)
{
  ARBRE temp;
  char  *oper;

  temp = (ARBRE)malloc(sizeof(NOEUD));
  oper = (char *)malloc(2 * sizeof(char));
  temp->type = type;
  temp->filsGauche = fg;
  temp->filsDroit = fd;
  return (temp);
}

int     printArbre(ARBRE arbre, PARAM param)
{
  if ((arbre->type == ADD) || (arbre->type == SUB))
    my_putstr("(");
      if (arbre->type ==  VALEUR)
	{
	  if (arbre->info.nbr->sign < 0)
	    my_putchar(param->op[1]);
	  my_putstr(arbre->info.nbr->val);
	}
      else
	{
	  printArbre(arbre->filsGauche, param);
	  my_putchar(param->op[arbre->type]);
	  printArbre(arbre->filsDroit, param);
	}
  if ((arbre->type == ADD) || (arbre->type == SUB))
    my_putstr(")");
}
