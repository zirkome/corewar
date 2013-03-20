/*
** and.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:28:57 2013 guillaume fillon
** Last update Wed Mar 20 10:01:59 2013 remi
*/

#include "lib.h"
#include "vm.h"

int	return_param_op(t_proc **lproc, int *indice, t_vm *vm, int decallage)
{
  int	ret;

  if ((((*lproc)->cmd[0] >> decallage) & 0x03) == 1)
    {
      printf("REGISTRE = ");
      *indice = *indice + 1;
      return ((*lproc)->pc + ((*lproc)->cmd[*indice] % IDX_MOD));
    }
  if ((((*lproc)->cmd[0] >> decallage) & 0x03) == 2)
    {
      printf("DIRECTE = ");
      ret = (vm->mem[(int)((((*lproc)->cmd[*indice + 1] << 24)
			    + ((*lproc)->cmd[*indice + 2] << 16) +
			    ((*lproc)->cmd[*indice + 3] << 8) +
			    ((*lproc)->cmd[*indice + 4])) % MEM_SIZE)]);
	*indice = *indice + 4;
	return (ret + (*lproc)->pc) % IDX_MOD;
    }
 if ((((*lproc)->cmd[0] >> decallage) & 0x03) == 3)
    {
      printf("INDIRECTE = ");
      ret = ((*lproc)->pc + ((((*lproc)->cmd[*indice + 1] << 8) +
			      (*lproc)->cmd[*indice + 2]) % IDX_MOD));
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
