/*
** parseur.c for parseur in /home/remi/Projet/corewar/corewar
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sat Jan 26 10:54:25 2013 remi robert
** Last update Mon Jan 28 14:52:40 2013 guillaume fillon
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

/*
** Passez le processus en paramétre la memoire et remplacer i par le Pc du processus.
** enlever la boucle while.
** Si ne rentre pas dans le if alors commande invalide et incrémentation du pc de 1
*/

void	parser(t_vm *vm)
{
  int	i;
  char	*buf;
  int	indice;

  i = 0;
  while (i < MEM_SIZE)
    {
      if ((vm->mem[i] & 0xFF) != 0 && (vm->mem[i] & 0xFF) < 16)
	{
	  indice = 0;
	  printf("{%s => %X} => ",
		 op_tab[(vm->mem[i] & 0xFF) - 1].mnemonique, (vm->mem[i] & 0xFF));
	  buf = return_param(vm->mem, &i, return_interval_param(vm->mem, i, 0, 0));
	  indice = 0;
	  while (indice != 16)
	    {
	      printf("[%X]", buf[indice] & 0xFF);
	      indice = indice + 1;
	    }
	  i = i + interval + 1;
	}
      /* Circularité de la mémoire */
      if (i + 1 <= MEM_SIZE)
	i = i + 1;
      else
	i = 0;
    }
  printf("\n");
}
