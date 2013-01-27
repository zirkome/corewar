/*
** parseur.c for parseur in /home/remi/Projet/corewar/corewar
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sat Jan 26 10:54:25 2013 remi robert
** Last update Sun Jan 27 21:11:42 2013 remi robert
*/

#include "lib.h"
#include "vm.h"
#include "op.h"

void	parser(t_vm *vm)
{
  int	i;
  int	interval;
  char	tab[4];
  char	size[3];
  int	indice;

  i = 0;
  size[0] = 1;
  size[1] = 4;
  size[2] = 2;
  while (i < MEM_SIZE)
    {
      if ((vm->mem[i] & 0xFF) != 0 && (vm->mem[i] & 0xFF) < 16)
	{
	  interval = 0;
	  printf("%d\n", i);
	  printf("{%s => %X} ", op_tab[(vm->mem[i] & 0xFF) - 1].mnemonique, (vm->mem[i] & 0xFF));
	  printf ("%d  =>> ", op_tab[(vm->mem[i] & 0xFF) - 1].nbr_args);
	  printf("octet de codage : %X ", (vm->mem[i + 1] & 0xFF));
	  printf(" [1 = %d]", ((vm->mem[i + 1]) >> 6) & 0x3);
	  printf(" [2 = %d]", ((vm->mem[i + 1]) >> 4) & 0x3);
	  printf(" [3 = %d]", ((vm->mem[i + 1]) >> 2) & 0x3);
	  printf(" [4 = %d]", ((vm->mem[i + 1]) & 0x3));
	  tab[0] = ((vm->mem[i + 1]) >> 6) & 0x3;
	  tab[1] = ((vm->mem[i + 1]) >> 4) & 0x3;
	  tab[2] = ((vm->mem[i + 1]) >> 2) & 0x3;
	  tab[3] = ((vm->mem[i + 1])) & 0x3;
	  indice = 0;
	  if (((vm->mem[i] & 0xFF) - 1) == 10)
	    size[1] = 2;
	  while (indice < 4)
	    {
	      if (tab[indice] != 0)
		interval = interval + size[(int)tab[indice] - 1];
	      indice = indice + 1;
	    }
	  if ((vm->mem[i] & 0xFF) == 0x01)
	    interval = 3;
	  size[1] = 4;
	  printf("interval {[%d]} ", interval);
	  printf ("%X \n", (vm->mem[i] & 0xFF));
	  i = i + interval + 1;
	}
      i = i + 1;
    }
  printf("\n");
}
