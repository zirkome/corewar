/*
** fab.h for fab in /home/linard_f//corewar/homework/vm
**
** Made by fabien linardon
** Login   <linard_f@epitech.net>
**
** Started on  Tue Mar 12 19:16:29 2013 fabien linardon
** Last update Fri Mar 29 14:20:03 2013 remi
*/

/* je suppose que vous avez déjà ces includes ! */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef	struct s_prog
{
  char	*prog_name;
  int	prog_numb;
  int	load_add;
}	t_prog;

char *strdup(const char *s); /* à virer ! */

/* parsing_param.c */
int	syntax_error(char *msg); /* à virer si vous avez déjà une fonction qui fait ça. */
void	initialize_tab(t_prog *tab);
int	parsing_param(char **av, t_prog *tab);

/* fill_prog_tab.c */
int	my_get_nbr_hex(char *str);
int	fill_prog_tab(char **av, t_prog *tab, int rk);
int	fill_prog_name(char **av, t_prog *tab, int rk);

/* progs_info.c */
t_prog	prog_name(char **av);
t_prog	prog_number(char **av);
t_prog	load_address(char **av);

/* my_strcmp */
int	my_strcmp(char *a, char *b); /* à virer, je suppose que vous l'avez déjà. */
