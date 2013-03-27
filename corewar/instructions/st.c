/*
** st.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:27:36 2013 guillaume fillon
** Last update Wed Mar 27 19:32:26 2013 remi
*/

#include "lib.h"
#include "vm.h"

void	load_reg_st(t_proc **lproc, char *reg)
{
  if ((*lproc)->cmd[1] - 1 < 0)
    (*lproc)->cmd[1] = 1;
  reg[0] = ((*lproc)->reg[((int)(*lproc)->cmd[1] - 1) % REG_NUMBER] >> 24) & 0xFF;
  reg[1] = ((*lproc)->reg[((int)(*lproc)->cmd[1] - 1) % REG_NUMBER] >> 16) & 0xFF;
  reg[2] = ((*lproc)->reg[((int)(*lproc)->cmd[1] - 1) % REG_NUMBER] >> 8) & 0xFF;
  reg[3] = ((*lproc)->reg[((int)(*lproc)->cmd[1] - 1) % REG_NUMBER]) & 0xFF;
}

void	get_adress_st(t_vm *vm, t_proc **lproc, int *adress)
{
  if ((((*lproc)->cmd[0] >> 4) & 0x03) == 1)
    {
      *adress = (*lproc)->cmd[2];
    }
  if ((((*lproc)->cmd[0] >> 4) & 0x03) == 3)
    {
      *adress = (((*lproc)->cmd[2] << 24) | ((*lproc)->cmd[3] << 16) |
		 ((*lproc)->cmd[4] << 8) | ((*lproc)->cmd[5])) & 0xFFFFFFFF;
    }
  if ((((*lproc)->cmd[0] >> 4) & 0x03) == 2)
    {
      *adress = (((*lproc)->cmd[2] << 8) | (*lproc)->cmd[3]) & 0xFFFF;
      if (*adress < 0)
	*adress = MEM_SIZE - *adress;
      *adress = vm->mem[*adress % MEM_SIZE];
    }
}

void	store_st(t_vm *vm, char *reg, t_proc **lproc, int adress)
{
  if ((((*lproc)->cmd[0] >> 4) & 0x03) == 1)
    {
      (*lproc)->reg[(adress - 1) % REG_NUMBER] = (reg[0] << 24) | (reg[1] << 16) |
	(reg[2] << 8) | (reg[3]);
    }
  if ((((*lproc)->cmd[0] >> 4) & 0x03) == 2 ||
      (((*lproc)->cmd[0] >> 4) & 0x03) == 3)
    {
      if (adress < 0)
	adress = MEM_SIZE - adress;
      vm->mem[((*lproc)->pc + adress) % MEM_SIZE] = reg[0];
      vm->mem[((*lproc)->pc + (adress + 1)) % MEM_SIZE] = reg[1];
      vm->mem[((*lproc)->pc + (adress + 2)) % MEM_SIZE] = reg[2];
      vm->mem[((*lproc)->pc + (adress + 3)) % MEM_SIZE] = reg[3];
    }
}

void		op_st(t_vm *vm, t_proc **lproc)
{
  int		adress;
  char		reg[4];

  adress = 0;
  reg[0] = 0;
  reg[1] = 0;
  reg[2] = 0;
  reg[3] = 0;
  adress = 0;
  printf("[%d][%d]st ", (*lproc)->reg[0], (*lproc)->nb_proc);
  load_reg_st(lproc, reg);
  get_adress_st(vm, lproc, &adress);
  printf("Adress = %d  ", adress);
  printf("[%d] => @(%d)\n", ((*lproc)->cmd[1] & 0xFF), adress);
  store_st(vm, reg, lproc, adress);
  (*lproc)->pc += interval_memory((*lproc)->cmd, (*lproc)->code, 0, 0);
}
