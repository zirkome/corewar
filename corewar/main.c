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
#include "op.h"

void	init_vm(t_vm **vm)
{
  int	i;

  i = 0;
  if ((((*vm) = malloc(sizeof(t_vm))) == NULL) ||
      ((*vm)->mem = malloc(sizeof(mem_t) * MEM_SIZE)) == NULL)
    my_error("Error malloc\n", 1);
  while (i++ < MEM_SIZE)
    (*vm)->mem[i - 1] = 0;
  (*vm)->size_rempl = 0;
}

void	fill_mem(t_vm **vm, t_champion *champion)
{
  int	i;

  if ((*vm)->mem[0] == 0)
    i = 0;
  if ((*vm)->mem[MEM_SIZE / 4] == 0)
    i = MEM_SIZE / 4;
  if ((*vm)->mem[MEM_SIZE / 2] == 0)
    i = MEM_SIZE / 2;
  if (MEM_SIZE - (*vm)->size_rempl < champion->nb_cmd)
    my_error("Error memory\n", 1);
  while (i++ < champion->nb_cmd)
    (*vm)->mem[i - 1] = 
      champion->file[i -1 + (champion->nb_carac - champion->nb_cmd)] & 0xFF;
  (*vm)->size_rempl = i;
}

void		display_usage()
{
  my_error("Usage : ./corewar [-comment] [-dump nbr_cycle] ", 0);
  my_error("[[-n prog_number] [-a load_address ] prog_name] ...\n", 1);
}

int		main(int argc, char **argv)
{
  t_champion	*champion1;
  t_vm		*vm;

  if (argc == 1)
    display_usage();
  if ((champion1 = malloc(sizeof(t_champion))) == NULL)
    return (0);
  open_file_champion(argv[1], champion1);
  init_vm(&vm);
  rempl_mem(&vm, champion1);
  print_file(champion1->file, champion1);
  print_memory(vm);
  return (0);
}
