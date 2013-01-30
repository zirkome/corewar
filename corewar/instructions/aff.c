/*
** aff.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:28:39 2013 guillaume fillon
** Last update Wed Jan 30 09:06:06 2013 remi robert
*/

#include "lib.h"
#include "vm.h"

void		op_aff(t_vm *vm, t_proc *lproc)
{
  if (lproc->cmd[1] > 16)
    {
      printf("Bad argurment\n");
      lproc->pc += 1;
      return ;
    }
  printf(" \nok => [%c]\n", (lproc->reg[(int) lproc->cmd[1]]));
  lproc->pc += interval_memory(lproc->cmd, 0, 0, 0);
}
