/*
** my_isneg.c for my_isneg in /home/david_h/rendu/Piscine_C_J03
** 
** Made by David Sullivan
** Login   <david_h@epitech.net>
** 
** Started on  Wed Oct  1 09:44:10 2014 David Sullivan
** Last update Wed Oct  1 09:55:18 2014 David Sullivan
*/

int	my_isneg(int n)
{
  char	pos;
  char	neg;

  pos = 'P';
  neg = 'N';
  if (n < 0)
    {
      my_putchar(neg);
    }
  else
    my_putchar(pos);
  return (0);
}
