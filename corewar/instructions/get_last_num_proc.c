/*
** get_last_num_proc.c for getnumproc in /home/remi/Projet/save_projet/corewar/corewar
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Fri Mar 29 00:33:51 2013 remi
** Last update Fri Mar 29 00:36:18 2013 remi
*/

#include "lib.h"
#include "vm.h"

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
