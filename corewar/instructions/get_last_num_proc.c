#include "lib.h"
#include "vm.h"

/*
** retourne le numero de proc le plus grand d un champion.
** correspond au nombre de processus par ce champion
*/
int		get_last_num_proc(t_vm *vm, int nb_proc)
{
  t_proc	*pcourant;
  int		temp;

  if (vm->proc == NULL)
    return (0);
  temp = 0;
  pcourant = vm->proc;
  while (pcourant != NULL)
    {
      if (temp < pcourant->num_proc)
	temp = pcourant->num_proc;
      pcourant = pcourant->next;
    }
  return (temp);
}
