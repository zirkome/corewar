/*
** lld.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:29:37 2013 guillaume fillon
** Last update Wed Mar 20 23:38:28 2013 remi
*/

#include "lib.h"
#include "vm.h"

void		op_lld(t_vm *vm, t_proc **lproc)
{
  int		indirect;
  short		direct;

  printf("[%d][%d]lld\n", (*lproc)->reg[0], (*lproc)->nb_proc);
  if ((((*lproc)->cmd[0] >> 6) & 0x03) == 1)
    {
      set_carry(lproc, (*lproc)->cmd[1]);
      if (((*lproc)->cmd[2] & 0xFF) > 0 && ((*lproc)->cmd[2] & 0xFF) < 16)
      	(*lproc)->reg[(int)((*lproc)->cmd[2] & 0xFF) % REG_NUMBER] =
	  (*lproc)->cmd[(int)((*lproc)->cmd[1] & 0xFF)];
    }
  if ((((*lproc)->cmd[0] >> 6) & 0x03) == 2)
    {
      indirect = (((*lproc)->cmd[1] & 0xFF) << 24) + (((*lproc)->cmd[2] & 0xFF) << 16)
	+ (((*lproc)->cmd[3] & 0xFF) << 8) + (((*lproc)->cmd[4] & 0xFF));
      indirect = (vm->mem[indirect % MEM_SIZE]) & 0xFF;
      printf("val [%d]\n", indirect);
      printf("%s{%d}%s\n", F_MAGENTA, (*lproc)->cmd[5], REZ);
      set_carry(lproc, indirect);
      if (((*lproc)->cmd[5] & 0xFF) > 0 && ((*lproc)->cmd[5] & 0xFF) < 16)
      	(*lproc)->reg[(int)((*lproc)->cmd[5] & 0xFF) % REG_NUMBER] = indirect;
    }
  if ((((*lproc)->cmd[0] >> 6) & 0x03) == 3)
    {
      direct = (((*lproc)->cmd[1] & 0xFF) << 8) + (((*lproc)->cmd[2] & 0xFF));
      printf("val [%d]\n", direct);
      printf("%s{%d}%s\n", F_MAGENTA, (*lproc)->cmd[3], REZ);
      set_carry(lproc, direct);
      if (((*lproc)->cmd[3] & 0xFF) > 0 && ((*lproc)->cmd[3] & 0xFF) < 16)
      	(*lproc)->reg[(int)(((*lproc)->cmd[3] % REG_NUMBER) & 0xFF)] = direct;
    }
  (*lproc)->pc += interval_memory((*lproc)->cmd, (*lproc)->code, 0, 0);
}
