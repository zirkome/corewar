/*
** my_getnbr.c for my_getnbr.c in /home/bridou_n//Lib/fichiers.c
**
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
**
** Started on  Thu Oct 25 11:39:51 2012 nicolas bridoux
** Last update Fri Mar 29 17:19:40 2013 remi
*/

#include "lib.h"

int	my_getnbr(char *str)
{
  int	sign;
  int	result;

  sign = 1;
  result = 0;
  while (*str == '-' || *str == '+')
    {
      if (*str == '-')
	sign = - sign;
      str = str + 1;
    }
  while (*str != '\0' && *str >= '0' && *str <= '9')
    {
      if (result > 214748364)
	return (0);
      if (result == 214748364 && *str > 7 && sign == 1)
	return (0);
      if (result == 214748364 && *str > 8 && sign == -1)
	return (0);
      result = result * 10 + *str - 48;
      str = str + 1;
    }
  if (sign == -1)
    result = - result;
  return (result);
}
