/*
** my_getnbr.c for my_getnbr in /home/david_h//Jour_04
** 
** Made by David Sullivan
** Login   <david_h@epitech.net>
** 
** Started on  Tue Oct  7 11:05:43 2014 David Sullivan
** Last update Sat Oct 25 19:30:45 2014 David Sullivan
*/

int	is_neg(char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i] > '9' || str[i] < '0')
    {
      if (str[i] == '-')
	j = j + 1;
      i = i + 1;
    }
  if (j % 2 == 0)
    return (1);
  else
    return (-1);
}

int	my_getnbr(char *str)
{
  int	i;
  int	n;

  n = 0;
  i = 0;
  while (str[i] < '0' || str[i] > '9')
    i = i + 1;
  while (str[i] >= '0' && str[i] <= '9')
    {
      n = n * 10 + str[i] - 48;
      i = i + 1;
    }
  return (n * is_neg(str));
}
