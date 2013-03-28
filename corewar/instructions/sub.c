/*
** sub.c for CoreWar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:27:09 2013 guillaume fillon
** Last update Thu Mar 28 17:41:31 2013 remi
*/

#include "lib.h"
#include "vm.h"

void		op_sub(t_vm *vm, t_proc **lproc)
{
  debug(vm, lproc);
  if ((*lproc)->cmd[1] > 16 || (*lproc)->cmd[2] > 16 || (*lproc)->cmd[3] > 16)
    {
      (*lproc)->pc += 1;
      return ;
    }
  (*lproc)->reg[(int)((*lproc)->cmd[3] - 1) % REG_NUMBER] =
    (*lproc)->reg[(int)(((*lproc)->cmd[1] - 1) & 0xFF) % REG_NUMBER] -
    (*lproc)->reg[(int)(((*lproc)->cmd[2] - 1) & 0xFF) % REG_NUMBER];
  set_carry(lproc,
	    (*lproc)->reg[(int)(((*lproc)->cmd[3] - 1) & 0xFF) % REG_NUMBER]);
  (*lproc)->pc += interval_memory((*lproc)->cmd, (*lproc)->code, 0, 0);
 }
