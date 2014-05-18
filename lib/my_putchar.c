#include "lib.h"

void	my_putchar(char c)
{
  if ((write(1, &c, 1)) == -1)
    write(2, &c, 1);
}

void	my_putstr(char *str)
{
  if ((write(1, str, my_strlen(str))) == -1)
    write(2, str, my_strlen(str));
}

int	my_strlen(char *str)
{
  int	i;

  i = -1;
  if (str == NULL)
    return (0);
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
    modulo = modulo * -1;
  my_putchar(modulo + '0');
}
