/*
** set_carry.c for set_carry in /home/remi/Projet/save_projet/corewar/corewar
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Tue Mar 12 13:57:31 2013 remi
** Last update Sat Mar 30 14:21:24 2013 remi
*/

#include "vm.h"

/*
** met le carry à 0 ou a 1 suivant la valeur passé.
** si val == 0 alors carry = 1;
*/
void	set_carry(t_proc **lproc, int val)
{
  if (val == 0)
    {
      my_putstr("\n");
      my_putstr(F_ROUGE);
      my_putstr("carry = 1");
      my_putstr(REZ);
      (*lproc)->carry = 1;
    }
  else
    (*lproc)->carry = 0;
}
