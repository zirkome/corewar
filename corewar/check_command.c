/*
** check_command.c for check_command in /home/robert_r//Corewar/Corewar/vm
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Tue Jan 22 12:49:47 2013 remi robert
** Last update Tue Jan 22 14:48:49 2013 remi robert
*/

#include "vm.h"
#include "lib.h"
#include "couleur.h"

int	return_number_param(int number)
{
  char	tab[16];

  tab[0] = 1;
  tab[1] = 2;
  tab[2] = 2;
  tab[3] = 3;
  tab[4] = 3;
  tab[5] = 3;
  tab[6] = 3;
  tab[7] = 3;
  tab[8] = 1;
  tab[9] = 3;
  tab[10] = 3;
  tab[11] = 1;
  tab[12] = 2;
  tab[13] = 3;
  tab[14] = 1;
  tab[15] = 1;
  return (tab[number]);
}

int	dectect_param(int number, char *tab)
{
  int	i;

  i = 0;
  while (i <= return_number_param(number))
    {
      printf(" %X ", tab[i]);
      i = i + 1;
    }
  return (i);
}

int	detect_fonction(int number, char *tab, int n)
{
  char	*command[16];

  command[0] = "live";
  command[1] = "ld";
  command[2] = "st";
  command[3] = "add";
  command[4] = "sub";
  command[5] = "and";
  command[6] = "or";
  command[7] = "xor";
  command[8] = "zjump";
  command[9] = "ldi";
  command[10] = "sti";
  command[11] = "fork";
  command[12] = "lld";
  command[13] = "lldi";
  command[14] = "lfork";
  command[15] = "aff";
  printf("\n%s%s%s%s -> ", INTENSITE, ROUGE, command[n], REZ);
  //return (dectect_param(number + 1, tab));
  return (1);
}
