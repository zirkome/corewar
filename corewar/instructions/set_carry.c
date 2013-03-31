/*
** set_carry.c for set_carry in /home/remi/Projet/save_projet/corewar/corewar
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Tue Mar 12 13:57:31 2013 remi
** Last update Wed Mar 20 10:26:12 2013 remi
*/

#include "vm.h"

void	set_carry(t_proc **lproc, int val)
{
  if (val == 0)
    {
      printf("%s%s%scarry = 1%s\n", INTENSITE, F_ROUGE, BLANC, REZ);
      (*lproc)->carry = 1;
    }
  else
    {
      printf("%s%s%scarry = 0%s\n", INTENSITE, F_ROUGE, BLANC, REZ);
      (*lproc)->carry = 0;
    }
}
