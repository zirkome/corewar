/*
** set_carry.c for set_carry in /home/remi/Projet/save_projet/corewar/corewar
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Tue Mar 12 13:57:31 2013 remi
** Last update Sun Mar 31 03:30:57 2013 guillaume fillon
*/

#include "vm.h"

void	set_carry(t_proc **lproc, int val)
{
  if (val == 0)
    {
      my_putstr(ROUGE);
      my_putstr("carry = 1\n");
      my_putstr(REZ);
      (*lproc)->carry = 1;
    }
  else
    (*lproc)->carry = 0;
}
