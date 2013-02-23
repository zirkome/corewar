/*
** interval_mem.c for interval_mem in /home/remi/Projet/corewar/corewar/instructions
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Wed Jan 30 08:50:03 2013 remi robert
** Last update Sat Feb 23 12:23:08 2013 remi robert
*/

#include "lib.h"
#include "vm.h"

/*
**           |   |
**           |   |
**           |   |
**          --   --
**          \     /
**           \   /
**            \ /
**      CALCUL ET RETOURNE LE PC
**
*/

/*
** Test de retour valeur Pc + 1 car decallage de 1 avec les instructions.
*/

/* int	interval_memory(char *cmd, int a, int f, int g) */
/* { */
/*   char	param_sz[3]; */
/*   int	offset; */
/*   int	pc; */

/*   param_sz[0] = 1; */
/*   param_sz[1] = DIR_SIZE; */
/*   param_sz[2] = IND_SIZE; */
/*   offset = 6; */
/*   pc = 0; */
/*   while (offset >= 0) */
/*     { */
/*       pc = pc + param_sz[((cmd[1] >> offset) & 0x03) - 1]; */
/*       offset = offset - 2; */
/*     } */
/*   return (pc + 1); */
/* } */

int	decoupage_pc(int pc)
{
  int	interval;
  char	param_sz[3];

  param_sz[0] = 1;
  param_sz[1] = 2;
  param_sz[2] = 4;
  interval = 0;
  interval = interval + param_sz[((pc >> 6) & 0x03) - 1];
  interval = interval + param_sz[((pc >> 4) & 0x03) - 1];
  interval = interval + param_sz[((pc >> 2) & 0x03) - 1];
  interval = interval + param_sz[((pc) & 0x03) - 1];
  printf("%s             %s\n", F_VERT, REZ);
  return (interval + 2);
}

int	interval_memory(char *cmd, int i, int interval, int indice)
{
  int	offset;
  char	param_sz[3];

  param_sz[0] = 1;
  param_sz[1] = DIR_SIZE;
  param_sz[2] = IND_SIZE;
  printf("cmd = %X\n", cmd[i]);
  return (decoupage_pc(cmd[i] & 0xFF));
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
  /* if ((cmd[i] & 0xFF) == 0x01) */
  /*   interval = 3; */
  /* if (((cmd[i] & 0xFF) - 1) == 8) */
  /*   interval = 1; */
  if (interval + i > MEM_SIZE)
    interval = MEM_SIZE - i;
  return (interval + 1);
}
