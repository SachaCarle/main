/*
** my_strcmp.c for my_strcmp in /home/david_h/rendu/Piscine_C_J06
** 
** Made by David Sullivan
** Login   <david_h@epitech.net>
** 
** Started on  Mon Oct  6 10:17:50 2014 David Sullivan
** Last update Mon Oct  6 11:46:54 2014 David Sullivan
*/

int	my_strcmp(char *s1, char *s2)
{
  int	count_fs;

  count_fs = 0;
  while (s1[count_fs])
    {
      if (s1[count_fs] < s2[count_fs])
	{
	  return (-1);
	}
      if (s1[count_fs] > s2[count_fs])
	{
	  return (1);
	}
      count_fs = count_fs + 1;
    }
  if (s1[count_fs] < s2[count_fs])
    {
      return (-1);
    }
  if (s1[count_fs] > s2[count_fs])
    {
      return (1);
    }
  return ;
}
