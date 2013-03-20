/*
** ld.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:29:11 2013 guillaume fillon
** Last update Wed Mar 20 23:33:55 2013 remi
*/

#include "lib.h"
#include "vm.h"

void		op_ld(t_vm *vm, t_proc **lproc)
{
  int		indirect;
  int		direct;

  indirect = 0;
  direct = 0;
  printf("[%d][%d]ld ", (*lproc)->reg[0], (*lproc)->nb_proc);
  if (((((*lproc)->cmd[0] & 0xFF) >> 6) & 0x03) == 1)
    {
      set_carry(lproc, ((*lproc)->reg[(*lproc)->cmd[2] & 0xFF]) % 0xFF);
      (*lproc)->reg[((*lproc)->cmd[1] & 0xFF)] =
	((*lproc)->reg[(*lproc)->cmd[2] & 0xFF]) % IDX_MOD;
      printf("Val : %d\n", ((*lproc)->reg[(*lproc)->cmd[2] & 0xFF]) % 0xFF);
    }
  if (((((*lproc)->cmd[0] & 0xFF) >> 6) & 0x03) == 2)
    {
       indirect = (((*lproc)->cmd[1] & 0xFF) << 24) +
	(((*lproc)->cmd[2] & 0xFF) << 16) +
	(((*lproc)->cmd[3] & 0xFF) << 8) +
	(((*lproc)->cmd[4] & 0xFF));
      indirect = (vm->mem[((indirect % IDX_MOD) + (*lproc)->pc) % MEM_SIZE] << 24) +
	(vm->mem[(((indirect + 1) % IDX_MOD) + (*lproc)->pc) % MEM_SIZE] << 16) +
	(vm->mem[(((indirect + 2) % IDX_MOD) + (*lproc)->pc) % MEM_SIZE] << 8) +
	(vm->mem[(((indirect + 3) % IDX_MOD) + (*lproc)->pc) % MEM_SIZE]);
      (*lproc)->reg[((*lproc)->cmd[5] & 0xFF)] = indirect % IDX_MOD;
      printf("Val : %d\n", indirect % IDX_MOD);
      set_carry(lproc, indirect % IDX_MOD);
    }
  if (((((*lproc)->cmd[0] & 0xFF) >> 6) & 0x03) == 3)
    {
       direct = (((*lproc)->cmd[1] & 0xFF) << 8) + (((*lproc)->cmd[2] & 0xFF));
      (*lproc)->reg[((*lproc)->cmd[3] & 0xFF)] = direct % IDX_MOD;
      set_carry(lproc, direct % IDX_MOD);
      printf("Val : %d\n", direct % IDX_MOD);
    }
  (*lproc)->pc += interval_memory((*lproc)->cmd, (*lproc)->code, 0, 0);
}
