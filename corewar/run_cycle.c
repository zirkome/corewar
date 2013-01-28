/*
** boucle.c for boucle in /home/remi/Projet/corewar/corewar
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Jan 28 13:10:36 2013 remi robert
** Last update Mon Jan 28 21:23:17 2013 remi robert
*/

#include "vm.h"
#include "lib.h"
#include "op.h"

int	check_ch_live(t_vm *vm)
{
  int	live;
  int	i;

  live = 0;
  i = 0;
  while (i < 4)
    {
      if (vm->is_ch_alive[i] == 1)
	live = 1;
      i = i + 1;
    }
  return (live);
}

void		first_value_proc(t_vm *vm)
{
  t_proc	*cur_proc;

  if (vm->proc == NULL)
    return ;
  cur_proc = vm->proc->next;
  while (cur_proc != vm->proc)
    {
      parser(vm, cur_proc);
      cur_proc = cur_proc->next;
    }
}

void		run_cycle(t_vm *vm)
{
  t_proc	*cur_proc;
  int		cur_cycle;
  int		i;
  int		indice;

  first_value_proc(vm);
  cur_proc = vm->proc->next;
  cur_cycle = 0;
#ifdef DEBUG
  while (cur_proc != vm->proc)
    {
      printf("\n[%d] =>>  %d\n", cur_proc->pc, cur_proc->instruction);
      indice = 0;
      while (indice < 16)
	{
	  printf("%X ", cur_proc->param[indice]);
	  indice = indice + 1;
	}
      printf("\n");
      cur_proc = cur_proc->next;
    }
#endif
  while (cur_cycle <= CYCLE_TO_DIE && check_ch_live(vm) == 1)
    {
      i = 0;
      while (i <= CYCLE_TO_DIE - cur_cycle && check_ch_live(vm) == 1)
	{
	  i = i + 1;
	}
      cur_cycle += CYCLE_DELTA;
    }
  printf("\n");
}
