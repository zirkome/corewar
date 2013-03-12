/*
** check_prog_live.c for check_prog_live in /home/remi/Projet/corewar/corewar/corewar
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Mon Mar 11 08:18:24 2013 remi
** Last update Tue Mar 12 22:35:54 2013 remi
*/

#include "lib.h"
#include "vm.h"
#include "couleur.h"
#include "instructions/instruction.h"

void	init_tab_live(char *tab)
{
  tab[0] = -1;
  tab[1] = -1;
  tab[2] = -1;
  tab[3] = -1;
}

void		gere_prog_live(char *live, t_vm **vm)
{
  int		indice;
  int		suppr;

  indice = 0;
  suppr = 0;
  while (indice < (*vm)->prg_nb)
    {
      if (live[indice] == 0)
	{
	  suppr = suppr + 1;
	  printf("%schampion : [%d] mort !!%s\n", ROUGE, indice + 1, REZ);
	  while (free_elem_prog(&((*vm)->proc), indice + 1) == 1);
	}
      indice = indice + 1;
    }
  (*vm)->prg_nb = (*vm)->prg_nb - suppr;
}

int		there_is_last_champ(char *live)
{
  int		i;
  int		count;

  count = 0;
  i = 0;
  while (i < 4)
    {
      if (live[i] > 0)
	++count;
      ++i;
    }
  if (count == 1)
    {
      count = 0;
      i = 0;
      while (i < 4)
	{
	  if (live[i] > 0)
	    count = i;
	  ++i;
	}
      printf("Champion %d a gagne !\n", count + 1);
      return (1);
    }
  if (count == 0)
    return (1);
  return (0);
}

int		check_prg_live(t_vm **vm)
{
  t_proc	*cur_proc;
  char		live[4];

  init_tab_live(live);
  if ((*vm)->proc == NULL)
    return (0);
  cur_proc = (*vm)->proc;
  while (cur_proc != NULL)
    {
      if  ((cur_proc->reg[0] - 1) < 4 && (cur_proc->reg[0] - 1) >= 0)
	{
	  if (cur_proc->live == 1)
	    live[cur_proc->reg[0] - 1] = cur_proc->live;
	}
      cur_proc = cur_proc->next;
    }
  gere_prog_live(live, vm);
  if (there_is_last_champ(live))
    return (0);
  printf ("%sRETURN 1%s\n", F_ROUGE, REZ);
  return (1);
}
