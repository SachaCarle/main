/*
** my_str_isprintable.c for my_str_isprintable in /home/david_h/rendu/Piscine_C_J06/ex_14
** 
** Made by David Sullivan
** Login   <david_h@epitech.net>
** 
** Started on  Mon Oct  6 16:41:14 2014 David Sullivan
** Last update Mon Oct  6 16:51:05 2014 David Sullivan
*/

int	my_str_isprintable(char *str)
{
  int	i;

  i = 1;
  while (str[i])
    {
      if (str[i] >= 32 && str[i] <= 126)
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
