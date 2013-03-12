/*
** ld.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:29:11 2013 guillaume fillon
** Last update Tue Mar 12 23:10:53 2013 guillaume fillon
*/

#include "lib.h"
#include "vm.h"

void		op_ld(t_vm *vm, t_proc **lproc)
{
  int		indirect;
  short		direct;

  printf("%sLD%s\n", F_CYAN, REZ);
  if ((((*lproc)->cmd[0] >> 6) & 0x03) == 1)
    {
      printf("REGISTRE\n");
      printf("%s{%d}%s\n", F_MAGENTA, (*lproc)->cmd[2], REZ);
      set_carry(lproc, (*lproc)->cmd[1]);
      if ((*lproc)->cmd[2] > 0 && (*lproc)->cmd[2] < 16)
      	(*lproc)->reg[(int)(*lproc)->cmd[2]] = (*lproc)->cmd[1];
    }
  if ((((*lproc)->cmd[0] >> 6) & 0x03) == 2)
    {
      printf("DIRECT\n");
      indirect = ((*lproc)->cmd[1] << 24) + ((*lproc)->cmd[2] << 16)
	+ ((*lproc)->cmd[3] << 8) + ((*lproc)->cmd[4]);
      indirect = vm->mem[indirect % MEM_SIZE];
      printf("val [%d]\n", indirect);
      printf("%s{%d}%s\n", F_MAGENTA, (*lproc)->cmd[5], REZ);
      set_carry(lproc, indirect);
      if ((*lproc)->cmd[5] > 0 && (*lproc)->cmd[5] < 16)
      	(*lproc)->reg[(int)(*lproc)->cmd[5]] = indirect;
    }
  if ((((*lproc)->cmd[0] >> 6) & 0x03) == 3)
    {
      printf("INDIRECT\n");
      direct = ((*lproc)->cmd[1] << 8) + ((*lproc)->cmd[2]);
      printf("val [%d]\n", direct);
      printf("%s{%d}%s\n", F_MAGENTA, (*lproc)->cmd[3], REZ);
      set_carry(lproc, direct);
      if ((*lproc)->cmd[3] > 0 && (*lproc)->cmd[3] < 16)
      	(*lproc)->reg[(int)(*lproc)->cmd[3]] = direct;
    }
  (*lproc)->pc += interval_memory((*lproc)->cmd, (*lproc)->code, 0, 0);
}
