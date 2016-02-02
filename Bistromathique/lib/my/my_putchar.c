/*
** my_putchar.c for my_putchar in /home/david_h/Desktop/lib
** 
** Made by David Sullivan
** Login   <david_h@epitech.net>
** 
** Started on  Tue Oct  7 08:55:23 2014 David Sullivan
** Last update Tue Oct  7 08:55:48 2014 David Sullivan
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}
