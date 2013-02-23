/*
** fork.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:28:20 2013 guillaume fillon
** Last update Sat Feb 23 12:28:32 2013 remi robert
*/

#include "lib.h"
#include "vm.h"

void		op_fork(t_vm *vm, t_proc *lproc)
{
  printf("%sFORK%s\n", F_CYAN, REZ);
  lproc->pc += interval_memory(lproc->cmd, 0, 0, 0);
}
