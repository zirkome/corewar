/*
** st.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:27:36 2013 guillaume fillon
** Last update Mon Feb 25 08:45:59 2013 remi robert
*/

#include "lib.h"
#include "vm.h"

void		op_st(t_vm *vm, t_proc **lproc)
{
  printf("%sST%s\n", F_CYAN, REZ);
  if ((((*lproc)->cmd[0] >> 4) & 0x03) == 1)
    (*lproc)->reg[(int)(*lproc)->cmd[2]] = (*lproc)->reg[(int)(*lproc)->cmd[1]];
  if ((((*lproc)->cmd[0] >> 4) & 0x03) == 2)
    (*lproc)->reg[(int)(*lproc)->cmd[2]] = ((*lproc)->cmd[2] << 24) +
      ((*lproc)->cmd[3] << 16)
      + ((*lproc)->cmd[4] << 8) + ((*lproc)->cmd[5]);
  if ((((*lproc)->cmd[0] >> 4) & 0x03) == 3)
    (*lproc)->reg[(int)(*lproc)->cmd[2]] =
      vm->mem[(int)(((((*lproc)->cmd[2] << 8) +
		      ((*lproc)->cmd[3])) % IDX_MOD) + (*lproc)->pc)];
  (*lproc)->pc += interval_memory((*lproc)->cmd, 0, 0, 0);
}
