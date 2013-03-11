/*
** add.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:28:50 2013 guillaume fillon
** Last update Mon Mar 11 15:24:15 2013 remi
*/

#include "lib.h"
#include "vm.h"

void		op_add(t_vm *vm, t_proc **lproc)
{
  printf("%sADD%s\n", F_CYAN, REZ);
  if ((*lproc)->cmd[1] > 16 || (*lproc)->cmd[2] > 16 || (*lproc)->cmd[3] > 16)
    {
      printf("Bad argurment\n");
      (*lproc)->pc += 1;
      return ;
    }
  (*lproc)->reg[(int)(*lproc)->cmd[3]] =
    (*lproc)->reg[(int)(*lproc)->cmd[1]] + (*lproc)->reg[(int)(*lproc)->cmd[2]];
  printf("%d + %d = [%d]", (*lproc)->reg[(int)(*lproc)->cmd[1]],
	 (*lproc)->reg[(int)(*lproc)->cmd[2]],
	 (*lproc)->reg[(int)(*lproc)->cmd[3]]);
  (*lproc)->pc += interval_memory((*lproc)->cmd, (*lproc)->code, 0, 0);
}
