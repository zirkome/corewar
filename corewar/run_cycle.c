/*
** boucle.c for boucle in /home/remi/Projet/corewar/corewar
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Jan 28 13:10:36 2013 remi robert
** Last update Sat Feb 23 12:50:11 2013 remi robert
*/

#include "lib.h"
#include "vm.h"
#include "couleur.h"
#include "instructions/instruction.h"

int	get_cmd(char code)
{
  int	i;

  i = 0;
  while (cmd_tab[i].code != 0x0)
    {
      if (cmd_tab[i].code == code)
	return (i);
      i += 1;
    }
  return (-1);
}

int	exec_instruction(t_vm *vm, t_proc **proc)
{
  int	cmd_idx;

  if (vm->prg_alive[(*proc)->reg[0] - 1] == 0 || (*proc)->wait-- > 0)
    return (0);
  if ((cmd_idx = get_cmd((*proc)->code)) >= 0)
    {
      (cmd_tab[cmd_idx].f)(vm, *proc);
      return (0);
    }
  else
    return (0);
  return (-1);
}

int	check_prg_live(t_vm *vm)
{
  int	live;
  int	i;

  live = 0;
  i = 0;
  while (i < 4)
    {
      if (vm->prg_alive[i] == 1)
	live += 1;
      i = i + 1;
    }
  return (live);
}

int		handle_schedule(t_vm *vm)
{
  t_proc	*cur_proc;

  cur_proc = vm->proc->next;
  if (cur_proc == NULL)
    return (0);
  if (check_prg_live(vm) == 1)
    return (0);
  while (cur_proc != vm->proc)
    {
      if (cur_proc->wait == -1)
      	{
      	  parser(vm, cur_proc);
      	  cur_proc->wait = cmd_tab[cur_proc->code - 1].cycle + 1;
      	}
      cur_proc->wait -= 1;
      if (cur_proc->wait == 0)
      	{
	  exec_instruction(vm, &cur_proc);
      	  parser(vm, cur_proc);
      	  cur_proc->wait = cmd_tab[cur_proc->code - 1].cycle;
      	}
      cur_proc = cur_proc->next;
    }
  return (1);
}

void		sync_cycle(t_vm *vm)
{
  int		turn;
  int		n;
  int		cycle;

  n = 0;
  turn = 1;
  cycle = CYCLE_TO_DIE;
  vm->proc->next->reg[3] = 42;
  while (turn)
    {
      turn = handle_schedule(vm);
      if (n == cycle /*|| test NBR_LIVE */)
	{
	  n = 0;
	  cycle -= CYCLE_DELTA;
	}
      vm->cycle += 1;
      n += 1;
      /* test instruction */
      if (n == 70)
	exit (0);
      /* A enlever bien evidemment*/
    }
}
