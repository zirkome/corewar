/*
** zjmp.c for CoreWar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:21:16 2013 guillaume fillon
** Last update Thu Mar 28 09:19:21 2013 remi
*/

#include "lib.h"
#include "vm.h"

void		op_zjmp(t_vm *vm, t_proc **lproc)
{
  int		jump;

  jump = 0;
  if (*lproc == NULL)
    return ;
  printf("[%d][%d]zjump ", (*lproc)->reg[0], (*lproc)->nb_proc);
  if (check_carry_champion(vm->proc, (*lproc)->reg[0]) == 0)
    {
      printf("carry 0\n");
      (*lproc)->pc += 3;
      return ;
    }
  jump = (((((*lproc)->cmd[0] << 8)) | (((*lproc)->cmd[1]))) % 0xFFFF) % IDX_MOD;
  printf("jump : [%d] + pc[%d] = ", jump, (*lproc)->pc);
  if ((*lproc)->pc + (jump) < 0)
    jump = MEM_SIZE- jump;
  (*lproc)->pc = (((*lproc)->pc + (jump))) % MEM_SIZE;
  printf("[%d]\n", (*lproc)->pc);
}
