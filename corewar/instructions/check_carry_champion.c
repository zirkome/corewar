/*
** check_carry_champion.c for check_carry in /home/remi/Projet/save_projet/corewar/corewar/instructions
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Wed Mar 20 09:21:26 2013 remi
** Last update Wed Mar 20 09:29:33 2013 remi
*/

#include "lib.h"
#include "vm.h"

int		check_carry_champion(t_proc *ptete, int num_champion)
{
  t_proc	*pcourant;

  if (ptete == NULL)
    return (0);
  pcourant = ptete;
  while (pcourant != NULL)
    {
      if (pcourant->reg[0] == num_champion &&
	  pcourant->carry == 1)
	return (1);
      pcourant = pcourant->next;
    }
  return (0);
}
