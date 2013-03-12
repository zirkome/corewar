/*
** ld.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:29:11 2013 guillaume fillon
** Last update Tue Mar 12 21:23:05 2013 guillaume fillon
*/

#include "lib.h"
#include "vm.h"

void		op_ld(t_vm *vm, t_proc **lproc)
{
  printf("%sLD%s\n", F_CYAN, REZ);
  (*lproc)->reg[(int)(*lproc)->cmd[3]] =
    (*lproc)->reg[(int)(*lproc)->cmd[1]] + (*lproc)->reg[(int)(*lproc)->cmd[2]];
  printf("%d <- %d = [%d]\n", (*lproc)->reg[(int)(*lproc)->cmd[1]],
	 (*lproc)->reg[(int)(*lproc)->cmd[2]],
	 (*lproc)->reg[(int)(*lproc)->cmd[3]]);
  (*lproc)->pc += interval_memory((*lproc)->cmd, (*lproc)->code, 0, 0);
}
