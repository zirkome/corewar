/*
** fork.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:28:20 2013 guillaume fillon
** Last update Wed Mar 27 12:59:08 2013 remi
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

t_proc		*add_fork(t_proc **ptete)
{
  t_proc	*pcourant;
  t_proc	*elem;

  if (*ptete == NULL ||
      (elem = malloc(sizeof(t_proc))) == NULL)
    return (NULL);
  pcourant = *ptete;
  while (pcourant->next != NULL)
    pcourant = pcourant->next;
  elem->next = NULL;
  elem->back = pcourant;
  pcourant->next = elem;
  return (elem);
}

void	view_list(t_proc *ptete)
{
  t_proc	*pcourant;

  pcourant = ptete;
  while (pcourant != NULL)
    {
      printf("NNNN{%d}\n", pcourant->reg[0]);
      pcourant = pcourant->next;
    }
}

void	init_new_proc(t_proc **new_proc, t_proc **proc_head, int new_pc)
{
  int	indice;

  indice = 0;
  while (indice < 16)
    {
      (*new_proc)->cmd[indice] = 0;
      (*new_proc)->reg[indice] = (*proc_head)->reg[indice];
      indice = indice + 1;
    }
  (*new_proc)->code = 0;
  (*new_proc)->cmd[indice] = 0;
  (*new_proc)->wait = 0;
  (*new_proc)->carry = 0;
  (*new_proc)->nb_proc = (*proc_head)->nb_proc + 1;;
  (*new_proc)->live = 0;
  if (new_pc < 0)
    (*new_proc)->pc = (MEM_SIZE) + ((*proc_head)->pc - new_pc);
  else
    (*new_proc)->pc = (((*proc_head)->pc + new_pc) % IDX_MOD) % MEM_SIZE;
}

void		op_fork(t_vm *vm, t_proc **lproc)
{
  int		new_pc;
  t_proc	*new_proc;

  printf("[%d][%d]fork ", (*lproc)->reg[0], (*lproc)->nb_proc);
  new_pc = (((*lproc)->cmd[0] & 0xFF) << 8) | ((*lproc)->cmd[1] & 0xFF);
  printf("[%d]\n", new_pc);
  if ((new_proc = add_fork(&(vm->proc))) == NULL)
    return ;
  init_new_proc(&new_proc, lproc, new_pc);
  new_proc->nb_proc = get_nb_proc(vm->proc, (*lproc)->reg[0]);
  //view_list(vm->proc);
  (*lproc)->pc += 3;
 }
