/*
** vm_utils.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Tue Jan 29 04:05:43 2013 guillaume fillon
** Last update Sun Mar 31 17:46:47 2013 remi
*/

#include "lib.h"
#include "vm.h"
#include "couleur.h"

/*
** initialise les premiers processus wait de 1,
** comme sur la vm de test pour commencer à parser
** dés le premier tour.
*/
void		init_cmd_proc(t_vm *vm)
{
  t_proc	*pcourant;

  if (vm == NULL || vm->proc == NULL)
    return ;
  pcourant = vm->proc;
  while (pcourant != NULL)
    {
      parser(vm, pcourant, 0);
      pcourant->wait = 1;
      pcourant = pcourant->next;
    }
}

void	print_value_memeory(char value)
{
  my_putstr(VERT);
  my_putstr(INTENSITE);
  my_putstr(INVERSE);
  if ((value & 0xFF) < 10)
    my_putstr("0");
  my_put_nbr(value & 0xFF);
  my_putstr(REZ);
  my_putstr(" ");
}

/*
** Dump memory => affiche la mémoire
*/
void	dump_memory(t_vm *vm)
{
  int	i;

  i = 0;
  while (vm->mem != NULL && i < MEM_SIZE)
    {
      if (i % 64 == 0)
	{
	  my_putstr("\n");
	  my_putstr(REZ);
	}
      if (vm->mem[i % MEM_SIZE])
	print_value_memeory(vm->mem[i % MEM_SIZE]);
      else
	my_putstr(" 00");
      i = i + 1;
    }
  my_putstr("\n");
}

/*
** calcul de l' interval entre les champions dans la memoire
*/
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
  return (interval);
}

/*
** initialise les registre de chaque proc
*/
void	init_reg(int *buf, int cid)
{
  int	i;

  i = 0;
  while (i < REG_NUMBER)
    buf[i++] = 0;
  buf[0] = cid;
}
