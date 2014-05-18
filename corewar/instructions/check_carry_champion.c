#include "lib.h"
#include "vm.h"

/*
** retourne l etat de carry d un champion, utilise par
** sjump par exmple pour savoir si on effectuer cette instruction
*/
int		check_carry_champion(t_proc *ptete, int num_champion)
{
  t_proc	*pcourant;

  if (ptete == NULL)
    return (0);
  pcourant = ptete;
  while (pcourant != NULL)
    {
      if (pcourant->nb_proc == num_champion &&
	  pcourant->carry == 1)
	return (1);
      pcourant = pcourant->next;
    }
  return (0);
}
