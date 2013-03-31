/*
** ldi.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:28:10 2013 guillaume fillon
** Last update Sun Mar 31 13:20:51 2013 guillaume fillon
*/

#include "lib.h"
#include "vm.h"

int	get_direct_ldi(t_vm *vm, t_proc **lproc, int octet, int *indice)
{
  int	ret;

  if (*indice < 0)
    *indice = 0;
  ret = ((((*lproc)->cmd[*indice] << 24) |
	  ((*lproc)->cmd[*indice + 1] << 16) |
	  ((*lproc)->cmd[*indice + 2] << 8) |
	  ((*lproc)->cmd[*indice + 3])) & 0xFFFFFFFF);
  *indice = *indice + 4;
  return (ret);
}

int	get_adress_ldi(t_vm *vm, t_proc **lproc, int octet, int *indice)
{
  int	val;

  val = 0;
  if ((((*lproc)->cmd[0] >> octet) & 0x03) == 1)
    {
      val = (*lproc)->cmd[*indice];
      *indice = *indice + 1;
    }
  if ((((*lproc)->cmd[0] >> octet) & 0x03) == 2)
    val = get_direct_ldi(vm, lproc, octet, indice);
  if ((((*lproc)->cmd[0] >> octet) & 0x03) == 3)
    {
      val = (((*lproc)->cmd[*indice] << 8) |
	     (*lproc)->cmd[*indice + 1]) & 0xFFFF;
      *indice = *indice + 2;
      if (val < 0)
	val = MEM_SIZE - val;
      val = vm->mem[((*lproc)->pc + (val)) % MEM_SIZE];
    }
  return (val);
}

void	op_ldi(t_vm *vm, t_proc **lproc)
{
  int	param1;
  int	param2;
  int	indice;

  indice = 2;
  debug(vm, lproc, -1);
  param1 = get_adress_ldi(vm, lproc, 6, &indice);
  param2 = get_adress_ldi(vm, lproc, 4, &indice);
  if (param1 < 0)
    param1 = MEM_SIZE - param1;
  param1 = vm->mem[(int)((*lproc)->pc + (param1 % IDX_MOD)) % MEM_SIZE];
  param1 = param1 + param2;
  set_carry(lproc, param1);
  if (((*lproc)->cmd[indice + 1] - 1) % REG_NUMBER < 0)
    (*lproc)->cmd[indice + 1] = 1;
  if (param1 < 0)
    param1 = MEM_SIZE - param1;
  (*lproc)->reg[((*lproc)->cmd[(indice + 1) %
			       REG_NUMBER] - 1) % REG_NUMBER] =
    vm->mem[(((*lproc)->pc + param1) % IDX_MOD) % MEM_SIZE];
  (*lproc)->pc += interval_memory((*lproc)->cmd, (*lproc)->code, 0, 0);
}
