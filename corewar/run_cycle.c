/*
** boucle.c for boucle in /home/remi/Projet/corewar/corewar
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Jan 28 13:10:36 2013 remi robert
** Last update Mon Jan 28 23:07:32 2013 remi robert
*/

#include "vm.h"
#include "lib.h"
#include "op.h"

void	exec_instruction(t_vm *vm, t_proc *proc)
{
  void	(*f[16])(t_vm *, t_proc *);

  f[0] = &op_live;
  f[1] = &op_ld;
  f[2] = &op_st;
  f[3] = &op_add;
  f[4] = &op_sub;
  f[5] = &op_and;
  f[6] = &op_or;
  f[7] = &op_xor;
  f[8] = &op_zjmp;
  f[9] = &op_ldi;
  f[10] = &op_sti;
  f[11] = &op_fork;
  f[12] = &op_lld;
  f[13] = &op_lldi;
  f[14] = &op_lfork;
  f[15] = &op_aff;

  if (proc->instruction <= 16 && proc->instruction >= 0)
    f[proc->instruction - 1](vm, proc);
}

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

void		decrement_cycle(t_vm *vm)
{
  t_proc	*cur_proc;

  if (vm->proc == NULL)
    return ;
  cur_proc = vm->proc->next;
  while (cur_proc != vm->proc)
    {
      cur_proc->cycle = cur_proc->cycle - 1;
      if (cur_proc->cycle <= 0)
	{
	  exec_instruction(vm, cur_proc);
	  parser(vm, cur_proc);
	  if (cur_proc->instruction <= 16 && cur_proc->instruction >= 0)
	    cur_proc->cycle = op_tab[cur_proc->instruction - 1].nbr_cycles;
	}
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
  /* vm->proc->next->reg[3] = 42; */
  /* exec_instruction(vm, vm->proc->next); */
  while (cur_cycle <= CYCLE_TO_DIE && check_ch_live(vm) == 1)
    {
      i = 0;
      while (i <= CYCLE_TO_DIE - cur_cycle && check_ch_live(vm) == 1)
	{
	  /* gestion des cycles et executions de l' instruction si variable cycle ets a zero */
	  /* decrement_cycle(vm); */
	  i = i + 1;
	}
      cur_cycle += CYCLE_DELTA;
    }
  printf("\n");
}
