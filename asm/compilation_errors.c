#include "asm.h"

/*
** Affiche un message d'erreur si une instruction n'est pas connue + free les listes
*/

void	error_unknow(int i, char **tab, t_list *call_label,
		     t_list *declare_label)
{
  my_putstr(RED_BOLD);
  my_error("[ERROR] ", 0);
  my_putstr(INIT);
  my_error("Unknown instruction at line  : ", 0);
  my_put_nbr(i + 2);
  my_error(".\n", 0);
  my_putstr(CYAN_BOLD);
  my_error("line => ", 0);
  my_putstr(INIT);
  my_error(tab[i], 0);
  my_error("\n", 0);
  my_free_list(declare_label);
  my_free_list(call_label);
}

/*
** Affiche un message d'erreur en cas d'erreur dans les parametres d'une instruction
*/

void	error_param(int i, char **tab, t_list *call_label,
		      t_list *declare_label)
{
  my_put_nbr(i + 2);
  my_error(".\n", 0);
  my_putstr(CYAN_BOLD);
  my_error("line => ", 0);
  my_putstr(INIT);
  my_error(tab[i], 0);
  my_error("\n", 0);
  my_free_list(declare_label);
  my_free_list(call_label);
}

/*
** Après avoir écrit le bytecode dans le fichier, on affiche succès, tout s'est bien passé
*/

void	successfull(t_compile *p, char *name_file, char *file_cor, header_t *header)
{
  my_putstr(GREEN_BOLD);
  my_putstr("[Successfull]\n");
  my_putstr(INIT);
  display_name_and_comment(header);
  final_name(name_file, file_cor, p->k, header);
  my_free_list(p->declare_label);
  my_free_list(p->call_label);
}

/*
** s'occupe de coder les instructions sans parametres (zjmp, live, fork et lfork)
*/

char	*no_param_instruct(int nb_cmd, char *file_cor, int *k, char *cmd)
{
  char	*file_cor_realloc;

  file_cor_realloc = NULL;
  if (nb_cmd != ZJMP && nb_cmd != LIVE && nb_cmd != FORK && nb_cmd != LFORK)
    {
      if (!(file_cor_realloc = realloc(file_cor, sizeof(char) * ++(*k))))
	{
	  my_error("Can't perform malloc.\n", 0);
	  free(file_cor);
	  return (NULL);
	}
      file_cor = file_cor_realloc;
      file_cor[*k - 1] = arg_type(cmd);
    }
  return (file_cor);
}

/*
** Affiche uniquement un message d'erreur avant de quitter
*/

int	wrong_label_name(void)
{
  my_putstr(RED_BOLD);
  my_error("[Erorr] ", 0);
  my_putstr(INIT);
  my_error("Label containing non LABEL_CHARS\n", 0);
  my_putstr(INIT);
  return (EXIT_FAILURE);
}
