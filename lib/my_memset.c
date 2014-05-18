#include "vm.h"

void	*my_memset(char *tab, int value, int size)
{
  int	indice;

  indice = 0;
  while (tab && indice < size)
    {
      tab[indice] = value;
      indice = indice + 1;
    }
  return (tab);
}
