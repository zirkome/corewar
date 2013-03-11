/*
** zjmp.c for CoreWar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:21:16 2013 guillaume fillon
** Last update Mon Mar  4 18:26:26 2013 remi
*/

#include "lib.h"
#include "vm.h"

void		op_zjmp(t_vm *vm, t_proc **lproc)
{
  printf("%sZJUMP%s\n", F_CYAN, REZ);
  /* if (lproc->carry == 0) */
  /*   return ; */
  /* lproc->pc = (lproc->pc + (lproc->param[0] % IDX_MOD)) % MEM_SIZE; */
  // (*lproc)->pc += interval_memory((*lproc)->cmd, (*lproc)->code, 0, 0);
  (*lproc)->pc += 3;
}
