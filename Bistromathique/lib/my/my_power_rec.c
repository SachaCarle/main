/*
** my_power_rec.c for my_power_rec in /home/david_h/rendu/Piscine_C_J05
** 
** Made by David Sullivan
** Login   <david_h@epitech.net>
** 
** Started on  Fri Oct  3 10:14:40 2014 David Sullivan
** Last update Fri Oct  3 12:59:35 2014 David Sullivan
*/

int	my_power_rec(int nb, int power)
{
  int	answer;

  answer = 1;
  if (power > 0)
    {
      answer = nb * my_power_rec(nb, power -1);
    }
  return (answer);
}
