/*
** init_vm.c for init_vm in /home/remi/Projet/corewar/corewar
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Thu Jan 24 23:12:01 2013 remi
** Last update Thu Jan 24 23:25:52 2013 remi
*/

#include "lib.h"
#include "vm.h"
#include "op.h"

int	inti_vm(int nb_elem, char **argv, header_t *header)
{
  int	i;
  int	mem_temp;

  i = -1;
  mem_temp = 0;
  while (i++ != nb_elem)
    mem_temp = mem_temp + header[i]->mem_size;
  if (mem_temp > MEM_SIZE)
    my_error("Unsifisant memory\n", 1);
  return (0);
}
