/*
** xor.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:30:12 2013 guillaume fillon
** Last update Mon Mar 11 19:36:47 2013 guillaume fillon
*/

#include "lib.h"
#include "vm.h"

void		op_xor(t_vm *vm, t_proc **lproc)
{
  printf("%sXOR%s\n", F_CYAN, REZ);
  (*lproc)->reg[(int)(*lproc)->cmd[3]] =
    (*lproc)->reg[(int)(*lproc)->cmd[1]] ^ (*lproc)->reg[(int)(*lproc)->cmd[2]];
  printf("%d ^ %d = [%d]", (*lproc)->reg[(int)(*lproc)->cmd[1]],
	 (*lproc)->reg[(int)(*lproc)->cmd[2]],
	 (*lproc)->reg[(int)(*lproc)->cmd[3]]);
  (*lproc)->pc += interval_memory((*lproc)->cmd, (*lproc)->code, 0, 0);
}
