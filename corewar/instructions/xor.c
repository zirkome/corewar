#include "lib.h"
#include "vm.h"

void		op_xor(t_vm *vm, t_proc **lproc)
{
  int	param1;
  int	param2;
  int	indice;

  indice = 0;
  debug(vm, lproc, -1);
  param1 = return_param_op(lproc, &indice, vm, 6);
  param2 = return_param_op(lproc, &indice, vm, 4);
  if ((*lproc)->cmd[indice - 1] < 0)
    (*lproc)->cmd[indice] = 1;
  if (vm->option[0].debug != -1)
    print_debug((param1 ^ param2), "result : ", 0);
  set_carry(lproc, (param1 ^ param2));
  (*lproc)->pc += interval_memory((*lproc)->cmd, (*lproc)->code, 0, 0);
}
