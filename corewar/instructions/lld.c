/*
** lld.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:29:37 2013 guillaume fillon
** Last update Mon Mar  4 15:53:57 2013 remi
*/

#include "lib.h"
#include "vm.h"

void		op_lld(t_vm *vm, t_proc **lproc)
{
  printf("%sLLD%s\n", F_CYAN, REZ);
  (*lproc)->pc += interval_memory((*lproc)->cmd, (*lproc)->code, 0, 0);
}
