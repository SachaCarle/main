/*
** my_square_root.c for my_square_root in /home/david_h/Desktop/lib/lab
** 
** Made by David Sullivan
** Login   <david_h@epitech.net>
** 
** Started on  Tue Oct  7 09:10:32 2014 David Sullivan
** Last update Tue Oct  7 15:30:04 2014 David Sullivan
*/

int	my_square_root(int nb)
{
  int	count;

  count = 0;
  if (nb == 1)
    return (1);
  while (count < (nb / 2))
    {
      if ((count * count) == nb)
      {
	return (1);
      }
      count = count + 1;
    }
  return (count);
}
