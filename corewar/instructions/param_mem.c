/*
** param_mem.c for param_mem in /home/remi/Projet/corewar/corewar/instructions
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Wed Jan 30 09:21:35 2013 remi robert
** Last update Wed Jan 30 09:52:29 2013 remi robert
*/

#include "lib.h"
#include "vm.h"

int	value_param(char *cmd, int *pos, int type)
{
  int	value;

  value = 0;
  while (type > 0)
    {
      value += (cmd[*pos] << type - 1);
      type -= 1;
      *pos += 1;
    }
  return (value);
}

void	param_memomy(char *cmd, char *param)
{
  int	offset;
  int	indice;
  int	pos;
  char	param_sz[3];

  param_sz[0] = 1;
  param_sz[1] = DIR_SIZE;
  param_sz[2] = IND_SIZE;
  offset = 6;
  indice = 0;
  pos = 1;
  while (offset > 0)
    {
      if (((mem[i + 1] >> offset) & 0x3) != 0)
	param[indice] =
	  value_param(cmd, &pos, param_sz[(int)((cmd[0] >> offset) & 0x3)]);
      offset -= 2;
      indice += 1;
    }
}
