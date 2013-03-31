/*
** sti.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:30:00 2013 guillaume fillon
** Last update Thu Mar 28 17:52:27 2013 remi
*/

#include "lib.h"
#include "vm.h"
#include "couleur.h"

void	init_tab(char *reg)
{
  reg[0] = 0;
  reg[1] = 0;
  reg[2] = 0;
  reg[3] = 0;
}

void		load_reg(t_vm *vm, t_proc **lproc, char *reg, int *i)
{
  int		adress;

  if ((((*lproc)->cmd[0] >> 6) & 0x03) == 1)
    get_reg_reg(vm, lproc, i, reg);
  if ((((*lproc)->cmd[0] >> 6) & 0x03) == 2)
    {
      adress = get_adress_reg(vm, lproc, i);
	if (adress < 0)
	adress = MEM_SIZE - adress;
      reg[0] = (vm->mem[adress % MEM_SIZE] >> 24) & 0xFF;
      reg[1] = (vm->mem[adress % MEM_SIZE] >> 16) & 0xFF;
      reg[2] = (vm->mem[adress % MEM_SIZE] >> 8) & 0xFF;
      reg[3] = (vm->mem[adress % MEM_SIZE]) & 0xFF;
    }
  if ((((*lproc)->cmd[0] >> 6) & 0x03) == 3)
    {
      adress = get_direct_reg(vm, lproc, i);
      reg[0] = (adress << 24) & 0xFF;
      reg[1] = (adress << 16) & 0xFF;
      reg[2] = (adress << 8) & 0xFF;
      reg[3] = (adress) & 0xFF;
      *i = 3;
    }
}

int		calc_offset(t_proc **lproc, int *i, int param)
{
  int		offset;

  offset = 0;
  if ((*lproc)->cmd[*i] - 1 < 0)
    (*lproc)->cmd[*i] = 0;
  if ((*lproc)->cmd[*i + 1] - 1 < 0)
    (*lproc)->cmd[*i + 1] = 0;
  if (((((*lproc)->cmd[0] & 0xFF) >> param) & 0x03) == 1)
    {
      offset = (*lproc)->reg[(int)(((*lproc)->cmd[*i] - 1) &
				   0xFF) % REG_NUMBER];
      ++(*i);
    }
  else if (((((*lproc)->cmd[0] & 0xFF) >> param) & 0x3) == 2 ||
	   ((((*lproc)->cmd[0] & 0xFF) >> param) & 0x3) == 3)
    {
      offset = ((((*lproc)->cmd[*i] & 0xFF) << 8)) +
	((((*lproc)->cmd[*i + 1]) & 0xFF));
      *i += 2;
    }
  return (offset);
}

void		op_sti(t_vm *vm, t_proc **lproc)
{
  int		i;
  char		reg[4];
  int		offset;

  offset = 0;
  i = 2;
  debug(vm, lproc);
  init_tab(reg);
  load_reg(vm, lproc, reg, &i);
  offset += calc_offset(lproc, &i, 4);
  fflush(stdout);
  offset += calc_offset(lproc, &i, 2);
  fflush(stdout);
  if (offset < 0)
    offset = (MEM_SIZE) - offset;
  if ((*lproc)->pc + offset < 0)
    (*lproc)->pc = MEM_SIZE - (*lproc)->pc;
  vm->mem[((*lproc)->pc + offset) % MEM_SIZE] = reg[0];
  vm->mem[((*lproc)->pc + (offset + 1)) % MEM_SIZE] = reg[1];
  vm->mem[((*lproc)->pc + (offset + 2)) % MEM_SIZE] = reg[2];
  vm->mem[((*lproc)->pc + (offset + 3)) % MEM_SIZE] = reg[3];
  (*lproc)->pc += interval_memory((*lproc)->cmd, (*lproc)->code, 0, 0);
}
