/*
** add.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:28:50 2013 guillaume fillon
** Last update Wed Mar 20 23:37:22 2013 remi
*/

#include "lib.h"
#include "vm.h"

void		op_add(t_vm *vm, t_proc **lproc)
{
  printf("[%d][%d]add \n", (*lproc)->reg[0], (*lproc)->nb_proc);
  if ((*lproc)->cmd[1] > 16 || (*lproc)->cmd[2] > 16 || (*lproc)->cmd[3] > 16)
    {
      printf("Bad argurment\n");
      (*lproc)->pc += 1;
      return ;
    }
  (*lproc)->reg[(int)(*lproc)->cmd[3]] =
    (*lproc)->reg[(int)((*lproc)->cmd[1] & 0xFF)] +
    (*lproc)->reg[(int)((*lproc)->cmd[2] & 0xFF)];
  printf("[%d] + [%d] = [%d]\n", (*lproc)->reg[(int)((*lproc)->cmd[1] & 0xFF)],
	 (*lproc)->reg[(int)((*lproc)->cmd[2] & 0xFF)],
	 (*lproc)->reg[(int)((*lproc)->cmd[3] & 0xFF)]);
  if ((*lproc)->reg[(int)((*lproc)->cmd[3] & 0xFF)] == 0)
    {
      if ((*lproc)->carry == 0)
	(*lproc)->carry = 1;
      else
	(*lproc)->carry = 0;
    }
  (*lproc)->pc += interval_memory((*lproc)->cmd, (*lproc)->code, 0, 0);
}
