/*
** main.c for main in /home/linard_f//corewar/homework/vm
**
** Made by fabien linardon
** Login   <linard_f@epitech.net>
**
** Started on  Thu Mar 21 10:26:14 2013 fabien linardon
** Last update Thu Mar 21 16:43:14 2013 guillaume fillon
*/

#include "fab.h"

/* main de test, il vous faut juste récupérer la ligne qui initialise. */
/* ne pas oublier de malloc le tableau de structure avant de l'envoyer. */

int		main(int ac, char **av)
{
  t_prog	*tab;
  int		rk;

  rk = -1;
  if (ac < 3)
    return (EXIT_FAILURE);
  tab = malloc(4 * sizeof(t_prog)); /* ne pas oublier de check le malloc quand mm ;) */

  initialize_tab(tab); /* <= injecter cette ligne dans votre code */

  printf("dump = [%d]\n", parcing_param(&av[1], tab));
  while (tab[++rk].prog_name)
    printf("tab[%d] ; name = [%s] ; nb = [%d] ; load_add = [%x]\n", rk, tab[rk].prog_name,
	   tab[rk].prog_numb, tab[rk].load_add);
  return (EXIT_SUCCESS);
}
