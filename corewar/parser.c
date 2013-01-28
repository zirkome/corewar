/*
** parseur.c for parseur in /home/remi/Projet/corewar/corewar
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sat Jan 26 10:54:25 2013 remi robert
** Last update Mon Jan 28 21:33:38 2013 remi robert
*/

#include "lib.h"
#include "vm.h"
#include "op.h"

void	return_tab(int instruction, char *tab)
{
  if (instruction == 0x03 || instruction == 0x0A || instruction == 0x04 ||
      instruction == 0x05 || instruction == 0x10)
    tab[0] = 1;
  if (instruction == 0x09 || instruction == 0x0C || instruction == 0x0F)
    tab[0] = 3;
  if (instruction == 0x02 || instruction == 0x0A || instruction == 0x0D ||
      instruction == 0x0E || instruction == 0x04 || instruction == 0x05)
    tab[1] = 1;
  if (instruction == 0x06 || instruction == 0x07 || instruction == 0x08 ||
      instruction == 0x04 || instruction == 0x05)
    tab[2] = 1;
 }

char	*return_param(char *mem, int *i, int interval)
{
  char	*param;
  int	size;
  int	indice_tab;

  size = *i + interval;
  if ((param = malloc(sizeof(char) * 17)) == NULL)
    return (NULL);
  indice_tab = 0;
  while (*i <= size)
    {
      param[indice_tab] = mem[*i + 1];
      *i = *i + 1;
      indice_tab = indice_tab + 1;
    }
  while (indice_tab < 17)
    {
      param[indice_tab] = 0x0;
      indice_tab = indice_tab + 1;
    }
  return (param);
}

int	return_interval_param(char *mem, int i, int interval, int indice)
{
  char	tab[4];
  char	size[3];

  size[0] = 1;
  size[1] = DIR_SIZE;
  size[2] = IND_SIZE;
  tab[0] = ((mem[i + 1]) >> 6) & 0x3;
  tab[1] = ((mem[i + 1]) >> 4) & 0x3;
  tab[2] = ((mem[i + 1]) >> 2) & 0x3;
  tab[3] = ((mem[i + 1])) & 0x3;
  return_tab(mem[i], tab);
  if (((mem[i] & 0xFF) - 1) == 10)
    size[1] = 2;
  while (indice < 4)
    {
      if (tab[indice] != 0)
	interval = interval + size[(int)tab[indice] - 1];
      indice = indice + 1;
    }
  if ((mem[i] & 0xFF) == 0x01)
    interval = 3;
  if (((mem[i] & 0xFF) - 1) == 8)
    interval = 1;
  if (interval + i > MEM_SIZE)
    interval = MEM_SIZE - i;
  return (interval);
}

void	rempl_param(t_proc *lproc, char *buf)
{
  int	i;

  i = 0;
  while (i < 17)
    {
      lproc->param[i] = buf[i];
      i = i + 1;
    }
}

/*
** Prend le processus en paramétre la memoire et remplace i par le Pc du processus.
** enlever la boucle while.
** Si ne rentre pas dans le if alors commande invalide et incrémentation du pc de 1
*/

void	parser(t_vm *vm, t_proc *lproc)
{
  char	*buf;

  if ((vm->mem[lproc->pc] & 0xFF) >= 0x01 && (vm->mem[lproc->pc] & 0xFF) <= 0x10)
    {
      lproc->instruction = (vm->mem[lproc->pc] & 0xFF);
#ifdef DEBUG
      printf("{%s => %X} => ",
	     op_tab[(vm->mem[lproc->pc] & 0xFF) - 1].mnemonique, (vm->mem[lproc->pc] & 0xFF));
#endif
      buf = return_param(vm->mem, &(lproc->pc), return_interval_param(vm->mem, lproc->pc, 0, 0));
      rempl_param(lproc, buf);
      printf("\n");
    }
  lproc->pc = (lproc->pc + 1) % (MEM_SIZE + 1);
  printf("\n");
}
