/*
** boucle.c for boucle in /home/remi/Projet/corewar/corewar
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Jan 28 13:10:36 2013 remi robert
** Last update Mon Jan 28 14:17:41 2013 remi robert
*/

#include "vm.h"
#include "lib.h"
#include "op.h"

void	loop(t_vm *vm)
{
  int	cycle_to_die;
  int	i;

  cycle_to_die = CYCLE_TO_DIE;
  while (cycle_to_die > 0 /*&& au moins un champion en vie*/)
    {
      i = 0;
      while (i <= cycle_to_die /*&& au moins un champion en vie*/)
	{
	  i = i + 1;
	}
      cycle_to_die = cycle_to_die - CYCLE_DELTA;
    }
}
