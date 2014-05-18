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
  debug(vm, lproc, -1);
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
