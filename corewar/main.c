/*
** main.c for main$ in /home/robert_r//Corewar/Corewar/vm
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Jan 21 18:27:28 2013 remi robert
** Last update Sun Jan 27 21:06:50 2013 guillaume fillon
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
  t_proc	*l_proc;
  header_t	*header;
  int		i;

  if (argc == 1 || argc > 5)
    display_usage();
  i = 1;
  l_proc = create_list();
  header = NULL;
  while (i < argc)
    {
      if ((header = realloc(header, sizeof(*header) * i)) == NULL)
	return (0);
      open_file_champion(argv[i], &header[i - 1]);
#ifdef DEBUG
      printf("HEADER CHAMPION N°%d\n", i);
      printf("MAGIC_CODE : 0x%X\n", header[i - 1].magic);
      printf("NAME : %s\n", header[i - 1].prog_name);
      printf("SIZE : %d octets\n", header[i - 1].prog_size);
      printf("COMMENT : %s\n\n", header[i - 1].comment);
#endif
      i = i + 1;
    }
  init_vm(l_proc, header, argv, argc - 1);
  free_proc(l_proc);
  free_champ(header, argc - 1);
  char buf[1];
  while(read(0, buf, 1) > 0);
  putchar('\n');
  return (0);
}
