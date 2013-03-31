/*
** ld.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:29:11 2013 guillaume fillon
** Last update Thu Mar 28 17:40:32 2013 remi
*/

#include "lib.h"
#include "vm.h"

void	get_adress_ld(t_vm *vm, t_proc **lproc, int *adress)
{
  if ((((*lproc)->cmd[0] >> 6) & 0x03) == 1)
    *adress = (*lproc)->cmd[1];
  if ((((*lproc)->cmd[0] >> 6) & 0x03) == 2)
    {
      *adress = (((*lproc)->cmd[1] << 24) | ((*lproc)->cmd[2] << 16) |
		 ((*lproc)->cmd[3] << 8) | ((*lproc)->cmd[4])) & 0xFFFFFFFF;
    }
  if ((((*lproc)->cmd[0] >> 6) & 0x03) == 3)
    {
      *adress = (((*lproc)->cmd[1] << 8) | (*lproc)->cmd[1]) & 0xFFFF;
      if (*adress < 0)
	*adress = MEM_SIZE - *adress;
      if ((*lproc)->pc < 0)
	(*lproc)->pc = MEM_SIZE - (*lproc)->pc;
      *adress = vm->mem[(((*lproc)->pc + *adress) % IDX_MOD) % MEM_SIZE];
    }
}

void	set_ld(t_vm *vm, t_proc **lproc, int val)
{
  if ((((*lproc)->cmd[0] >> 6) & 0x03) == 1)
    {
      if (((*lproc)->cmd[2] - 1) < 0)
	((*lproc)->cmd[2]) = 1;
      (*lproc)->reg[((*lproc)->cmd[2] - 1) % REG_NUMBER] = val;
    }
  if ((((*lproc)->cmd[0] >> 6) & 0x03) == 3)
    {
      if (((*lproc)->cmd[3] - 1) < 0)
	((*lproc)->cmd[3]) = 1;
      (*lproc)->reg[((*lproc)->cmd[3] - 1) % REG_NUMBER] = val;
    }
  if ((((*lproc)->cmd[0] >> 6) & 0x03) == 2)
    {
      if (((*lproc)->cmd[5] - 1) < 0)
	((*lproc)->cmd[5]) = 1;
      (*lproc)->reg[((*lproc)->cmd[5] - 1) % REG_NUMBER] = val;
    }
}

void	op_ld(t_vm *vm, t_proc **lproc)
{
  int	val;

  val = 0;
  debug(vm, lproc);
  get_adress_ld(vm, lproc, &val);
  set_carry(lproc, val);
  set_ld(vm, lproc, val);
  (*lproc)->pc += interval_memory((*lproc)->cmd, (*lproc)->code, 0, 0);
}
