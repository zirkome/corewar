/*
** parsing_param.c for parsing_param$ in /home/linard_f//corewar/homework/vm
**
** Made by fabien linardon
** Login   <linard_f@epitech.net>
**
** Started on  Tue Mar 12 17:24:38 2013 fabien linardon
** Last update Sat Mar 23 00:27:46 2013 Guillaume Fillon
*/

#include "lib.h"
#include "vm.h"

/* à virer si vous avez déjà une fonction qui fait ça. */

int	syntax_error(char *msg)
{
  write(2, msg, strlen(msg));
  return (-1);
}

void	initialize_tab(t_prog *tab)
{
  int	i;

  i = -1;
  while (++i < 4)
    {
      tab[i].prog_name = NULL;
      tab[i].prog_numb = -1; /* j'initialise à -1 car on peut avoir 0 comme numéro. */
      tab[i].load_add = -1; /* ici je en sais pas trop ce qu'il faut mettre comme adresse. */
    }
}

int	parsing_param(char **av, t_prog *tab)
{
  int	dump;
  int	i;
  int	j;

  dump = 0;
  i = -1;
  j = 0;
  while (av[++i])
    {
      if (!my_strcmp(av[i], "-dump"))
	{
	  if (av[++i])
	    dump = atoi(av[i]); /* remplacer atoi par getnbr !*/
	  else
	    return (syntax_error("Syntax error.\n"));
	}
      else
	{
	  if ((j = fill_prog_tab(&av[i], tab, j)) == -1)
	    return (-1);
	  if (av[i][0] == '-')
	    ++i;
	}
    }
  return (dump);
}
