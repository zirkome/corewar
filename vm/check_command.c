/*
** check_command.c for check_command in /home/robert_r//Corewar/Corewar/vm
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Tue Jan 22 12:49:47 2013 remi robert
** Last update Tue Jan 22 13:40:02 2013 remi robert
*/

#include "vm.h"
#include "lib.h"

int	detect_fonction(int number)
{
  char	*command[16];

  if (number > 15)
    return (0);
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
  printf("%s\n", command[number]);
  return (0);
}
