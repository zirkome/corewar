/*
** lld.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:29:37 2013 guillaume fillon
** Last update Sat Mar 30 14:11:33 2013 remi
*/

#include "lib.h"
#include "vm.h"

/*
** recupére l adresse de lld en fonction du type de paraùtre
*/
void	get_adress_lld(t_vm *vm, t_proc **lproc, int *adress)
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
      *adress = vm->mem[(((*lproc)->pc + *adress)) % MEM_SIZE];
    }
}

void		op_lld(t_vm *vm, t_proc **lproc)
{
  int	val;

  val = 0;
  debug(vm, lproc);
  get_adress_lld(vm, lproc, &val);
  set_ld(vm, lproc, val);
  if (vm->option[0].debug != -1)
    print_debug(val, "value : ", 0);
  set_carry(lproc, val);
  (*lproc)->pc += interval_memory((*lproc)->cmd, (*lproc)->code, 0, 0);
}
