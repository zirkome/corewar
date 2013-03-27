/*
** boucle.c for boucle in /home/remi/Projet/corewar/corewar
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Jan 28 13:10:36 2013 remi robert
** Last update Wed Mar 27 21:52:51 2013 remi
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

  if (((*proc)->wait != 0 && (*proc)->wait != -1) || (vm->prg_alive[(*proc)->nb_proc % 4] == 0))
    return (0);
  cmd_idx = 0;
  cmd_idx = get_cmd((*proc)->code);
  if (cmd_idx >= 0 && cmd_idx <= REG_NUMBER)
    {
      (cmd_tab[cmd_idx].f)(vm, proc);
      return (0);
    }
  else
    return (0);
  return (-1);
}

void		reset_live_prg(t_vm **vm)
{
  t_proc	*cur_proc;

  if ((*vm)->proc == NULL)
    return ;
  cur_proc = (*vm)->proc;
  while (cur_proc != NULL)
    {
      cur_proc->live = 0;
      cur_proc = cur_proc->next;
    }
}

int		handle_schedule(t_vm **vm)
{
  t_proc	*cur_proc;

  if ((*vm)->proc == NULL)
    return (0);
  cur_proc = (*vm)->proc;
  while (cur_proc != NULL)
    {
      if (cur_proc->wait == -1)
      	{
      	  parser(*vm, cur_proc, 0);
	  cur_proc->wait = wait_proc(cur_proc->code - 1);
      	}
      cur_proc->wait -= 1;
      if (cur_proc->wait <= 0)
      	{
	  exec_instruction(*vm, &cur_proc);
      	  parser(*vm, cur_proc, 1);
	  cur_proc->wait = wait_proc(cur_proc->code - 1);
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
  reset_live_prg(&vm);
  vm->nb_live = 0;
  while (turn && cycle > 0)
    {
      turn = handle_schedule(&vm);
      if (n == cycle || vm->nb_live == NBR_LIVE)
	{
	  if (vm->nb_live == 40)
	    printf("%s              40 LIVE                                     %d => [%d]%s\n", F_VERT, n, cycle, REZ);
	  else
	    printf("%s                                                          %d => [%d]%s\n", F_VERT, n, cycle, REZ);
	  if ((check_prg_live(&vm)) == 0)
	    {
	      printf("fin programme\n");
	      return ;
	    }
	  n = 0;
	  vm->nb_live = 0;
	  reset_live_prg(&vm);
	  cycle = cycle - CYCLE_DELTA;
	  if (cycle <= 0)
	    return ;
	}
           /* vm->cycle += 1; */
      n = n + 1;
    }
}
