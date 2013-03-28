/*
** debug.c for debug in /home/remi/Projet/save_projet/corewar/corewar
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Thu Mar 28 17:05:43 2013 remi
** Last update Thu Mar 28 17:38:50 2013 remi
*/

#include "lib.h"
#include "vm.h"

void	debug(t_vm *vm, t_proc ** lproc)
{
  my_putstr("[");
  my_put_nbr((*lproc)->nb_proc);
  my_putstr("] ");
  my_putstr("[");
  my_put_nbr((*lproc)->num_proc);
  my_putstr("] ");
  my_putstr(op_tab[((*lproc)->code - 1) % REG_NUMBER].mnemonique);
  my_putstr("\n");
}
