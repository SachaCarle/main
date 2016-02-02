/*
** my_strcat.c for my_strcat in /home/david_h/rendu/Piscine_C_J07/ex_01
** 
** Made by David Sullivan
** Login   <david_h@epitech.net>
** 
** Started on  Tue Oct  7 13:10:34 2014 David Sullivan
** Last update Tue Oct  7 13:27:58 2014 David Sullivan
*/

int	my_strlenn(char *str)
{
  int	i;
  i = 0;
  while (str[i])
    {
      i = i + 1;
    }
  return (i);
}

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  i = 0;
  j = my_strlenn(dest);
  while (src[i])
    {
      dest[j] = src[i];
      j = j + 1;
      i = i + 1;
    }
  dest[j] = '\0';
  return (dest);
}
