/*
** my_strcmp.c for strcmp in /home/linard_f//corewar/homework/vm
**
** Made by fabien linardon
** Login   <linard_f@epitech.net>
**
** Started on  Tue Mar 12 19:50:22 2013 fabien linardon
** Last update Thu Mar 21 10:28:38 2013 fabien linardon
*/

#include "fab.h"

int	my_strcmp(char *a, char *b)
{
  int	rk;

  if (strlen(a) != strlen(b))
    return (-1);
  rk = -1;
  while (a[++rk] && a[rk] == b[rk]);
  if (a[rk])
    return (-1);
  return (0);
}
