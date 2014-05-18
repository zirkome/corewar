/*
** fork.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:28:20 2013 guillaume fillon
** Last update Sun Mar 31 18:08:30 2013 guillaume fillon
*/

#include "lib.h"
#include "vm.h"

int		get_nb_proc(t_proc *ptete, int nb_champion)
{
  int		nb;
  t_proc	*pcourant;

  if (ptete == NULL)
    return (0);
  pcourant = ptete;
  nb = 0;
  while (pcourant != NULL)
    {
      if (pcourant->reg[0] == nb_champion &&
	  pcourant->nb_proc > nb)
	nb = pcourant->nb_proc;
      pcourant = pcourant->next;
    }
  return (nb);
}

/*
** ajoute a la liste de processus le nouveau proc fork
*/
t_proc		*add_fork(t_proc **ptete, t_proc **elem)
{
  t_proc	*pcourant;

  if (*ptete == NULL ||
      (*elem = malloc(sizeof(t_proc))) == NULL)
    return (*ptete);
  pcourant = *ptete;
  while (pcourant->next != NULL)
    pcourant = pcourant->next;
  (*elem)->next = NULL;
  (*elem)->back = pcourant;
  init_elem(elem, 0, 0, 0);
  pcourant->next = *elem;
  return (*ptete);
}

/*
** init le nouveau proc.
*/
void	init_new_proc(t_vm *vm, t_proc **new_proc,
		      t_proc **proc_head, int new_pc)
{
  int	indice;

  indice = 0;
  while (indice < REG_NUMBER)
    {
      (*new_proc)->cmd[indice % 16] = 0;
      (*new_proc)->reg[indice % REG_NUMBER] =
	(*proc_head)->reg[indice % REG_NUMBER];
      indice = indice + 1;
    }
  (*new_proc)->code = 0;
  (*new_proc)->wait = -1;
  (*new_proc)->carry = 0;
  (*new_proc)->nb_proc = (*proc_head)->nb_proc;
  (*new_proc)->num_proc = get_last_num_proc(vm, (*proc_head)->nb_proc) + 1;
  (*new_proc)->live = 0;
  (*new_proc)->pc = 0;
  if (new_pc < 0)
    (*new_proc)->pc = (MEM_SIZE) + ((*proc_head)->pc - new_pc);
  else
    (*new_proc)->pc = (((*proc_head)->pc + new_pc) % IDX_MOD) % MEM_SIZE;
}

void		op_fork(t_vm *vm, t_proc **lproc)
{
  int		new_pc;
  t_proc	*new_proc;

  new_pc = ((((*lproc)->cmd[0]) << 8) | ((*lproc)->cmd[1])) & 0xFFFF;
  if ((vm->proc = add_fork(&(vm->proc), &new_proc)) == NULL)
    {
      (*lproc)->pc += 3;
      return ;
    }
  init_new_proc(vm, &new_proc, lproc, new_pc);
  vm->nb_proc = vm->nb_proc + 1;
  if (vm->option[0].debug != -1)
    print_debug(new_pc, "new pc : ", 1);
  new_proc->nb_proc = get_nb_proc(vm->proc, (*lproc)->reg[0]);
  debug(vm, lproc, -1);
  (*lproc)->pc += 3;
}
