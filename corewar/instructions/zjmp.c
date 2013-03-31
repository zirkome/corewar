/*
** zjmp.c for CoreWar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:21:16 2013 guillaume fillon
** Last update Sun Mar 31 15:24:03 2013 remi
*/

#include "lib.h"
#include "vm.h"

/*
** fais un saut du pc.
** pc actuel + jump;
*/
void	op_zjmp(t_vm *vm, t_proc **lproc)
{
  short	jump;

  jump = 0;
  debug(vm, lproc);
  if (*lproc == NULL)
    return ;
  if (check_carry_champion(vm->proc, (*lproc)->nb_proc) == 0)
    {
      (*lproc)->pc += 3;
      return ;
    }
  jump = ((*lproc)->cmd[0] << 8) & 0xFFFF;
  jump = (jump + (((*lproc)->cmd[1]) & 0xFF));
  (*lproc)->pc = (((*lproc)->pc + (jump % IDX_MOD))) % MEM_SIZE;
  if ((*lproc)->pc + (jump) < 0)
    jump = MEM_SIZE - jump;
  if (vm->option[0].debug != -1)
    print_debug(jump, "jump : ", 0);
  if (vm->option[0].debug != -1)
    print_debug((*lproc)->pc, " PC : ", 1);
}
