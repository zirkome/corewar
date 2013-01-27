/*
** utils.c for CoreWar in /home/fillon_g/projets/groups/corewar/corewar/list
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Sun Jan 27 00:44:43 2013 guillaume fillon
** Last update Sun Jan 27 00:55:35 2013 guillaume fillon
*/

#include "lib.h"
#include "vm.h"

void		init_reg(int *buf, int cid)
{
  int		i;

  i = 0;
  while (i < 16)
    {
      buf[i++] = 0;
    }
  buf[0] = cid;
}
