/*
** my_strncpy.c for my_strncpy in /home/david_h/rendu/Piscine_C_J06
** 
** Made by David Sullivan
** Login   <david_h@epitech.net>
** 
** Started on  Mon Oct  6 09:14:32 2014 David Sullivan
** Last update Mon Oct  6 17:52:20 2014 David Sullivan
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (src[i] && i < n)
    {
      dest[i] = src[i];
      i = i + 1;
    }
  if (src[n - 1])
    {
      dest[i] = '\0';
    }
  return (dest);
}
