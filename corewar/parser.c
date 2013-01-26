/*
** parseur.c for parseur in /home/remi/Projet/corewar/corewar
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sat Jan 26 10:54:25 2013 remi robert
** Last update Sat Jan 26 11:31:54 2013 remi robert
*/

#include "lib.h"
#include "vm.h"
#include "op.h"

void	parser_fct(t_vm *vm)
{
  int	interval;
  int	i;

  i = 0;
  printf("\nParsing instruction ...\n");
  while (i < MEM_SIZE)
    {
      if ((vm->mem[i] & 0xFF) - 1 <= 15 && (vm->mem[i] & 0xFF) - 1 >= 0)
	{
	  interval = op_tab[(vm->mem[i] & 0xFF) - 1].nbr_args + i;
	  printf("%s ", op_tab[(vm->mem[i] & 0xFF) - 1].mnemonique);
	  while (i < interval)
	    {
	      printf("%x ", vm->mem[i]);
	      i = i + 1;
	    }
	  printf(" | ");
	}
      i = i + 1;
    }
  printf("\nParsing instruction fini\n");
}
