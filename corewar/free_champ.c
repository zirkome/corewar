/*
** free_champ.c for CoreWar in /home/fillon_g/projets/groups/corewar/corewar
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Sun Jan 27 20:48:10 2013 guillaume fillon
** Last update Fri Mar 29 22:32:48 2013 remi
*/

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
