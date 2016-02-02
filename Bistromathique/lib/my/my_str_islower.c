/*
** my_str_islower.c for my_str_islower in /home/david_h/rendu/Piscine_C_J06/ex_12
** 
** Made by David Sullivan
** Login   <david_h@epitech.net>
** 
** Started on  Mon Oct  6 16:08:11 2014 David Sullivan
** Last update Tue Oct  7 15:31:37 2014 David Sullivan
*/

int	my_str_islower(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] >= 'a' && str[i] <= 'z')
	{
	  i = i + 1;
	}
      else
	{
	  return (0);
	}
      i = i + 1;
    }
  return (1);
}
