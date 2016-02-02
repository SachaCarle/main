/*
** my_str_isupper.c for my_str_isupper in /home/david_h/rendu/Piscine_C_J06/ex_13
** 
** Made by David Sullivan
** Login   <david_h@epitech.net>
** 
** Started on  Mon Oct  6 16:35:25 2014 David Sullivan
** Last update Mon Oct  6 16:36:43 2014 David Sullivan
*/

int	my_str_isupper(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] >= 'A' && str[i] <= 'Z')
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
