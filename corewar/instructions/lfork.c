/*
** lfork.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:29:24 2013 guillaume fillon
** Last update Sun Mar 31 18:09:14 2013 guillaume fillon
*/

#include "lib.h"
#include "vm.h"

/*
** initialise le nouveau processus de lfork;
*/
void	init_new_proc_lfork(t_vm *vm, t_proc **new_proc,
			    t_proc **proc_head, int new_pc)
{
  int	indice;

  indice = 0;
  while (indice < 16)
    {
      (*new_proc)->reg[indice % REG_NUMBER] =
	(*proc_head)->reg[indice % REG_NUMBER];
      indice = indice + 1;
    }
  (*new_proc)->code = 0;
  (*new_proc)->wait = -1;
  (*new_proc)->carry = 0;
  (*new_proc)->nb_proc = (*proc_head)->nb_proc;
  (*new_proc)->num_proc = get_last_num_proc(vm, (*proc_head)->nb_proc);
  (*new_proc)->live = 0;
  (*new_proc)->pc = (((*proc_head)->pc + new_pc)) % MEM_SIZE;
  if ((*new_proc)->pc < 0)
    (*new_proc)->pc = MEM_SIZE - (*new_proc)->pc;
}

void		op_lfork(t_vm *vm, t_proc **lproc)
{
  int		new_pc;
  t_proc	*new_proc;

  new_pc = (((*lproc)->cmd[0] & 0xFF) << 8) | ((*lproc)->cmd[1] & 0xFF);
  if ((vm->proc = add_fork(&(vm->proc), &new_proc)) == NULL)
    {
      (*lproc)->pc += 3;
      return ;
    }
  if (vm->option[0].debug != -1)
    print_debug(new_pc, "new pc : ", 1);
  init_new_proc_lfork(vm, &new_proc, lproc, new_pc);
  debug(vm, lproc, -1);
  (*lproc)->pc += 3;
}
