/*
** get_sti.c for get_sti in /home/remi/Projet/save_projet/corewar/corewar/instructions
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Thu Mar 28 16:02:20 2013 remi
** Last update Fri Mar 29 08:58:54 2013 remi
*/

#include "lib.h"
#include "vm.h"

int	get_adress_reg(t_vm *vm, t_proc **lproc, int *i)
{
  *i = 3;
  return ((((*lproc)->reg[((int)((*lproc)->cmd[1] - 1) %
			   REG_NUMBER)] >> 8) & 0xFF) |
	  (((*lproc)->reg[((int)((*lproc)->cmd[2] - 1) %
			   REG_NUMBER)]) & 0xFF));
}

int	get_direct_reg(t_vm *vm, t_proc **lproc, int *i)
{
  *i = 5;
  return ((((*lproc)->reg[((int)((*lproc)->cmd[1] - 1) %
			   REG_NUMBER)] >> 24) & 0xFF) |
	  (((*lproc)->reg[((int)((*lproc)->cmd[2] - 1) %
			   REG_NUMBER)] >> 16) & 0xFF) |
	  (((*lproc)->reg[((int)((*lproc)->cmd[3] - 1) %
			   REG_NUMBER)] >> 8) & 0xFF) |
	  (((*lproc)->reg[((int)((*lproc)->cmd[4] - 1) %
			   REG_NUMBER)]) & 0xFF));
}

void	get_reg_reg(t_vm *vm, t_proc **lproc, int *i, char *reg)
{
  *i = 2;
  reg[0] = ((*lproc)->reg[((int)(*lproc)->cmd[1] - 1) %
			  REG_NUMBER] >> 24) & 0xFF;
  reg[1] = ((*lproc)->reg[((int)(*lproc)->cmd[1] - 1) %
			  REG_NUMBER] >> 16) & 0xFF;
  reg[2] = ((*lproc)->reg[((int)(*lproc)->cmd[1] - 1) %
			  REG_NUMBER] >> 8) & 0xFF;
  reg[3] = ((*lproc)->reg[((int)(*lproc)->cmd[1] - 1) %
			  REG_NUMBER]) & 0xFF;
}
