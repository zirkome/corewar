/*
** ld.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:29:11 2013 guillaume fillon
** Last update Mon Mar  4 15:54:20 2013 remi
*/

#include "lib.h"
#include "vm.h"

void		op_ld(t_vm *vm, t_proc **lproc)
{
  printf("%sLD%s\n", F_CYAN, REZ);
  (*lproc)->pc += interval_memory((*lproc)->cmd, (*lproc)->code, 0, 0);
  /* lproc->reg[(int)lproc->param[2]] = */
  /*   (int)vm->mem[lproc->pc + (lproc->param[1] % IDX_MOD)]; */
  /* if (lproc->carry == 0) */
  /*   lproc->carry = 1; */
  /* else */
  /*   lproc->carry = 0; */
}
