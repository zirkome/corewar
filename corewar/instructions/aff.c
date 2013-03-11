/*
** aff.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:28:39 2013 guillaume fillon
** Last update Mon Mar  4 15:54:48 2013 remi
*/

#include "lib.h"
#include "vm.h"
#include "couleur.h"

void		op_aff(t_vm *vm, t_proc **lproc)
{
  if ((*lproc)->cmd[1] > 16)
    {
      my_putstr("Bad argurment\n");
      (*lproc)->pc += 1;
      return ;
    }
  printf("%sAFF%s\n", F_CYAN, REZ);
  (*lproc)->pc += interval_memory((*lproc)->cmd, (*lproc)->code, 0, 0);
}
