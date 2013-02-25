/*
** xor.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:30:12 2013 guillaume fillon
** Last update Mon Feb 25 08:40:00 2013 remi robert
*/

#include "lib.h"
#include "vm.h"

void		op_xor(t_vm *vm, t_proc **lproc)
{
  printf("%sXOR%s\n", F_CYAN, REZ);
  /* lproc->reg[(int)lproc->param[3]] = lproc->reg[(int)lproc->param[1]] */
  /*   ^ lproc->reg[(int)lproc->param[2]]; */
  /* if (lproc->carry == 0) */
  /*   lproc->carry = 1; */
  /* else */
  /*   lproc->carry = 0; */
  (*lproc)->pc += interval_memory((*lproc)->cmd, 0, 0, 0);
}
