/*
** my_strlen.c for my_strlen in /home/david_h/rendu/Piscine_C_J04
** 
** Made by David Sullivan
** Login   <david_h@epitech.net>
** 
** Started on  Thu Oct  2 09:17:17 2014 David Sullivan
** Last update Thu Oct  2 09:41:56 2014 David Sullivan
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}
