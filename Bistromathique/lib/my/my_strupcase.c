/*
** my_strupcase.c for my_strupcase in /home/david_h/rendu/Piscine_C_J06
** 
** Made by David Sullivan
** Login   <david_h@epitech.net>
** 
** Started on  Mon Oct  6 12:51:00 2014 David Sullivan
** Last update Mon Oct  6 13:26:59 2014 David Sullivan
*/

char	*my_strupcase(char *str)
{
  int	count;

  count = 0;
  while (str[count])
    {
      if (str[count] >= 'a' && str[count] <= 'z')
	{
	  str[count] = str[count] - 32;
	}
      count = count + 1;
    }
}
