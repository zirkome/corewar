/*
** sti.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:30:00 2013 guillaume fillon
** Last update Wed Mar 20 22:32:46 2013 remi
*/

#include "lib.h"
#include "vm.h"
#include "couleur.h"

void		load_reg(t_proc **lproc, char *reg)
{
  reg[0] = ((*lproc)->reg[(int)(*lproc)->cmd[1]] >> 24) & 0xFF;
  reg[1] = ((*lproc)->reg[(int)(*lproc)->cmd[1]] >> 16) & 0xFF;
  reg[2] = ((*lproc)->reg[(int)(*lproc)->cmd[1]] >> 8) & 0xFF;
  reg[3] = (*lproc)->reg[(int)(*lproc)->cmd[1]] & 0xFF;
}

int		calc_offset(t_proc **lproc, int *i, int param)
{
  int		offset;

  offset = 0;
  if (((((*lproc)->cmd[0] & 0xFF) >> param) & 0x03) == 1)
    {
      printf("REGISTRE = \n");
      offset = (*lproc)->reg[(int)((*lproc)->cmd[*i] & 0xFF)];
      ++(*i);
    }
  else if (((((*lproc)->cmd[0] & 0xFF) >> param) & 0x3) == 2 ||
	   ((((*lproc)->cmd[0] & 0xFF) >> param) & 0x3) == 3)
    {
      if (((((*lproc)->cmd[0] & 0xFF) >> param) & 0x3) == 2)
	printf("DIRECTE = \n");
      else if (((((*lproc)->cmd[0] & 0xFF) >> param) & 0x3) == 3)
	printf("INDIRECTE = \n");
      offset = ((((*lproc)->cmd[*i] & 0xFF) << 8)) + ((((*lproc)->cmd[*i + 1]) & 0xFF));
      *i += 2;
    }
  printf("%d\n", offset);
  return (offset);
}

void		op_sti(t_vm *vm, t_proc **lproc)
{
  int		i;
  char		reg[4];
  int		offset;

  offset = 0;
  i = 2;
  load_reg(lproc, reg);
  printf("%s[%d] STI%s : ", F_CYAN, (*lproc)->nb_proc, REZ);
  offset += calc_offset(lproc, &i, 4);
  printf("r1 = %d\n", (*lproc)->cmd[1]);
  fflush(stdout);
  my_putstr(", ");
  offset += calc_offset(lproc, &i, 2);
  fflush(stdout);
  /* if (offset < 0) */
  /*   { */
  /*     printf("Bad param\n"); */
  /*     (*lproc)->pc += interval_memory((*lproc)->cmd, (*lproc)->code, 0, 0); */
  /*     return ; */
  /*   } */
  if (offset < 0)
    offset = (MEM_SIZE) + offset;
  printf(" OFfFSET : %d\n", offset);
  vm->mem[offset % MEM_SIZE] = reg[0];
  vm->mem[(offset + 1) % MEM_SIZE] = reg[1];
  vm->mem[(offset + 2) % MEM_SIZE] = reg[2];
  vm->mem[(offset + 3) % MEM_SIZE] = reg[3];
  (*lproc)->pc += interval_memory((*lproc)->cmd, (*lproc)->code, 0, 0);
}
