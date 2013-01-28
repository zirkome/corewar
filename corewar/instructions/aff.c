/*
** aff.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:28:39 2013 guillaume fillon
** Last update Mon Jan 28 22:26:46 2013 remi robert
*/

#include "lib.h"
#include "vm.h"

void		op_aff(t_vm *vm, t_proc *lproc)
{
  my_putchar(lproc->reg[(int) lproc->param[1]]);
}
