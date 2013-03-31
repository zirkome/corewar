/*
** main.c for main$ in /home/robert_r//Corewar/Corewar/vm
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Jan 21 18:27:28 2013 remi robert
** Last update Fri Mar 29 18:02:51 2013 guillaume fillon
*/

#include "lib.h"
#include "vm.h"

void		display_usage()
{
  my_error("Usage : ./corewar [-comment] [-dump nbr_cycle] ", 0);
  my_error("[[-n prog_number] [-a load_address ] prog_name] ...\n", 1);
}

int	check_value_vm()
{
  if (MEM_SIZE <= 0)
    {
      my_putstr("Error MEM_SIZE vm is to small\n");
      return (0);
    }
  if (REG_NUMBER <= 0)
    {
      my_putstr("Error there are 0 or less, instructions on the vm\n");
      return (0);
    }
  if (REG_SIZE <= 0)
    {
      my_putstr("Error not egal 4\n");
      return (0);
    }
  return (1);
}

/* #ifdef DEBUG */
/*       printf("HEADER CHAMPION N°%d\n", i); */
/*       printf("MAGIC_CODE : 0x%X\n", header[i - 1].magic); */
/*       printf("NAME : %s\n", header[i - 1].prog_name); */
/*       printf("SIZE : %d octets\n", header[i - 1].prog_size); */
/*       printf("COMMENT : %s\n\n", header[i - 1].comment); */
/* #endif */

int		check_display(char **envp)
{
  int		i;

  i = 0;
  while (envp[i] != NULL)
    {
      if (my_strncmp("DISPLAY", envp[i], my_strlen("DISPLAY")) == 0)
	return (1);
      ++i;
    }
  return (0);
}

int		main(int argc, char **argv, char **envp)
{
  header_t	*header;
  int		i;

  if (argc == 1 || argc > 5 || check_value_vm() == 0)
    display_usage();
  if (!check_display(envp))
    my_error("$DISPLAY is not set appropriately. "	\
	     "Can't open display, sorry. Abort.\n", 1);
  i = 1;
  header = NULL;
  while (i < argc)
    {
      if ((header = realloc(header, sizeof(*header) * i)) == NULL)
	return (0);
      open_file_champion(argv[i], &header[i - 1]);
      i = i + 1;
    }
  launch_vm(header, argv, argc - 1);
  SDL_WaitEvent(NULL);
  return (EXIT_SUCCESS);
}
