/*
** my_strncmp.c for my_strncmp in /home/david_h/rendu/Piscine_C_J06
** 
** Made by David Sullivan
** Login   <david_h@epitech.net>
** 
** Started on  Mon Oct  6 11:28:17 2014 David Sullivan
** Last update Mon Oct  6 11:55:59 2014 David Sullivan
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (s1[i] || s2[i] && i < n)
    {
      if (s1[i] < s2[i])
	{
	  return (-1);
	}
      if (s1[i] > s2[i])
	{
	  return (1);
	}
      i = i + 1;
    }
  if (s1[i] < s2[i])
    {
      return (-1);
    }
  if (s1[i] > s2[i])
    {
      return (1);
    }
  return ;
}
