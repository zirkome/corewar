/*
** vm_utils.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Tue Jan 29 04:05:43 2013 guillaume fillon
** Last update Wed Jan 30 17:35:30 2013 guillaume fillon
*/

#include "lib.h"
#include "vm.h"
#include "couleur.h"

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
      	printf("\n%s", REZ);
      if (vm->mem[i])
      	printf(" %s%s%s%02X", VERT, INVERSE, INTENSITE, vm->mem[i] & 0xFF);
      else
      	printf("%s %02X", REZ, vm->mem[i] & 0xFF);
      i = i + 1;
    }
  printf("%s", REZ);
  fflush(stdout);
}

int	calc_interval(int prg_nb, int total_size)
{
  int	interval;

  if (total_size > MEM_SIZE)
    my_error("Can’t perform malloc\n", 1);
  if (total_size == MEM_SIZE || prg_nb == 0)
    return (0);
  interval = (MEM_SIZE - total_size) / prg_nb;
  if (prg_nb == 2)
    interval = (MEM_SIZE - total_size);
#ifdef DEBUG
  printf("Intervalle de mémoire calculer à %d octets\n", interval);
#endif
  return (interval);
}

void		init_reg(int *buf, int cid)
{
  int		i;

  i = 0;
  while (i < 16)
    {
      buf[i++] = 0;
    }
  buf[0] = cid;
}
