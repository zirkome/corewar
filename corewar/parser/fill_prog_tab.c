/*
** fill_prog_tab.c for fill_prog_tab in /home/linard_f//corewar/homework/vm
**
** Made by fabien linardon
** Login   <linard_f@epitech.net>
**
** Started on  Tue Mar 12 20:02:45 2013 fabien linardon
** Last update Fri Mar 29 22:58:56 2013 remi
*/

#include "lib.h"
#include "vm.h"

int		my_get_nbr_hex(char *str)
{
  static char	hex[] = "0123456789ABCDEF";
  int		rk;
  int		nb;
  int		i;

  nb = 0;
  rk = -1;
  while (str[++rk])
    {
      i = -1;
      while (hex[++i] && str[rk] != hex[i]);
      if (i > 15)
	return (nb);
      nb = nb * 16 + i;
    }
  return (nb);
}

int	fill_prog_tab(char **av, t_prog *tab, int rk)
{
  if (!my_strcmp(av[0], "-v"))
    {
      printf("OKOKKOK PASS\n");
      if (tab[rk].debug != -1)
      	++rk;
      if (rk > 3)
      	return (syntax_error("Syntax error.\n"));
      tab[rk].debug = 1;
      return (rk);
    }
  if (!my_strcmp(av[0], "-n") && av[1])
    {
    if (tab[rk].prog_numb != -1)
      ++rk;
    if (rk > 3)
      return (syntax_error("Syntax error.\n"));
    tab[rk].prog_numb = my_getnbr(av[1]);
    return (rk);
    }
  else if (!my_strcmp(av[0], "-a") && av[1])
    {
      if (tab[rk].load_add != -1)
	++rk;
      if (rk > 3)
	return (syntax_error("Syntax error.\n"));
      tab[rk].load_add = my_get_nbr_hex(av[1]);
      return (rk);
    }
  else if (!my_strcmp(av[0], "-m") && av[1])
    {
      if (tab[rk].mem != -1)
	++rk;
      if (rk > 3)
	return (syntax_error("Syntax error.\n"));
      tab[rk].mem = my_get_nbr_hex(av[1]);
      return (rk);
    }
  else if (av[0][0] != '-')
    return (fill_prog_name(av, tab, rk));
  return (syntax_error("Syntax error.\n"));
}

int	fill_prog_name(char **av, t_prog *tab, int rk)
{
  if (tab[rk].prog_name != NULL)
    ++rk;
  if (rk > 3)
    return (syntax_error("Syntax error.\n"));
  tab[rk].prog_name = my_strdup(av[0]);
  return (rk);
}
