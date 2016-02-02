/*
** my_strstr.c for my_strstr in /home/david_h/rendu/Piscine_C_J06
** 
** Made by David Sullivan
** Login   <david_h@epitech.net>
** 
** Started on  Mon Oct  6 09:46:05 2014 David Sullivan
** Last update Mon Oct  6 10:13:11 2014 David Sullivan
*/

char	*my_strstr(char *str, char *to_find)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (str[i])
    {
      if (str[i] == to_find[count])
	{
	  count = count + 1;
	}
      else
	{
	  count = 0;
	}
      if (!to_find[count])
	{
	  i = i - (count - 1);
	  return (str + i);
	}
      i = i + 1;
    }
  return (0);
}

