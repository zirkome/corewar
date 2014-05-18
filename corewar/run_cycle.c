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

  if (((*proc)->wait != 0 && (*proc)->wait != -1) ||
      (vm->prg_alive[(*proc)->nb_proc % 4] == 0))
    return (0);
  cmd_idx = 0;
  cmd_idx = get_cmd((*proc)->code);
  if (cmd_idx >= 0 && cmd_idx <= REG_NUMBER)
    {
      (cmd_tab[cmd_idx].f)(vm, proc);
      if (vm->option[0].debug != -1)
	my_putstr("\n");
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
	  (*vm)->cycle_champion[cur_proc->nb_proc % 4] += cur_proc->wait;
      	}
      cur_proc->wait -= 1;
      if (cur_proc->wait <= 0)
      	{
	  exec_instruction(*vm, &cur_proc);
      	  parser(*vm, cur_proc, 1);
	  cur_proc->wait = wait_proc(cur_proc->code - 1);
	  (*vm)->cycle_champion[cur_proc->nb_proc % 4] += cur_proc->wait;
      	}
      cur_proc = cur_proc->next;
    }
  return (1);
}

void		sync_cycle(t_vm *vm)
{
  SDL_Event	event;
  int		n;

  n = 0;
  reset_live_prg(&vm);
  init_cmd_proc(vm);
  display_sidebar(vm->sdl->screen);
  display_champions(vm);
  while (handle_schedule(&vm) && vm->ctd > 0)
    {
      ++vm->cycle;
      handle_event(&event, vm->sdl);
      if (n == vm->ctd || vm->nb_live == NBR_LIVE)
	{
	  if ((check_prg_live(&vm)) == 0)
	    return ;
	  n = 0;
	  vm->nb_live = 0;
	  reset_live_prg(&vm);
	  vm->ctd = vm->ctd - CYCLE_DELTA;
	}
      ++n;
    }
}
