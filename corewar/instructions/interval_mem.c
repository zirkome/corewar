/*
** interval_mem.c for interval_mem in /home/remi/Projet/corewar/corewar/instructions
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Wed Jan 30 08:50:03 2013 remi robert
** Last update Sun Mar 31 18:07:38 2013 guillaume fillon
*/

#include "lib.h"
#include "vm.h"

/*
** Fonction permettant de calculer l avancer du pc aprés avoir
** executé une instruction.
*/

/*
** cas partisulier
*/
void	rempl_param_sz(char *interval, int cmd)
{
  if (cmd == 0x0B)
    {
      interval[1] = 2;
      interval[2] = 2;
    }
  if (cmd == 0x0A)
    {
      interval[0] = 2;
      interval[1] = 2;
    }
  if (cmd == 0x06 || cmd == 0x07)
    interval[2] = 1;
  if (cmd == 0x02)
    interval[1] = 1;
  if (cmd == 0x03)
    interval[0] = 1;
  if (cmd == 0x04 || cmd == 0x05)
    {
      interval[0] = 1;
      interval[1] = 1;
      interval[2] = 1;
    }
}

/*
** calculdu pc on focntion de l octet de codage
*/
int	decoupage_pc(int pc, int cmd)
{
  char	interval[4];
  char	param_sz[3];

  param_sz[0] = 1;
  param_sz[1] = 4;
  param_sz[2] = 2;
  interval[0] = ((pc >> 6) & 0x03);
  interval[1] = ((pc >> 4) & 0x03);
  interval[2] = ((pc >> 2) & 0x03);
  interval[3] = ((pc) & 0x03);
  if (interval[0] > 0)
    interval[0] = param_sz[interval[0] - 1];
  if (interval[1] > 0)
    interval[1] = param_sz[interval[1] - 1];
  if (interval[2] > 0)
    interval[2] = param_sz[interval[2] - 1];
  if (interval[3] > 0)
    interval[3] = param_sz[interval[3] - 1];
  rempl_param_sz(interval, cmd);
  return ((interval[0] + interval[1] + interval[2] +
	   interval[3] + 2) % MEM_SIZE);
}

int	interval_memory(char *cmd, int pc, int interval, int indice)
{
  if (cmd == NULL || (cmd[0] & 0x3) < 0 || (cmd[0] & 0x3) > REG_NUMBER)
    return (1);
  return (decoupage_pc((cmd[0] & 0xFF), pc));
}
