/*
** lldi.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:27:49 2013 guillaume fillon
** Last update Sun Mar 31 03:30:17 2013 guillaume fillon
*/

#include "lib.h"
#include "vm.h"

void		op_lldi(t_vm *vm, t_proc **lproc)
{
  int	param1;
  int	param2;
  int	indice;

  indice = 2;
  debug(vm, lproc);
  param1 = get_adress_ldi(vm, lproc, 6, &indice);
  param2 = get_adress_ldi(vm, lproc, 4, &indice);
  if (param1 < 0)
    param1 = MEM_SIZE - param1;
  param1 = vm->mem[((*lproc)->pc + (param1 % IDX_MOD)) % MEM_SIZE];
  param1 = param1 + param2;
  set_carry(lproc, param1);
  if (((*lproc)->cmd[indice + 1] - 1) % REG_NUMBER < 0)
    (*lproc)->cmd[indice + 1] = 1;
  if (param1 < 0)
    param1 = MEM_SIZE - param1;
  (*lproc)->reg[((*lproc)->cmd[indice + 1] - 1) %
		REG_NUMBER] = vm->mem[(((*lproc)->pc + param1) %
				       IDX_MOD) % MEM_SIZE];
  (*lproc)->pc += interval_memory((*lproc)->cmd, (*lproc)->code, 0, 0);
}
