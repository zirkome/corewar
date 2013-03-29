/*
** debug.c for debug in /home/remi/Projet/save_projet/corewar/corewar
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Thu Mar 28 17:05:43 2013 remi
** Last update Fri Mar 29 09:56:39 2013 remi
*/

#include "lib.h"
#include "vm.h"

void	debug(t_vm *vm, t_proc ** lproc)
{
  my_putstr(INTENSITE);
  my_putstr("[wait : ");
  my_put_nbr(vm->cycle_champion[(*lproc)->nb_proc % 4]);
  my_putstr("] ");
  my_putstr("[cycle : ");
  my_put_nbr(vm->cycle);
  my_putstr("] ");
  my_putstr(BLEU);
  my_putstr("[N°proc : ");
  my_put_nbr((*lproc)->num_proc + 1);
  my_putstr("] ");
  my_putstr(CYAN);
  my_putstr("[Champion ");
  my_put_nbr((*lproc)->nb_proc + 1);
  my_putstr("] ");
  my_putstr(REZ);
  my_putstr(op_tab[((*lproc)->code - 1) % REG_NUMBER].mnemonique);
  my_putstr("\n");
}
