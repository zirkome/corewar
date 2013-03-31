/*
** or.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:29:51 2013 guillaume fillon
** Last update Sun Mar 31 14:28:13 2013 remi
*/

#include "lib.h"
#include "vm.h"

void		op_or(t_vm *vm, t_proc **lproc)
{
  int	param1;
  int	param2;
  int	indice;

  indice = 0;
  debug(vm, lproc);
  param1 = return_param_op(lproc, &indice, vm, 6);
  param2 = return_param_op(lproc, &indice, vm, 4);
  if (indice < 0)
    indice = 1;
  if ((*lproc)->cmd[indice + 1 % 16] - 1 < 0)
    (*lproc)->cmd[indice + 1 % 16] = 1;
  if (vm->option[0].debug != -1)
    print_debug((param1 | param2), "result : ", 0);
  set_carry(lproc, (param1 | param2));
  (*lproc)->pc += interval_memory((*lproc)->cmd, (*lproc)->code, 0, 0);
}
