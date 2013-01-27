/*
** init_vm.c for init_vm in /home/remi/Projet/corewar/corewar
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Thu Jan 24 23:12:01 2013 remi
** Last update Sun Jan 27 01:15:52 2013 guillaume fillon
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
  while (vm->mem != NULL && i < MEM_SIZE)
    {
      if (i % 64 == 0)
	printf("%s", "\n");
      printf("%02X ", vm->mem[i] & 0xFF);
      i = i + 1;
    }
  printf("%s", "\n\n");
}

int	fill_mem(char *file, t_vm **vm, header_t *header, int pos_mem)
{
  char	*buf;
  int	size;
  int	pos_buf;

  buf = get_champ(file, &size);
  if (size != header->prog_size)
    my_error("Error number instruction\n", 1);
  size = size + pos_mem;
  pos_buf = 0;
  while (pos_mem < size)
    {
      (*vm)->mem[pos_mem] = buf[pos_buf];
      pos_mem = pos_mem + 1;
      pos_buf = pos_buf + 1;
    }
  return (pos_mem);
}

int	calc_interval(int nb_chp, int total_size)
{
  int	interval;

  if (total_size > MEM_SIZE)
    my_error("Can’t perform malloc\n", 1);
  if (total_size == MEM_SIZE || nb_chp == 0)
    return (0);
  interval = (MEM_SIZE - total_size) / nb_chp;
  if (nb_chp == 2)
    interval = (MEM_SIZE - total_size);
#ifdef DEBUG
  printf("Intervalle de mémoire calculer à %d octets\n", interval);
#endif
  return (interval);
}

int		init_vm(t_proc *l_proc, header_t *header, char **av, int nb_ch)
{
  t_vm		*vm;
  int		i;
  int		mem_temp;
  int		interval;
  int		pos_mem;

  i = 0;
  mem_temp = 0;
  while (i < nb_ch)
    mem_temp += header[i++].prog_size;
  if (mem_temp > MEM_SIZE || (vm = malloc(sizeof(t_vm))) == NULL)
    my_error("File is too big.\n", 1);
  if ((vm->mem = malloc(sizeof(char) * MEM_SIZE)) == NULL)
    my_error("Can’t perform malloc\n", 1);
  reset_mem(&vm);
  i = 0;
  pos_mem = 0;
  interval = calc_interval(nb_ch, mem_temp);
  while (i < nb_ch)
    {
      queue(l_proc, pos_mem, i + 1);
      pos_mem = fill_mem(av[i + 1], &vm, &header[i], pos_mem) + interval;
      i = i + 1;
    }
#ifdef DEBUG
  dump_memory(vm);
  printf("%s","VM initialiser avec succès !\n");
#endif
  parser(vm);
  return (0);
}
