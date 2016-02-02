/*
** my_strlcat.c for my_strlcat in /home/david_h/rendu/Piscine_C_J07/ex_03
** 
** Made by David Sullivan
** Login   <david_h@epitech.net>
** 
** Started on  Tue Oct  7 13:58:39 2014 David Sullivan
** Last update Sat Oct 25 19:30:29 2014 David Sullivan
*/

int	my_strleen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      i = i + 1;
    }
  return (i);
}

int	my_strlcat(char *dest, char *src, int size)
{
  int	size_buf;
  int	i;

  size_buf = my_strleen(dest);
  i = 0;
  if (!(size_buf) && (size < size_buf))
    {
      return (size + my_strleen(src));
    }
  while ((i + size_buf < size) && (src[i] != '\0'))
    {
      dest[i + size_buf] = src[i];
      i = i + 1;
    }
  if ((i + size_buf < size))
    {
      dest[i + size_buf] = '\0';
    }
  else
    {
      dest[i + size_buf -1] = '\0';
    }
  return (size_buf + my_strleen(src));
}
