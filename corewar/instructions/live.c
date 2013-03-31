/*
** live.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:28:00 2013 guillaume fillon
** Last update Sun Mar 31 13:20:37 2013 guillaume fillon
*/

#include "lib.h"
#include "vm.h"

void		live_champion(t_vm *vm, int live)
{
  t_proc	*pcourant;

  if (vm->proc == NULL)
    return ;
  pcourant = vm->proc;
  while (pcourant != NULL)
    {
      if (pcourant->nb_proc == live)
	{
	  my_putstr(VERT);
	  my_putstr("Le champion : ");
	  my_put_nbr(live + 1);
	  my_putstr(" est en vie\n");
	  my_putstr(REZ);
	  vm->old_live = pcourant->nb_proc;
	  pcourant->live = 1;
	  return ;
	}
      pcourant = pcourant->next;
    }
}

void	op_live(t_vm *vm, t_proc **lproc)
{
  int	live;

  debug(vm, lproc, -1);
  vm->nb_live = vm->nb_live + 1;
  live = ((((*lproc)->cmd[0]) << 24) | (((*lproc)->cmd[1]) << 16) |
	  (((*lproc)->cmd[2]) << 8) | ((*lproc)->cmd[3])) & 0xFFFFFFFF;
  live_champion(vm, live - 1);
  (*lproc)->pc += 5;
}
