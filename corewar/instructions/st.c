/*
** st.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:27:36 2013 guillaume fillon
** Last update Mon Mar 11 15:21:11 2013 remi
*/

#include "lib.h"
#include "vm.h"

void		op_st(t_vm *vm, t_proc **lproc)
{
  int		adress;

  printf("%sST%s\n", F_CYAN, REZ);
  if ((((*lproc)->cmd[0] >> 4) & 0x03) == 1)
    {
      printf("REGISTRE\n");
      (*lproc)->reg[(int)(*lproc)->cmd[2]] =
	(*lproc)->reg[(int)(*lproc)->cmd[1]];
    }
  else
    {
      printf("ADRESSE\n");
      adress = ((*lproc)->cmd[2] << 24) + ((*lproc)->cmd[3] << 16)
	+ ((*lproc)->cmd[4] << 8) + ((*lproc)->cmd[5]);
      vm->mem[((*lproc)->pc + adress) % IDX_MOD] =
	(*lproc)->reg[(int)(*lproc)->cmd[1]];
    }
  (*lproc)->pc += interval_memory((*lproc)->cmd, (*lproc)->code, 0, 0);
}
