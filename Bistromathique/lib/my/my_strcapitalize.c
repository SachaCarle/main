/*
** my_strcapitalize.c for my_strcapitalize in /home/david_h/rendu/Piscine_C_J06
** 
** Made by David Sullivan
** Login   <david_h@epitech.net>
** 
** Started on  Mon Oct  6 13:42:18 2014 David Sullivan
** Last update Mon Oct  6 15:43:33 2014 David Sullivan
*/

char	*my_strlowcaser(char *str)
{
  int	count;

  count = 0;
  while (str[count])
    {
      if (str[count] <= 90 && str[count] >= 65)
	{
	  str[count] = str[count] + 32;
	}
      count = count + 1;
    }
}

char	*my_strcapitalize(char *str)
{
  int	i;

  i = 1;
  my_strlowcaser(str);
  if (str[0] >= 'a' && str[0] <= 'z')
    {
      str[0] = str[0] - 32;
    }
  while (str[i] != 0)
    {
      if (str[i] <= 'a' && str[i] <= 'z' && str[i - 1] < '0'
	  && str[i] > '9' && i != 0)
	{
	  str[i] = str[i] - 32;
	}
      i = i + 1;
    }
  return (str);
}
