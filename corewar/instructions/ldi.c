/*
** ldi.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:28:10 2013 guillaume fillon
** Last update Tue Mar 12 14:16:22 2013 remi
*/

#include "lib.h"
#include "vm.h"

void	op_ldi(t_vm *vm, t_proc **lproc)
{
  short	val1;
  short	val2;

  printf("%sLDI%s\n", F_CYAN, REZ);
  (*lproc)->pc += interval_memory((*lproc)->cmd, (*lproc)->code, 0, 0);
  val1 = ((*lproc)->cmd[1] << 8) | ((*lproc)->cmd[2]);
  val1 = MEM_SIZE % val1;
  val2 = ((*lproc)->cmd[3] << 8) | ((*lproc)->cmd[4]);
  printf("val ldi = [%d] [%d]\n", val1, val2);
  if ((((*lproc)->cmd[0] >> 2) & 0x03) == 1)
    printf("REGISTRE\n");
  if ((((*lproc)->cmd[0] >> 2) & 0x03) == 2)
    printf("DIRECT\n");
  if ((((*lproc)->cmd[0] >> 2) & 0x03) == 3)
    printf("INDIRECT\n");
}
