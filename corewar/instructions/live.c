#include "lib.h"
#include "vm.h"

/*
** recherche dans la liste de proc, le numero de champion
** si trouve, ce champion a live et est donc en vie
*/
void		live_champion(t_vm *vm, int live)
{
  t_proc	*pcourant;

  if (vm->proc == NULL)
    return ;
  pcourant = vm->proc;
  while (pcourant != NULL)
    {
      if (pcourant->reg[0] == live + 1)
	{
	  my_putstr(VERT);
	  my_putstr("\nLe champion : ");
	  my_put_nbr(live + 1);
	  my_putstr(" est en vie");
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
  if (vm->option[0].debug != -1)
    print_debug(live, "live : ", 0);
  live_champion(vm, live - 1);
  (*lproc)->pc += 5;
}
