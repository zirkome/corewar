#include "lib.h"
#include "vm.h"

/*
** Permet suivant l' option -n de changer le numéro du champion
*/
void		init_option_number_proc(t_proc *ptete, int nb)
{
  t_proc	*pcourant;

  if (ptete == NULL || nb == -1)
    return ;
  pcourant = ptete;
  while (pcourant->next != NULL)
    pcourant = pcourant->next;
  pcourant->nb_proc = nb;
  pcourant->reg[0] = nb;
}
