/*
** my_strdup.c for my_strdup in /home/david_h/rendu/Piscine_C_J08/ex_01
** 
** Made by David Sullivan
** Login   <david_h@epitech.net>
** 
** Started on  Wed Oct  8 10:23:40 2014 David Sullivan
** Last update Thu Oct 30 15:10:37 2014 david_h
*/

#include <stdlib.h>
#include "../../include/my.h"

char	*my_strdup(char *src)
{
  char	*dest_len;

  dest_len = ((char *)malloc(sizeof(char) * my_strlen(src) + 1));
  if (dest_len == 0)
    return (0);
  dest_len = my_strcpy(dest_len, src);
  return (dest_len);
}
