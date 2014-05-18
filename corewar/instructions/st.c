/*
** st.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:27:36 2013 guillaume fillon
** Last update Sun Mar 31 18:03:45 2013 guillaume fillon
*/

#include "lib.h"
#include "vm.h"

void	load_reg_st(t_proc **lproc, char *reg)
{
  if ((*lproc)->cmd[1] - 1 < 0)
    (*lproc)->cmd[1] = 1;
  reg[0] = ((*lproc)->reg[((int)(*lproc)->cmd[1] - 1) %
			  REG_NUMBER] >> 24) & 0xFF;
  reg[1] = ((*lproc)->reg[((int)(*lproc)->cmd[1] - 1) %
			  REG_NUMBER] >> 16) & 0xFF;
  reg[2] = ((*lproc)->reg[((int)(*lproc)->cmd[1] - 1) %
			  REG_NUMBER] >> 8) & 0xFF;
  reg[3] = ((*lproc)->reg[((int)(*lproc)->cmd[1] - 1) %
			  REG_NUMBER]) & 0xFF;
}

void	get_address_st(t_vm *vm, t_proc **lproc, int *address)
{
  if ((((*lproc)->cmd[0] >> 4) & 0x03) == 1)
    *address = (*lproc)->cmd[2];
  if ((((*lproc)->cmd[0] >> 4) & 0x03) == 3)
    {
      *address = (((*lproc)->cmd[2] << 8) | ((*lproc)->cmd[3]) |
		 ((*lproc)->cmd[4] << 8) | ((*lproc)->cmd[5])) & 0xFFFFFFFF;
    }
  if ((((*lproc)->cmd[0] >> 4) & 0x03) == 2)
    {
      *address = (((*lproc)->cmd[2] << 8) | (*lproc)->cmd[3]) & 0xFFFF;
      if (*address < 0)
	*address = MEM_SIZE - *address;
      *address = vm->mem[((*lproc)-> pc + *address) % MEM_SIZE];
    }
}

void	store_st(t_vm *vm, char *reg, t_proc **lproc, int address)
{
  if ((((*lproc)->cmd[0] >> 4) & 0x03) == 1)
    {
      (*lproc)->reg[(address - 1) % REG_NUMBER] = (reg[0] << 24) |
	(reg[1] << 16) | (reg[2] << 8) | (reg[3]);
    }
  if ((((*lproc)->cmd[0] >> 4) & 0x03) == 2 ||
      (((*lproc)->cmd[0] >> 4) & 0x03) == 3)
    {
      if (address < 0)
	address = MEM_SIZE - address;
      vm->mem[((*lproc)->pc + address) % IDX_MOD % MEM_SIZE] = reg[0];
      vm->mem[((*lproc)->pc + (address + 1)) % IDX_MOD % MEM_SIZE] = reg[1];
      vm->mem[((*lproc)->pc + (address + 2)) % IDX_MOD % MEM_SIZE] = reg[2];
      vm->mem[((*lproc)->pc + (address + 3)) % IDX_MOD % MEM_SIZE] = reg[3];
    }
}

void		op_st(t_vm *vm, t_proc **lproc)
{
  int		address;
  char		reg[4];

  address = 0;
  reg[0] = 0;
  reg[1] = 0;
  reg[2] = 0;
  reg[3] = 0;
  address = 0;
  load_reg_st(lproc, reg);
  get_address_st(vm, lproc, &address);
  debug(vm, lproc, address);
  store_st(vm, reg, lproc, address);
  if (vm->option[0].debug != -1)
    print_debug(address, "address : ", 1);
  (*lproc)->pc += interval_memory((*lproc)->cmd, (*lproc)->code, 0, 0);
}
