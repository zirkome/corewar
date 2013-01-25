/*
** main.c for main$ in /home/robert_r//Corewar/Corewar/vm
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Jan 21 18:27:28 2013 remi robert
** Last update Fri Jan 25 14:09:10 2013 remi robert
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

  if (argc == 1 || argc > 5)
    display_usage();
  i = 1;
  header = NULL;
  while (i < argc)
    {
      if ((header = realloc(header, sizeof(header_t) * i)) == NULL)
	return (0);
      open_file_champion(argv[i], &header[i - 1]);
      printf("HEADER CHAMPION N°%d\n", i);
      printf("MAGIC_CODE : 0x%X\n", header[i - 1].magic);
      printf("NAME : %s\n", header[i - 1].prog_name);
      printf("SIZE : %d octets\n", header[i - 1].prog_size);
      printf("COMMENT : %s\n\n", header[i - 1].comment);
      i = i + 1;
    }
  init_vm(i - 1, argv, header);
  return (0);
}
