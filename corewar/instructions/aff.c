/*
** aff.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:28:39 2013 guillaume fillon
** Last update Wed Mar 20 21:47:43 2013 remi
*/

#include "lib.h"
#include "vm.h"
#include "couleur.h"

void		op_aff(t_vm *vm, t_proc **lproc)
{
  if ((*lproc)->cmd[1] > 16)
    {
      my_putstr("Bad argurment\n");
      (*lproc)->pc += 1;
      return ;
    }
  printf("%s[%d] AFF%s : ", F_CYAN, (*lproc)->nb_proc, REZ);
  my_putchar((*lproc)->reg[(int)((*lproc)->cmd[1] & 0xFF)]);
  (*lproc)->pc += interval_memory((*lproc)->cmd, (*lproc)->code, 0, 0);
}
