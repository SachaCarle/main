/*
** my_atoi.c for my_getnbr in /home/david_h//Jour_04
** 
** Made by David Sullivan
** Login   <david_h@epitech.net>
** 
** Started on  Tue Oct  7 11:05:43 2014 David Sullivan
** Last update Sat Oct 25 19:30:45 2014 David Sullivan
*/

int	my_atoi(char *nbr)
{
  int	i;
  int	n;

  n = 0;
  i = 0;
  while (nbr[i] >= '0' && nbr[i] <= '9')
    {
      n = n * 10 + nbr[i] - 48;
      i = i + 1;
    }
  return (n);
}
