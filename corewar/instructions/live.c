/*
** live.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:28:00 2013 guillaume fillon
** Last update Mon Feb 25 08:47:11 2013 remi robert
*/

#include "lib.h"
#include "vm.h"

void		op_live(t_vm *vm, t_proc **lproc)
{
  printf("%sLIVE%s\n", F_CYAN, REZ);
  /* if (lproc->param[0] > 0 && lproc->param[0] <= 4) */
  /*   vm->prg_alive[] */
  (*lproc)->pc += 5;
}
