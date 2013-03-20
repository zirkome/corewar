/*
** st.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:27:36 2013 guillaume fillon
** Last update Wed Mar 20 23:37:42 2013 remi
*/

#include "lib.h"
#include "vm.h"

void		op_st(t_vm *vm, t_proc **lproc)
{
  int		adress;

  printf("[%d][%d]st ", (*lproc)->reg[0], (*lproc)->nb_proc);
  adress = 0;
  if ((((*lproc)->cmd[0] >> 4) & 0x03) == 1)
    {
      adress = ((*lproc)->pc + (((*lproc)->cmd[2] % IDX_MOD) & 0xFF));
    }
  if ((((*lproc)->cmd[0] >> 4) & 0x03) == 2)
    {
      adress = vm->mem[(int)((((*lproc)->cmd[2] << 24) & 0xFF)
			       + ((((*lproc)->cmd[3] & 0xFF) << 16)) +
			       ((((*lproc)->cmd[4] & 0xFF) << 8)) +
			       (((*lproc)->cmd[5] & 0xFF)) % MEM_SIZE)];
      adress = (adress + (*lproc)->pc) % IDX_MOD;
    }
  if ((((*lproc)->cmd[0] >> 4) & 0x03) == 3)
    {
      adress = ((*lproc)->pc + ((((((*lproc)->cmd[2] & 0xFF) << 8)) +
				 ((*lproc)->cmd[3] & 0xFF)) % IDX_MOD));
    }
  printf("@(%d) <= %d\n", adress, ((*lproc)->cmd[1] & 0xFF));
  vm->mem[adress % MEM_SIZE] = ((*lproc)->cmd[1] & 0xFF);
  (*lproc)->pc += interval_memory((*lproc)->cmd, (*lproc)->code, 0, 0);
}
