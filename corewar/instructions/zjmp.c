/*
** zjmp.c for CoreWar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:21:16 2013 guillaume fillon
** Last update Wed Mar 20 10:10:07 2013 remi
*/

#include "lib.h"
#include "vm.h"

void		op_zjmp(t_vm *vm, t_proc **lproc)
{
  short		jump;

  printf("%sZJUMP%s\n", F_CYAN, REZ);
  if (check_carry_champion(vm->proc, (*lproc)->reg[0]) == 0)
    {
      (*lproc)->pc += 3;
      return ;
    }
  jump = ((*lproc)->cmd[0] << 8) | ((*lproc)->cmd[1]);
  printf("Saut :[%d]<< [%d] = [%d]\n", (*lproc)->cmd[0], (*lproc)->cmd[1], jump);
  (*lproc)->pc = MEM_SIZE % (((*lproc)->pc + jump) + 1);
  printf("PC final : %d\n", (*lproc)->pc);
}
