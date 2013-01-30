/*
** interval_mem.c for interval_mem in /home/remi/Projet/corewar/corewar/instructions
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Wed Jan 30 08:50:03 2013 remi robert
** Last update Wed Jan 30 09:52:30 2013 remi robert
*/

#include "lib.h"
#include "vm.h"

int	interval_memory(char *cmd, int i, int interval, int indice)
{
  int	offset;
  char	param_sz[3];

  param_sz[0] = 1;
  param_sz[1] = DIR_SIZE;
  param_sz[2] = IND_SIZE;
  if (((cmd[i] & 0xFF) - 1) == 10)
    param_sz[1] = 2;
  offset = 6;
  while (indice < 4)
    {
      if (((cmd[i + 1] >> offset) & 0x3) != 0)
	interval = interval + param_sz[((cmd[i + 1] >> offset) & 0x3) - 1];
      offset = offset - 2;
      indice = indice + 1;
    }
  if ((cmd[i] & 0xFF) == 0x01)
    interval = 3;
  if (((cmd[i] & 0xFF) - 1) == 8)
    interval = 1;
  if (interval + i > MEM_SIZE)
    interval = MEM_SIZE - i;
  return (interval);
}
