/*
** add.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:28:50 2013 guillaume fillon
** Last update Thu Mar 28 13:41:28 2013 remi
*/

#include "lib.h"
#include "vm.h"

void		op_add(t_vm *vm, t_proc **lproc)
{
  if ((*lproc)->cmd[1] > REG_NUMBER || (*lproc)->cmd[2] > REG_NUMBER ||
      (*lproc)->cmd[3] > REG_NUMBER || (*lproc)->cmd[1] < 0 ||
      (*lproc)->cmd[2] < 0 || (*lproc)->cmd[3] < 0)
    {
      (*lproc)->pc += 1;
      return ;
    }
  (*lproc)->reg[(int)((*lproc)->cmd[3] - 1) % REG_NUMBER] =
    (*lproc)->reg[(int)(((*lproc)->cmd[1] - 1) & 0xFF) % REG_NUMBER] +
    (*lproc)->reg[(int)(((*lproc)->cmd[2] - 1) & 0xFF) % REG_NUMBER];
  set_carry(lproc, (*lproc)->reg[(int)((*lproc)->cmd[3] - 1) % REG_NUMBER] & 0xFF);
  (*lproc)->pc += interval_memory((*lproc)->cmd, (*lproc)->code, 0, 0);
}
