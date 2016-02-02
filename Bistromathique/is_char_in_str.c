/*
** test_colle1.c for colle3 in /home/carle_s/colle
** 
** Made by Carle Sacha
** Login   <carle_s@epitech.net>
** 
** Started on  Fri Oct 24 21:50:44 2014 Carle Sacha
** Last update Wed Oct 29 18:48:43 2014 Carle Sacha
*/

int	is_char_in(char *str, char c)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
  {
    if (str[i] == c)
      {
	return (1);
      }
    i = i + 1;
  }
  return (0);
}

int	one_of_them_in(char *tab, char *str)
{
  int	i;

  i = 0;
  while (tab[i] != 0)
    {
      if (is_char_in(str, tab[i]) == 1)
	return (1);
      i = i + 1;
    }
  return (0);
}
