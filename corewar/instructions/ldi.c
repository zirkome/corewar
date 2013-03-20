/*
** ldi.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:28:10 2013 guillaume fillon
** Last update Wed Mar 20 11:00:17 2013 remi
*/

#include "lib.h"
#include "vm.h"

void	op_ldi(t_vm *vm, t_proc **lproc)
{
  int	param1;
  int	param2;
  int	s;
  int	read;
  int	indice;

  printf("%sLDI%s\n", F_CYAN, REZ);
  indice = 0;
  param1 = return_param_op(lproc, &indice, vm, 6);
  param2 = return_param_op(lproc, &indice, vm, 4);
  s = ((vm->mem[((int)((*lproc)->pc + (param1 % IDX_MOD))) % MEM_SIZE] << 8) +
       (vm->mem[((int)((*lproc)->pc + (param1 % IDX_MOD)) + 1)
		% MEM_SIZE] << 8)) + param2;
  read = ((vm->mem[s % MEM_SIZE] << 24) + (vm->mem[s % MEM_SIZE + 1] << 16) +
	  (vm->mem[s % MEM_SIZE + 2] << 8) +
	  (vm->mem[s % MEM_SIZE + 3])) % IDX_MOD;
  set_carry(lproc, read);
  printf("read ldi = %d\n", read);
  printf("read reg ldi : %d\n", (int)(*lproc)->cmd[indice]);
  (*lproc)->reg[(int)(*lproc)->cmd[indice]] = read;
  (*lproc)->pc += interval_memory((*lproc)->cmd, (*lproc)->code, 0, 0);
}
