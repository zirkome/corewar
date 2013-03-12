/*
** st.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:27:36 2013 guillaume fillon
** Last update Tue Mar 12 23:04:44 2013 remi
*/

#include "lib.h"
#include "vm.h"

void		op_st(t_vm *vm, t_proc **lproc)
{
  int		adress;

  printf("%sST%s\n", F_CYAN, REZ);
  adress = 0;
  printf("ST ARG = %d\n", (*lproc)->cmd[0]);
  if ((((*lproc)->cmd[0] >> 4) & 0x03) == 1)
    {
      printf("REGISTRE\n");
      adress = ((*lproc)->pc + ((*lproc)->cmd[2] % IDX_MOD));
    }
  if ((((*lproc)->cmd[0] >> 4) & 0x03) == 2)
    {
      printf("DIRECT\n");
      adress = vm->mem[(int)((((*lproc)->cmd[2] << 24)
			     + ((*lproc)->cmd[3] << 16) +
			     ((*lproc)->cmd[4] << 8) +
			     ((*lproc)->cmd[5])) % MEM_SIZE)];
      adress = (adress + (*lproc)->pc) % IDX_MOD;
    }
  if ((((*lproc)->cmd[0] >> 4) & 0x03) == 3)
    {
      printf("INDIRECT\n");
      adress = ((*lproc)->pc + ((((*lproc)->cmd[2] << 8) +
				 (*lproc)->cmd[3]) % IDX_MOD));
    }
  vm->mem[adress % MEM_SIZE] = (*lproc)->cmd[1];
  (*lproc)->pc += interval_memory((*lproc)->cmd, (*lproc)->code, 0, 0);
}
