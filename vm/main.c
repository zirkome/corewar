/*
** main.c for main$ in /home/robert_r//Corewar/Corewar/vm
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Jan 21 18:27:28 2013 remi robert
** Last update Tue Jan 22 11:32:50 2013 remi robert
*/

#include "vm.h"

int		main(int argc, char **argv)
{
  t_champion	*champion1;

  if (argc == 1)
    return (0);
  if ((champion1 = malloc(sizeof(t_champion))) == NULL)
    return (0);
  open_file(argv[1], champion1);
  return (0);
}
