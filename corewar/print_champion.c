/*
** print_champion.c for print_champion in /home/remi/Projet/save_projet/corewar/corewar
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Thu Mar 28 23:32:23 2013 remi
** Last update Sun Mar 31 17:44:15 2013 remi
*/

#include "vm.h"
#include "lib.h"

void	print_champion(int count, t_vm *vm)
{
  my_putstr("\n\n");
  my_putstr(vm->header[count % 4].prog_name);
  my_putstr(" ");
  my_putstr(BLEU);
  my_putstr(INTENSITE);
  my_putstr(vm->header[count % 4].comment);
  my_putstr(REZ);
  my_putstr("  a gagne !\n");
  my_putstr("\n");
}
