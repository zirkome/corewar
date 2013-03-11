/*
** live.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:28:00 2013 guillaume fillon
** Last update Mon Mar 11 15:46:15 2013 remi
*/

#include "lib.h"
#include "vm.h"

void		op_live(t_vm *vm, t_proc **lproc)
{
  printf("%sLIVE%s\n", F_CYAN, REZ);
  /* if (lproc->param[0] > 0 && lproc->param[0] <= 4) */
  /*   vm->prg_alive[] */
  printf("%sLe champion : %d est en vie !%s\n", VERT, (*lproc)->reg[0], REZ);
  (*lproc)->live = 1;
  (*lproc)->pc += 5;
}
