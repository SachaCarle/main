/*
** my_revstr.c for my_revstr in /home/david_h/rendu/Piscine_C_J06
** 
** Made by David Sullivan
** Login   <david_h@epitech.net>
** 
** Started on  Mon Oct  6 09:25:11 2014 David Sullivan
** Last update Tue Oct  7 15:30:25 2014 David Sullivan
*/

int	my_strlenght(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}

char	*my_revstr(char *str)
{
  char	temp;
  int	forward;
  int	backward;

  forward = 0;
  backward = my_strlenght(str) - 1;
  while (forward < backward)
    {
      temp = str[forward];
      str[forward] = str[backward];
      str[backward] = temp;
      forward = forward + 1;
      backward = backward -1;
    }
  return (str);
}
