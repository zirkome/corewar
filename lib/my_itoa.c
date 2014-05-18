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
