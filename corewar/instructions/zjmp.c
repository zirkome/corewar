/*
** zjmp.c for CoreWar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:21:16 2013 guillaume fillon
** Last update Mon Feb 25 08:39:40 2013 remi robert
*/

#include "lib.h"
#include "vm.h"

void		op_zjmp(t_vm *vm, t_proc **lproc)
{
  printf("%sZJUMP%s\n", F_CYAN, REZ);
  /* if (lproc->carry == 0) */
  /*   return ; */
  /* lproc->pc = (lproc->pc + (lproc->param[0] % IDX_MOD)) % MEM_SIZE; */
  (*lproc)->pc += interval_memory((*lproc)->cmd, 0, 0, 0);
}
