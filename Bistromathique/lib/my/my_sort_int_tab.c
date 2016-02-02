/*
** my_sort_int_tab.c for my_sort_int_tab in /home/david_h/rendu/Piscine_C_J04
** 
** Made by David Sullivan
** Login   <david_h@epitech.net>
** 
** Started on  Fri Oct  3 08:32:04 2014 David Sullivan
** Last update Fri Oct  3 22:47:05 2014 David Sullivan
*/

void	my_sort_int_tab(int *tab, int size)
{
  int	i;
  int	c;
  int	j;

  i = 0;
  while (i < size)
    {
      j = i + 1;
      while (j < size)
	{
	  if (tab[i] > tab[j])
	    {
	      c = tab[i];
	      tab[i] = tab[j];
	      tab[j] = c;
	    }
	  j = j + 1;
	}
      i = i + 1;
    }
}
