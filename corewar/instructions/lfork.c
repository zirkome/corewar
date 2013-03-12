/*
** lfork.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:29:24 2013 guillaume fillon
** Last update Tue Mar 12 19:06:02 2013 remi
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
  (*new_proc)->wait = -1;
  (*new_proc)->carry = 1;
  (*new_proc)->pc = (((*proc_head)->pc + new_pc) % IDX_MOD) % MEM_SIZE;
}

void		op_lfork(t_vm *vm, t_proc **lproc)
{
  int		new_pc;
  t_proc	*new_proc;

  printf("%sLFORK%s\n", F_CYAN, REZ);
  new_pc = ((*lproc)->cmd[0] << 8) | (*lproc)->cmd[1];
  printf("[%d]\n", new_pc);
  if ((new_proc = add_fork(&(vm->proc))) == NULL)
    return ;
  init_new_proc_lfork(&new_proc, lproc, new_pc);
  (*lproc)->pc += 3;
}
