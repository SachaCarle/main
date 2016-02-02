/*
** my_strlowcase.c for my_strlowcase in /home/david_h/rendu/Piscine_C_J06
** 
** Made by David Sullivan
** Login   <david_h@epitech.net>
** 
** Started on  Mon Oct  6 13:12:30 2014 David Sullivan
** Last update Mon Oct  6 13:29:39 2014 David Sullivan
*/

char	*my_strlowcase(char *str)
{
  int	count;

  count = 0;
  while (str[count])
    {
      if (str[count] >= 'A' && str[count] <= 'Z')
	{
	  str[count] = str[count] + 32;
	}
      count = count + 1;
    }
}
