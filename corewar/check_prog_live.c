/*
** check_prog_live.c for check_prog_live in /home/remi/Projet/corewar/corewar/corewar
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Mon Mar 11 08:18:24 2013 remi
** Last update Mon Mar 11 14:56:15 2013 remi
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

  indice = 0;
  while (indice < (*vm)->prg_nb)
    {
      if (live[indice] == 0)
	{
	  printf("%schampion : [%d] mort !!%s\n", ROUGE, indice + 1, REZ);
	  while (free_elem_prog(&((*vm)->proc), indice + 1) == 1);
	}
      indice = indice + 1;
    }
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
      if (live[cur_proc->reg[0] - 1] != 1)
	live[cur_proc->reg[0] - 1] = cur_proc->live;
      cur_proc = cur_proc->next;
    }
  gere_prog_live(live, vm);
  if (live[0] != 1 && live[1] != 1 &&
      live[2] != 1 && live[3] != 1)
    {
      printf("%splus de champion en vie%s\n", JAUNE, REZ);
      return (0);
    }
  return (1);
}
