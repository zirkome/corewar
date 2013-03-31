/*
** debug.c for debug in /home/remi/Projet/save_projet/corewar/corewar
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Thu Mar 28 17:05:43 2013 remi
** Last update Sun Mar 31 15:36:00 2013 remi
*/

#include "lib.h"
#include "vm.h"

void	print_debug(int value, char *str, int type)
{
  my_putstr(" ");
  if (str != NULL)
    my_putstr(str);
  if (type == 1)
    {
      my_putstr(ROUGE);
      my_putstr(" [@ ");
      my_put_nbr(value);
      my_putstr("]");
      my_putstr(REZ);
    }
  else
    {
      my_putstr(" ");
      my_put_nbr(value);
    }
}

/*
** affiche des informations complémentaires.
** pour activer cette option = -v
*/
void	debug(t_vm *vm, t_proc **lproc)
{
  if (vm->option[0].debug != 1)
    return ;
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
}
