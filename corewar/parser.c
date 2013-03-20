/*
** parser.c for parser in /home/remi/corewar-ce1098f977d5a07e4c8c55c6a935fb2962d4b8a7/corewar
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Tue Jan 29 13:13:40 2013 remi robert
** Last update Wed Mar 20 19:01:32 2013 remi
*/

#include "lib.h"
#include "vm.h"

void	parser(t_vm *vm, t_proc *lproc, int add)
{
  int	i;

  i = 0;
  if (lproc->pc >= MEM_SIZE)
    lproc->pc = lproc->pc % MEM_SIZE;
  if ((vm->mem[(lproc->pc)] & 0xFF) >= 0x01 &&
      (vm->mem[(lproc->pc)] & 0xFF) <= 0x10)
    {
      lproc->code = vm->mem[lproc->pc] & 0xFF;
      while (i < 17)
	{
	  if (lproc->pc + i < MEM_SIZE)
	    lproc->cmd[i] = (vm->mem[(lproc->pc + i + 1) % MEM_SIZE]) & 0xFF;
	  else
	    lproc->cmd[i] = 0x0;
	  i = i + 1;
	}
      return ;
    }
  lproc->pc = (lproc->pc + 1) % (MEM_SIZE + 1);
  lproc->code = -1;
}
