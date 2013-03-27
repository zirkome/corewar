/*
** lldi.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:27:49 2013 guillaume fillon
** Last update Wed Mar 27 19:06:48 2013 remi
*/

#include "lib.h"
#include "vm.h"

void		op_lldi(t_vm *vm, t_proc **lproc)
{
  int	param1;
  int	param2;
  int	indice;

  printf("[%d][%d]lldi ", (*lproc)->reg[0], (*lproc)->nb_proc);
  indice = 2;
  param1 = get_adress_ldi(vm, lproc, 6, &indice);
  param2 = get_adress_ldi(vm, lproc, 4, &indice);
  if (param1 < 0)
    param1 = MEM_SIZE - param1;
  param1 = vm->mem[((*lproc)->pc + (param1 % IDX_MOD)) % MEM_SIZE];
  param1 = param1 + param2;
  set_carry(lproc, param1);
  if (((*lproc)->cmd[indice + 1] - 1) % REG_NUMBER < 0)
    (*lproc)->cmd[indice + 1] = 1;
  if (param1 < 0)
    param1 = MEM_SIZE - param1;
  printf("{%d} {%d}  ", ((*lproc)->cmd[indice] - 1), (param1) % MEM_SIZE);
  (*lproc)->reg[((*lproc)->cmd[indice + 1] - 1) % REG_NUMBER] = vm->mem[(param1 % IDX_MOD) % MEM_SIZE];
  printf("param 1 %d param 2 % d\n", param1, param2);
  (*lproc)->pc += interval_memory((*lproc)->cmd, (*lproc)->code, 0, 0);
}
