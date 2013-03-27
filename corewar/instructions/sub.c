/*
** sub.c for CoreWar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:27:09 2013 guillaume fillon
** Last update Tue Mar 26 13:47:56 2013 remi
*/

#include "lib.h"
#include "vm.h"

void		op_sub(t_vm *vm, t_proc **lproc)
{
  printf("[%d][%d]sub ", (*lproc)->reg[0], (*lproc)->nb_proc);
  if ((*lproc)->cmd[1] > 16 || (*lproc)->cmd[2] > 16 || (*lproc)->cmd[3] > 16)
    {
      printf("Bad argurment\n");
      (*lproc)->pc += 1;
      return ;
    }
  (*lproc)->reg[(int)((*lproc)->cmd[3] - 1)] =
    (*lproc)->reg[(int)(((*lproc)->cmd[1] - 1) & 0xFF)] -
    (*lproc)->reg[(int)(((*lproc)->cmd[2] - 1) & 0xFF)];
  if ((*lproc)->reg[(int)(((*lproc)->cmd[3] - 1) & 0xFF)] == 0)
    {
      if ((*lproc)->carry == 0)
	(*lproc)->carry = 1;
      else
	(*lproc)->carry = 0;
    }
  printf("[%d] - [%d] = [%d]\n",     (*lproc)->reg[(int)((*lproc)->cmd[1] & 0xFF)],
	 (*lproc)->reg[(int)(((*lproc)->cmd[2] - 1) & 0xFF)],
	 (*lproc)->reg[(int)(((*lproc)->cmd[3] - 1) & 0xFF)]);
  (*lproc)->pc += interval_memory((*lproc)->cmd, (*lproc)->code, 0, 0);
 }
