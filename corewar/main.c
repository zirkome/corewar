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
    my_error("Error MEM_SIZE vm is to small\n", 1);
  if (REG_NUMBER <= 0)
    my_error("Error there are 0 or less, instructions on the vm\n" , 1);
  if (REG_SIZE <= 0)
    my_error("Error not egal 4\n" , 1);
  return (1);
}

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

t_prog		*get_arg_parsing(int argc, char **av)
{
  t_prog	*tab;

  if ((tab = malloc(4 * sizeof(t_prog))) == NULL)
    return (NULL);
  initialize_tab(tab);
  if (parsing_param(&av[1], tab, 0) == -1 ||
      tab[0].prog_name == NULL)
    display_usage();
  return (tab);
}

int		main(int argc, char **argv, char **envp)
{
  t_proc	*lproc;
  SDL_Event	event;
  header_t	*header;
  int		i;
  t_prog	*tab;

  if (argc == 1 || check_value_vm() == 0 ||
      (tab = get_arg_parsing(argc, argv)) == NULL)
    display_usage();
  if (!check_display(envp))
    my_error("$DISPLAY is not set appropriately. "	\
	     "Can't open display, sorry. Abort.\n", 1);
  i = 0;
  lproc = NULL;
  header = NULL;
  while (i < 4 && tab[i].prog_name != NULL)
    {
      if ((header = realloc(header, sizeof(*header) * (i + 1))) == NULL)
      	return (EXIT_FAILURE);
      open_file_champion(tab[i].prog_name, &header[i]);
      i = i + 1;
    }
  launch_vm(lproc, header, tab, i);
  handle_event2(&event);
  return (EXIT_SUCCESS);
}
