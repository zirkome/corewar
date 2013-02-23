/*
** aff.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:28:39 2013 guillaume fillon
** Last update Sat Feb 23 12:27:51 2013 remi robert
*/

#include "lib.h"
#include "vm.h"
#include "couleur.h"

void		op_aff(t_vm *vm, t_proc *lproc)
{
  printf("%sAFF%s\n", F_CYAN, REZ);
  if (lproc->cmd[1] > 16)
    {
      printf("Bad argurment\n");
      lproc->pc += 1;
      return ;
    }
  //u/  printf(" \nok => [%c]\n", (lproc->reg[(int) lproc->cmd[1]]));
  //  printf("%s%sPC = %d%s\n", INTENSITE, VERT, interval_memory(lproc->cmd, 0, 0, 0), REZ);
  lproc->pc += interval_memory(lproc->cmd, 0, 0, 0);
}
