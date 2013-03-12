/*
** st.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:27:36 2013 guillaume fillon
** Last update Tue Mar 12 21:08:08 2013 guillaume fillon
*/

#include "lib.h"
#include "vm.h"

void		op_st(t_vm *vm, t_proc **lproc)
{
  int		adress;

  printf("%sST%s : ", F_CYAN, REZ);
  if ((((*lproc)->cmd[0] >> 4) & 0x03) == 1)
    {
      printf("REGISTRE");
      (*lproc)->reg[(int)(*lproc)->cmd[2]] =
	(*lproc)->reg[(int)(*lproc)->cmd[1]];
    }
  else
    {
      printf("ADRESSE");
      adress = ((*lproc)->cmd[2] << 24) + ((*lproc)->cmd[3] << 16)
	+ ((*lproc)->cmd[4] << 8) + ((*lproc)->cmd[5]);
      vm->mem[((*lproc)->pc + adress) % IDX_MOD] =
	(*lproc)->reg[(int)(*lproc)->cmd[1]];
    }
  (*lproc)->pc += interval_memory((*lproc)->cmd, (*lproc)->code, 0, 0);
}
