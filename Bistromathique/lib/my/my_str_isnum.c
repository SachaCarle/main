/*
** my_str_isnum.c for my_str_isnum in /home/david_h/rendu/Piscine_C_J06/ex_11
** 
** Made by David Sullivan
** Login   <david_h@epitech.net>
** 
** Started on  Mon Oct  6 16:03:11 2014 David Sullivan
** Last update Mon Oct  6 16:05:30 2014 David Sullivan
*/

int	my_str_isnum(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] >= '0' && str[i] <= '9')
	{
	  i = i + 1;
	}
      else
	{
	  return (0);
	}
    }
  return (1);
}
