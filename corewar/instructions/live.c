/*
** live.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:28:00 2013 guillaume fillon
** Last update Wed Mar 20 22:55:35 2013 remi
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
      if (pcourant->reg[0] == live)
	{
	  printf("%sLe champion : %d est en vie !%s\n", VERT, live, REZ);
	  pcourant->live = 1;
	}
      pcourant = pcourant->next;
    }
}

void		op_live(t_vm *vm, t_proc **lproc)
{
  int		live;

  vm->nb_live = vm->nb_live + 1;
  printf("%s[%d] LIVE%s\n", F_CYAN, (*lproc)->nb_proc,  REZ);
  live = (((*lproc)->cmd[0] & 0xFF) << 24) | (((*lproc)->cmd[1] & 0xFF) << 16) |
    (((*lproc)->cmd[2] & 0xFF) << 8) | ((*lproc)->cmd[3] & 0xFF);
  printf("champion live : %d\n", live);
   live_champion(vm, live);
  (*lproc)->pc += 5;
}
