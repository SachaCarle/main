/*
** main.c for emb in /home/scarle/shared/python/emb
** 
** Made by Sacha Carle
** Login   <scarle@epitech.net>
** 
** Started on  Tue Feb  9 13:39:48 2016 Sacha Carle
// Last update Tue Feb  9 14:47:40 2016 Sacha Carle
*/

#include "Python.h"

wchar_t * wtoc(char * str) {
  int size = strlen(str);
  wchar_t * ret;
  if ((ret = (wchar_t *)malloc(sizeof(wchar_t) * (size + 1))) == NULL)
    return (NULL);
  swprintf(ret, size, L"%hs", str);
  return ret;
}

int main(int ac, char **av)
{
  Py_SetProgramName(wtoc(av[0]));
  Py_Initialize();
  FILE * file = fopen(av[1], "r");
  PyRun_SimpleFile(file, av[1]);
  Py_Finalize();
  return 0;
}
