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
