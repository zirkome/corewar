/*
** ldi.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:28:10 2013 guillaume fillon
** Last update Mon Mar  4 15:54:14 2013 remi
*/

#include "lib.h"
#include "vm.h"

void	op_ldi(t_vm *vm, t_proc **lproc)
{
  printf("%sLDI%s\n", F_CYAN, REZ);
  (*lproc)->pc += interval_memory((*lproc)->cmd, (*lproc)->code, 0, 0);
  /* int	s; */

  /* s =  */
  /* lproc->param[3] =  */
  /* if (lproc->carry == 0) */
  /*   lproc->carry = 1; */
  /* else */
  /*   lproc->carry = 0; */
}
