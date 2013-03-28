/*
** or.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:29:51 2013 guillaume fillon
** Last update Thu Mar 28 17:40:14 2013 remi
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
  set_carry(lproc, (param1 | param2));
  if (indice < 0)
    indice = 1;
  if ((*lproc)->cmd[indice + 1] - 1 < 0)
    (*lproc)->cmd[indice + 1] = 1;
  (*lproc)->reg[(int)((*lproc)->cmd[indice + 1] - 1) %
		REG_NUMBER] = param1 | param2;
  (*lproc)->pc += interval_memory((*lproc)->cmd, (*lproc)->code, 0, 0);
}
