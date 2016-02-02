/*
** my_swap.c for my_swap in /home/david_h/rendu/Piscine_C_J04
** 
** Made by David Sullivan
** Login   <david_h@epitech.net>
** 
** Started on  Thu Oct  2 08:56:19 2014 David Sullivan
** Last update Fri Oct  3 22:47:48 2014 David Sullivan
*/

int	my_swap(int *a, int *b)
{
  int	copy;

  copy = *b;
  *b = *a;
  *a = copy;
  return (0);
}
