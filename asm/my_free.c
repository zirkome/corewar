/*
** my_free.c<2> for my_free in /home/linard_f//corewar/homework/asm/corewar
**
** Made by fabien linardon
** Login   <linard_f@epitech.net>
**
** Started on  Thu Jan 24 11:23:32 2013 fabien linardon
** Last update Wed Mar 13 14:54:50 2013 nicolas bridoux
*/

#include "asm.h"

/*
** Fonction pour free une liste
*/ 

void		my_free_list(t_list *list)
{
  t_list	*tmp;
  t_list	*cpy;

  tmp = list;
  while (tmp != NULL)
    {
      cpy = tmp;
      tmp = tmp->next;
      free(cpy->name);
      free(cpy);
    }
}

/*
** Fonction pour free un char **
*/

void	my_free_tab(char **tab)
{
  int	rk;

  rk = - 1;
  while (tab[++rk])
    free(tab[rk]);
  free(tab);
}
