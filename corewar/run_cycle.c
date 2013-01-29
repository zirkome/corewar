/*
** boucle.c for boucle in /home/remi/Projet/corewar/corewar
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Jan 28 13:10:36 2013 remi robert
** Last update Tue Jan 29 10:36:21 2013 guillaume fillon
*/

#include "lib.h"
#include "vm.h"
#include "instructions/instruction.h"

int	get_cmd(char code)
{
  int	i;

  i = 0;
  while (cmd_tab[i].code != 0x0)
    {
      if (cmd_tab[i].code == proc->instruction)
	return (i);
      i += 1;
    }
  return (-1);
}

int	exec_instruction(t_vm *vm, t_proc *proc)
{
  int	cmd_idx;

  if ((cmd_idx = get_cmd(proc->code)) >= 0)
    {
      proc
    }
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

void		run_cycle(t_vm *vm)
{
  int		flag;
  int		decrement;
  int		cur_cycle;

  flag = 1;
  cur_cycle = 0;
  decrement = 0;
  while (flag)
    {
      while (cur_cycle < CYCLE_TO_DIE + decrement)
	{
	  if (vm->nbr_live >= 40)
	    decrement -= CYCLE_DELTA;
	  cur_cycle += 1;
	}
      if (vm->pgr_nb == 1)
	{
	  flag = 0;
	  return;
	}
    }
}
