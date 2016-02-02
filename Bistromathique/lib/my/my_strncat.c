/*
** my_strncat.c for my_strncat in /home/david_h/rendu/Piscine_C_J07/ex_02
** 
** Made by David Sullivan
** Login   <david_h@epitech.net>
** 
** Started on  Tue Oct  7 13:29:46 2014 David Sullivan
** Last update Tue Oct  7 13:37:39 2014 David Sullivan
*/

int	my_strlenne(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      i = i + 1;
    }
  return (i);
}

char	*my_strncat(char *dest, char *src, int nb)
{
  int	i;
  int	j;

  i = 0;
  j = my_strlenne(dest);
  while (i < nb && src[i] != '\0')
    {
      dest[j] = src[i];
      j = j + 1;
      i = i + 1;
    }
  dest[j] = '\0';
  return (dest);
}
