/*
** xor.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:30:12 2013 guillaume fillon
** Last update Wed Mar 20 23:39:31 2013 remi
*/

#include "lib.h"
#include "vm.h"

void		op_xor(t_vm *vm, t_proc **lproc)
{
  int	param1;
  int	param2;
  int	indice;

  printf("[%d][%d]xor ", (*lproc)->reg[0], (*lproc)->nb_proc);
  indice = 0;
  param1 = return_param_op(lproc, &indice, vm, 6);
  param2 = return_param_op(lproc, &indice, vm, 4);
  (*lproc)->reg[(int)((*lproc)->cmd[indice + 1] & 0xFF) % REG_NUMBER] =
    param1 ^ param2;
  printf("[%d] ^ [%d] = [%d]\n", param1, param2, param1 ^ param2);
  set_carry(lproc, (param1 ^ param2));
 (*lproc)->pc += interval_memory((*lproc)->cmd, (*lproc)->code, 0, 0);
}
