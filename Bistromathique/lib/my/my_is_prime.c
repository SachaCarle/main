/*
** my_isprime.c for my_isprime in /home/david_h/Desktop/lib/lab
** 
** Made by David Sullivan
** Login   <david_h@epitech.net>
** 
** Started on  Tue Oct  7 09:27:56 2014 David Sullivan
** Last update Tue Oct  7 09:40:28 2014 David Sullivan
*/

int	my_is_prime(int nb)
{
  int	count;

  count = 0;
  if (nb == 0 || nb == 1)
    return (0);
  count = count + 2;
  while (count < nb)
    {
      if (nb % count == 0)
	{
	  return (0);
	}
      count = count + 1;
    }
  return (1);
}
