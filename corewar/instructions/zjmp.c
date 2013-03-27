/*
** zjmp.c for CoreWar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:21:16 2013 guillaume fillon
** Last update Tue Mar 26 17:51:27 2013 remi
*/

#include "lib.h"
#include "vm.h"

void		op_zjmp(t_vm *vm, t_proc **lproc)
{
  int		jump;

  printf("[%d][%d]zjump ", (*lproc)->reg[0], (*lproc)->nb_proc);
  if (check_carry_champion(vm->proc, (*lproc)->reg[0]) == 0)
    {
      printf("carry 0\n");
      (*lproc)->pc += 3;
      return ;
    }
  //printf("{%d}{%d} = {%d}  ", (*lproc)->cmd[0] % 0xFF, (*lproc)->cmd[1] % 0xFF, (((*lproc)->cmd[0] << 8) | (*lproc)->cmd[1]) % 0xFF);
  jump = (((((*lproc)->cmd[0] << 8)) | (((*lproc)->cmd[1]))) % 0xFFFF) % IDX_MOD;
  printf("jump : [%d] + pc[%d] = ", jump, (*lproc)->pc);
  (*lproc)->pc = (((*lproc)->pc + (jump))) % MEM_SIZE;
  if ((*lproc)->pc < 0)
    (*lproc)->pc = MEM_SIZE - (*lproc)->pc;
  printf("[%d]\n", (*lproc)->pc);
}
