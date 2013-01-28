/*
** aff.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:28:39 2013 guillaume fillon
** Last update Mon Jan 28 20:49:29 2013 guillaume fillon
*/

#include "lib.h"
#include "vm.h"

void		aff(t_vm *vm, t_proc *lproc)
{
  my_putchar(lproc->reg[lproc->param[1]]);
}
