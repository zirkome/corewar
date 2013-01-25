/*
** init_vm.c for init_vm in /home/remi/Projet/corewar/corewar
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Thu Jan 24 23:12:01 2013 remi
** Last update Fri Jan 25 16:39:46 2013 remi robert
*/

#include <sys/stat.h>
#include <fcntl.h>
#include "lib.h"
#include "vm.h"
#include "op.h"

void	reset_mem(t_vm **vm)
{
  int	i;

  i = 0;
  while (i < MEM_SIZE)
    (*vm)->mem[i++] = 0x0;
}

void	dump_memory(t_vm *vm)
{
  int	i;

  i = 0;
  printf("%s", "\n\n");
  while (vm->mem != NULL && i < MEM_SIZE)
    {
      printf("%0#4X ", vm->mem[i] & 0xFF);
      i = i + 1;
    }
  printf("%s", "\n\n");
}

void	fill_mem(char *file, t_vm **vm, int nb_elem, int *pos_mem)
{
  char	*buf;
  int	size;
  int	pos_buf;

  buf = return_buf_mem(file, &size);
  if (size != nb_elem)
    my_error("Error number instruction\n", 1);
  size = size + *pos_mem;
  pos_buf = 0;
  while (*pos_mem < size)
    {
      (*vm)->mem[*pos_mem] = buf[pos_buf];
      *pos_mem = *pos_mem + 1;
      pos_buf = pos_buf + 1;
    }
}

int	calc_interval(int nb_elem, int total_size)
{
  int	interval;

  if (total_size > MEM_SIZE)
    my_error("Can’t perform malloc\n", 1);
  if (total_size == MEM_SIZE || nb_elem == 0)
    return (0);
  interval = (MEM_SIZE - total_size) / nb_elem;
  if (nb_elem == 2)
    interval = (MEM_SIZE - total_size);
  return (interval);
}

int		init_vm(int nb_elem, char **argv, header_t *header)
{
  t_vm		*vm;
  int		i;
  int		mem_temp;
  int		interval;
  int		pos_mem;

  i = 0;
  mem_temp = 0;
  while (i < nb_elem)
    mem_temp += header[i++].prog_size;
  if (mem_temp > MEM_SIZE || (vm = malloc(sizeof(t_vm))) == NULL)
    my_error("Can’t perform malloc\n", 1);
  if ((vm->mem = malloc(sizeof(char) * MEM_SIZE)) == NULL)
    my_error("Can’t perform malloc\n", 1);
  reset_mem(&vm);
  i = 0;
  pos_mem = 0;
  interval = calc_interval(nb_elem, mem_temp);
  while (i < nb_elem)
    {
      fill_mem(argv[i + 1], &vm, header[i].prog_size, &pos_mem);
      pos_mem = pos_mem + interval;
      i = i + 1;
    }
  dump_memory(vm);
  return (0);
}
