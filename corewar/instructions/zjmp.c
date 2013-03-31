/*
** zjmp.c for CoreWar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:21:16 2013 guillaume fillon
** Last update Thu Mar 28 17:39:56 2013 remi
*/

#include "lib.h"
#include "vm.h"

void		op_zjmp(t_vm *vm, t_proc **lproc)
{
  int		jump;

  jump = 0;
  debug(vm, lproc);
  if (*lproc == NULL)
    return ;
  if (check_carry_champion(vm->proc, (*lproc)->nb_proc) == 0)
    {
      (*lproc)->pc += 3;
      return ;
    }
  jump = ((((*lproc)->cmd[0] << 8) | ((*lproc)->cmd[1])) % 0xFFFF) % IDX_MOD;
  if ((*lproc)->pc + (jump) < 0)
    jump = MEM_SIZE- jump;
  (*lproc)->pc = (((*lproc)->pc + (jump))) % MEM_SIZE;
}
