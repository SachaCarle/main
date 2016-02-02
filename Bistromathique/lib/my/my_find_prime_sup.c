/*
** my_find_prime_sup.c for my_find_prime_sup in /home/david_h/Desktop/lib/lab
** 
** Made by David Sullivan
** Login   <david_h@epitech.net>
** 
** Started on  Tue Oct  7 09:43:32 2014 David Sullivan
** Last update Tue Oct  7 15:29:34 2014 David Sullivan
*/

int	my_find_prime_sup(int nb)
{
  int	nb_superieur;

  if (nb == 1)
    {
      return (nb);
    }
  while ((nb_superieur = my_find_prime_sup(nb)) == 0)
  {
    nb = nb + 1;
  }
return (nb);
}
