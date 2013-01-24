/*
** main.c for main$ in /home/robert_r//Corewar/Corewar/vm
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Jan 21 18:27:28 2013 remi robert
** Last update Thu Jan 24 23:55:21 2013 remi
*/

#include "lib.h"
#include "vm.h"
#include "op.h"

void		display_usage()
{
  my_error("Usage : ./corewar [-comment] [-dump nbr_cycle] ", 0);
  my_error("[[-n prog_number] [-a load_address ] prog_name] ...\n", 1);
}

int		main(int argc, char **argv)
{
  header_t	*header;
  int		i;

  if (argc == 1 || argc > 4)
    display_usage();
  i = 1;
  header = NULL;
  while (i < argc)
    {
      if ((header = realloc(header, sizeof(header_t) * i)) == NULL)
	return (0);
      open_file_champion(argv[i], &header[i - 1]);
      i = i + 1;
    }
  return (0);
}
