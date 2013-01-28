/*
** boucle.c for boucle in /home/remi/Projet/corewar/corewar
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Jan 28 13:10:36 2013 remi robert
** Last update Mon Jan 28 14:40:32 2013 remi robert
*/

#include "vm.h"
#include "lib.h"
#include "op.h"

void	run_cycle(t_vm *vm)
{
  int	cur_cycle;
  int	i;

  cur_cycle = 0;
  while (cur_cycle <= CYCLE_TO_DIE /*&& au moins un champion en vie*/)
    {
      i = 0;
      while (i <= CYCLE_TO_DIE - cur_cycle /*&& au moins un champion en vie*/)
	{
	  i = i + 1;
	}
      cur_cycle += CYCLE_DELTA;
    }
}
