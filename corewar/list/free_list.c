/*
** free_list.c for CoreWar in /home/fillon_g/projets/groups/corewar/corewar
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Sun Jan 27 20:32:13 2013 guillaume fillon
** Last update Mon Jan 28 12:10:14 2013 remi robert
*/

#include "lib.h"
#include "vm.h"

void		free_proc(t_proc *lproc)
{
  t_proc	*tmp;

  tmp = lproc->next;
  while (tmp != lproc)
    {
      pop(tmp);
      tmp = lproc->next;
    }
  free(lproc);
}
