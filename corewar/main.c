/*
** main.c for main$ in /home/robert_r//Corewar/Corewar/vm
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Jan 21 18:27:28 2013 remi robert
** Last update Tue Jan 22 23:03:03 2013 guillaume fillon
*/

#include "lib.h"
#include "vm.h"

void		display_usage()
{
  my_error("Usage : ./corewar [-comment] [-dump nbr_cycle] ", 0);
  my_error("[[-n prog_number] [-a load_address ] prog_name] ...\n", 1);
}

int		main(int argc, char **argv)
{
  t_champion	*champion1;

  if (argc == 1)
    display_usage();
  if ((champion1 = malloc(sizeof(t_champion))) == NULL)
    return (0);
  open_file_champion(argv[1], champion1);
  return (0);
}
