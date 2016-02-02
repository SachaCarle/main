/*
** my_put_nbr.c for my_put_nbr in /home/david_h/rendu/Piscine_C_J04
** 
** Made by David Sullivan
** Login   <david_h@epitech.net>
** 
** Started on  Wed Oct  1 18:30:45 2014 David Sullivan
** Last update Tue Oct  7 11:40:23 2014 David Sullivan
*/
int	my_put_nbr(int nb)
{
  int	x;

  if (nb >= 0)
    {
      x = nb % 10;
      nb = (nb - x) / 10;
      if (nb != 0)
	my_put_nbr(nb);
      my_putchar(x + 48);
    }
  else
    {
      nb = nb * -1;
      x = nb % 10;
      nb = (nb - x) / -10;
      if (nb != 0)
	my_put_nbr(nb);
      if (nb == 0 )
	my_putchar('-');
      my_putchar(x + 48);
    }
}
