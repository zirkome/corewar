/*
** and.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:28:57 2013 guillaume fillon
** Last update Sun Mar 31 13:21:13 2013 guillaume fillon
*/

#include "lib.h"
#include "vm.h"

int	get_direct_param_op(t_proc **lproc, int *indice,
			    t_vm *vm, int decallage)
{
  int	ret;

  if (*indice < 0)
    *indice = 0;
  ret = (((int)(((((*lproc)->cmd[*indice + 1] & 0xFF) << 24)) |
		((((*lproc)->cmd[*indice + 2] & 0xFF) << 16)) |
		((((*lproc)->cmd[*indice + 3] & 0xFF) << 8)) |
		(((*lproc)->cmd[*indice + 4]))) % MEM_SIZE));
  *indice = *indice + 4;
  return (ret);
}

int	return_param_op(t_proc **lproc, int *indice,
			t_vm *vm, int decallage)
{
  int	ret;
  int	var;

  if (((((*lproc)->cmd[0] & 0xFF) >> decallage) & 0x03) == 1)
    {
      *indice = *indice + 1;
      return ((((*lproc)->cmd[*indice] & 0xFF) % IDX_MOD));
    }
  if (((((*lproc)->cmd[0] & 0xFF) >> decallage) & 0x03) == 3)
    {
      var = (((((((*lproc)->cmd[*indice + 1] & 0xFF) << 8)) |
	       (((*lproc)->cmd[*indice + 1] & 0xFF)) % IDX_MOD)));
      if (var < 0)
	var = MEM_SIZE - var;
      ret = (vm->mem[((*lproc)->pc + var) % MEM_SIZE]) & 0xFF;
      *indice = *indice + 2;
      return (ret % IDX_MOD);
    }
  if (((((*lproc)->cmd[0] & 0xFF) >> decallage) & 0x03) == 2)
    return (get_direct_param_op(lproc, indice, vm, decallage));
  return (0);
}

void	op_and(t_vm *vm, t_proc **lproc)
{
  int	param1;
  int	param2;
  int	indice;

  indice = 0;
  debug(vm, lproc, -1);
  param1 = return_param_op(lproc, &indice, vm, 6);
  param2 = return_param_op(lproc, &indice, vm, 4 );
  set_carry(lproc, (param1 & param2));
  (*lproc)->reg[(int)((*lproc)->cmd[indice + 1] - 1) %
		REG_NUMBER] = param1 & param2;
  (*lproc)->pc += interval_memory((*lproc)->cmd, (*lproc)->code, 0, 0);
}
