/*
** set_carry.c for set_carry in /home/remi/Projet/save_projet/corewar/corewar
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Tue Mar 12 13:57:31 2013 remi
** Last update Tue Mar 12 14:01:29 2013 remi
*/

#include "vm.h"

void	set_carry(t_proc **lproc, int val)
{
  if (val == 0)
    {
      if ((*lproc)->carry == 0)
	{
	  printf("%scarry = 1%s\n", CYAN, REZ);
	  (*lproc)->carry = 1;
	}
      else
	(*lproc)->carry = 0;
    }
}
