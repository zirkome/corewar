/*
** my_putchar.c for my_putchar.c in /home/bridou_n//Jour_07
** 
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
** 
** Started on  Tue Oct  9 09:33:48 2012 nicolas bridoux
** Last update Tue Jan 22 14:35:12 2013 nicolas bridoux
*/

#include "asm.h"

void	my_putchar(char c)
{
  if ((write(1, &c, 1)) == -1)
    exit(EXIT_FAILURE);
}

void	my_putstr(char *str)
{
  if ((write(1, str, my_strlen(str))) == -1)
    exit(EXIT_FAILURE);
}

int	my_strlen(char *str)
{
  int	i;

  i = -1;
  while (str[++i]);
  return (i);
}

void	my_error(char *str, int quit)
{
  if ((write(2, str, my_strlen(str))) == -1)
    exit(EXIT_FAILURE);
  if (quit)
    exit(EXIT_FAILURE);
}

void	my_put_nbr(int nb)
{
  int	modulo;
  int	div;

  if (nb < 0 && nb > -10)
    my_putchar('-');
  modulo = nb % 10;
  div = nb / 10;
  if (nb >= 10 || nb <= -10)
    my_put_nbr(div);
  if (modulo < 0)
    modulo = - modulo;
  my_putchar(modulo + '0');
}
