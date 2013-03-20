/*
** and.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:28:57 2013 guillaume fillon
** Last update Wed Mar 20 19:24:51 2013 remi
*/

#include "lib.h"
#include "vm.h"

int	return_param_op(t_proc **lproc, int *indice, t_vm *vm, int decallage)
{
  int	ret;

  if (((((*lproc)->cmd[0] & 0xFF) >> decallage) & 0x03) == 1)
    {
      *indice = *indice + 1;
      return ((*lproc)->pc + (((*lproc)->cmd[*indice] & 0xFF) % IDX_MOD));
    }
  if (((((*lproc)->cmd[0] & 0xFF) >> decallage) & 0x03) == 2)
    {
      ret = (vm->mem[(int)(((((*lproc)->cmd[*indice + 1] & 0xFF) << 24))
			   + ((((*lproc)->cmd[*indice + 2] & 0xFF) << 16)) +
			   ((((*lproc)->cmd[*indice + 3] & 0xFF) << 8)) +
			   (((*lproc)->cmd[*indice + 4])) % MEM_SIZE)]) & 0xFF;
      *indice = *indice + 4;
      return (ret + (*lproc)->pc) % IDX_MOD;
    }
  if (((((*lproc)->cmd[0] & 0xFF) >> decallage) & 0x03) == 3)
    {
      ret = ((*lproc)->pc + ((((((*lproc)->cmd[*indice + 1] & 0xFF) << 8)) +
			      (((*lproc)->cmd[*indice + 2] & 0xFF)) % IDX_MOD)));
      *indice = *indice + 2;
      return (ret);
    }
  return (0);
}

void	op_and(t_vm *vm, t_proc **lproc)
{
  int	param1;
  int	param2;
  int	indice;

  printf("%sAND%s : \n", F_CYAN, REZ);
  indice = 0;
  param1 = return_param_op(lproc, &indice, vm, 6);
  param2 = return_param_op(lproc, &indice, vm, 4 );
  set_carry(lproc, (param1 & param2));
  printf("resultat : %d\n", param1 & param2);
  (*lproc)->reg[(int)(*lproc)->cmd[indice + 1] % REG_NUMBER] = param1 & param2;
  (*lproc)->pc += interval_memory((*lproc)->cmd, (*lproc)->code, 0, 0);
}
