/*
** lfork.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:29:24 2013 guillaume fillon
** Last update Thu Mar 28 10:59:02 2013 remi
*/

#include "lib.h"
#include "vm.h"

void	init_new_proc_lfork(t_proc **new_proc, t_proc **proc_head, int new_pc)
{
  int	indice;

  indice = 0;
  while (indice < 16)
    {
      (*new_proc)->reg[indice] = (*proc_head)->reg[indice];
      indice = indice + 1;
    }
  (*new_proc)->code = 0;
  (*new_proc)->wait = 0;
  (*new_proc)->carry = 0;
  (*new_proc)->nb_proc = (*proc_head)->nb_proc + 1;
  (*new_proc)->live = 0;
  (*new_proc)->pc = (((*proc_head)->pc + new_pc)) % MEM_SIZE;
  if ((*new_proc)->pc < 0)
    (*new_proc)->pc = MEM_SIZE - (*new_proc)->pc;
}

void		op_lfork(t_vm *vm, t_proc **lproc)
{
  int		new_pc;
  t_proc	*new_proc;

  printf("[%d][%d]lfork ", (*lproc)->reg[0], (*lproc)->nb_proc);
  new_pc = (((*lproc)->cmd[0] & 0xFF) << 8) | ((*lproc)->cmd[1] & 0xFF);
  printf("[%d]\n", new_pc);
  if ((new_proc = add_fork(&(vm->proc))) == NULL)
    {
      (*lproc)->pc += 3;
      return ;
    }
  init_new_proc_lfork(&new_proc, lproc, new_pc);
  (*lproc)->pc += 3;
}
