/*
** my_itoa.c for RTv1 in /home/fillon_g/projets/rtv1/src
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Sun Mar 17 16:07:35 2013 guillaume fillon
** Last update Sat Mar 30 21:23:01 2013 guillaume fillon
*/

#include "lib.h"

char		*my_itoa(int i, char b[])
{
  int		shifter = i;
  char const	digit[] = "0123456789";
  char		*p;

  p = b;
  if (i < 0)
    {
      *p++ = '-';
      i = -1;
    }
  shifter = i;
  while (shifter)
    {
      ++p;
      shifter = shifter / 10;
    }
  *p = '\0';
  while (i)
    {
      *--p = digit[i % 10];
      i = i / 10;
    }
  return (b);
}
