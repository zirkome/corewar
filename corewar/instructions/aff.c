/*
** aff.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:28:39 2013 guillaume fillon
** Last update Sun Mar 31 13:21:28 2013 guillaume fillon
*/

#include "lib.h"
#include "vm.h"
#include "couleur.h"

void		op_aff(t_vm *vm, t_proc **lproc)
{
  debug(vm, lproc, -1);
  if ((*lproc)->cmd[1] > 16)
    {
      (*lproc)->pc += 1;
      return ;
    }
  if ((*lproc)->cmd[1] - 1 < 0)
    (*lproc)->cmd[1] = REG_NUMBER - (*lproc)->cmd[1];
  my_putchar((*lproc)->reg[((int)(((*lproc)->cmd[1] - 1) & 0xFF))
			   % REG_NUMBER]);
  (*lproc)->pc += interval_memory((*lproc)->cmd, (*lproc)->code, 0, 0);
}
