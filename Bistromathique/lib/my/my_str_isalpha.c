/*
** my_str_isalpha.c for my_str_isalpha in /home/david_h/rendu/Piscine_C_J06/ex_10
** 
** Made by David Sullivan
** Login   <david_h@epitech.net>
** 
** Started on  Mon Oct  6 15:56:49 2014 David Sullivan
** Last update Mon Oct  6 16:02:06 2014 David Sullivan
*/

int	my_str_isalplha(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
	{
	  i = i + 1;
	}
      else
	{
	  return (0);
	}
      return (1);
    }
}
