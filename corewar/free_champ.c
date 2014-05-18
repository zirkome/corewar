#include "lib.h"
#include "vm.h"

/*
** free la vm + les proc
*/
void		free_vm(t_vm *vm)
{
  if (vm == NULL)
    return ;
  if (vm->mem != NULL)
    free(vm->mem);
  if (vm->proc != NULL)
    {
      while (vm->proc != NULL && free_elem_prog(&(vm->proc), 0) == 1);
      while (vm->proc != NULL && free_elem_prog(&(vm->proc), 1) == 1);
      while (vm->proc != NULL && free_elem_prog(&(vm->proc), 2) == 1);
      while (vm->proc != NULL && free_elem_prog(&(vm->proc), 3) == 1);
      free(vm->proc);
    }
  free(vm);
}
