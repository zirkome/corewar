/*
** ld.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:29:11 2013 guillaume fillon
** Last update Wed Mar 20 21:09:16 2013 remi
*/

#include "lib.h"
#include "vm.h"

void		op_ld(t_vm *vm, t_proc **lproc)
{
  int		indirect;
  short		direct;

  printf("%sLD%s\n", F_CYAN, REZ);
  printf("%d %d %d %d\n", (*lproc)->cmd[1] & 0xFF, (*lproc)->cmd[2] & 0xFF, (*lproc)->cmd[3] & 0xFF, (*lproc)->cmd[4] & 0xFF);
  if (((((*lproc)->cmd[0] & 0xFF) >> 6) & 0x03) == 1)
    {
      printf("REGISTRE\n");
      printf("%s{%d}%s\n", F_MAGENTA, (*lproc)->cmd[2], REZ);
      set_carry(lproc, ((*lproc)->cmd[1] & 0xFF));
      if (((*lproc)->cmd[2] & 0xFF) > 0 && ((*lproc)->cmd[2] < 16) & 0xFF)
      	(*lproc)->reg[(int)((*lproc)->cmd[2] & 0xFF) % REG_NUMBER] =
	  ((*lproc)->cmd[1] & 0xFF) % IDX_MOD;
    }
  if (((((*lproc)->cmd[0] & 0xFF) >> 6) & 0x03) == 2)
    {
      printf("DIRECT\n");
      indirect = (((*lproc)->cmd[1] & 0xFF) << 24) + (((*lproc)->cmd[2] & 0xFF) << 16)
	+ (((*lproc)->cmd[3] & 0xFF) << 8) + (((*lproc)->cmd[4] & 0xFF));
      indirect = vm->mem[((*lproc)->pc + (indirect % IDX_MOD)) % MEM_SIZE] & 0xFF;
      printf("val [%d]\n", indirect);
      printf("%s{%d}%s\n", F_MAGENTA, (*lproc)->cmd[5] & 0xFF, REZ);
      set_carry(lproc, indirect);
      if (((*lproc)->cmd[5] & 0xFF) > 0 && ((*lproc)->cmd[5] & 0xFF) < 16)
      	(*lproc)->reg[(int)((*lproc)->cmd[5] & 0xFF) % REG_NUMBER] =
	  indirect % IDX_MOD;
    }
  if (((((*lproc)->cmd[0] & 0xFF) >> 6) & 0x03) == 3)
    {
      printf("INDIRECT\n");
      direct = (((*lproc)->cmd[1] & 0xFF) << 8) + (((*lproc)->cmd[2] & 0xFF));
      printf("val [%d]\n", direct);
      printf("%s{%d}%s\n", F_MAGENTA, (*lproc)->cmd[3], REZ);
      set_carry(lproc, direct);
      if (((*lproc)->cmd[3] & 0xFF) > 0 && ((*lproc)->cmd[3] & 0xFF) < 16)
      	(*lproc)->reg[(int)((*lproc)->cmd[3] & 0xFF) % REG_NUMBER] =
	  direct % IDX_MOD;
    }
  (*lproc)->pc += interval_memory((*lproc)->cmd, (*lproc)->code, 0, 0);
}
