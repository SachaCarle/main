/*
** my_showstr.c for my_showstr.c in /home/david_h/rendu/Piscine_C_J06
** 
** Made by David Sullivan
** Login   <david_h@epitech.net>
** 
** Started on  Tue Oct  6 09:58:00 2014 David Sullivan
** Last update Tue Oct  7 15:51:52 2014 David Sullivan
*/

int	my_showstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
       if (str[i] <= 31 || str[i] >= 128)
      	{
        my_putchar('\\');
	if (str[i] <= 15)
	  {
	    my_putchar('0');
	  }
        my_putchar(my_putnbr_base(str[i], "0123456789abcdef"));
      	}
       else
      	{
	  my_putchar(str[i]);
	}
      i = i + 1;
    }
  return (0);
}
