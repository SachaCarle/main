/*
** my_putstr.c for my_put_str in /home/david_h/rendu/Piscine_C_J04
** 
** Made by David Sullivan
** Login   <david_h@epitech.net>
** 
** Started on  Thu Oct  2 09:10:23 2014 David Sullivan
** Last update Fri Oct  3 22:46:24 2014 David Sullivan
*/

int	my_putstr(char *str)
{
  int	i;
  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
  return (0);
}
