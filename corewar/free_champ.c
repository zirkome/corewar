/*
** free_champ.c for CoreWar in /home/fillon_g/projets/groups/corewar/corewar
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Sun Jan 27 20:48:10 2013 guillaume fillon
** Last update Sun Jan 27 20:51:00 2013 guillaume fillon
*/

#include "lib.h"
#include "vm.h"

void		free_champ(header_t *header, int nb)
{
  int		i;

  i = 0;
  while (i < nb)
    {
      free(header[i].comment);
      free(header[i].prog_name);
      i += 1;
    }
  free(header);
}
