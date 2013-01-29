/*
** aff.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:28:39 2013 guillaume fillon
** Last update Tue Jan 29 16:18:15 2013 remi robert
*/

#include "lib.h"
#include "vm.h"

void		op_aff(t_vm *vm, t_proc *lproc)
{
  printf("\nOK\n");
  printf(" \nok => [%c]\n", (lproc->reg[(int) lproc->cmd[1]]));
  //lproc->pc += 2;
  exit(0);
}
