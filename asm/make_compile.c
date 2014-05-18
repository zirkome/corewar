/*
** make_compile2.c for make_compile2 in /home/linard_f//corewar/homework/asm
**
** Made by fabien linardon
** Login   <linard_f@epitech.net>
**
** Started on  Thu Feb  7 13:37:13 2013 fabien linardon
** Last update Thu Mar 14 01:14:39 2013 nicolas bridoux
*/

#include "asm.h"

extern op_t	op_tab[];

/*
** HEADER_SIZE + 6 => +3 pour name +3 comment, decalage ?
** Cette fonction lance la compilation ligne par ligne et appelle
** toutes les sous fonctions, elle fait le café.
*/

void		make_compile(char *name, header_t *header, char **tab)
{
  t_compile	p;
  char		*file_cor;

  p.call_label = NULL;
  p.declare_label = NULL;
  file_cor = NULL;
  p.k = 0;
  p.i = -1;
  while (tab[++(p.i)])
    if (my_strcmp(tab[p.i], ""))
      {
	if (compile_cmd_and_label(&p, tab, file_cor))
	  return;
	is_label_null(&tab[p.i], p.label);
	if (compile_existing_cmd(tab, &file_cor, &p))
	  return;
      }
  if (check_multi_labels(&p.declare_label, &p.call_label, file_cor))
    return;
  if (!(file_cor = replace_label(file_cor, &p.call_label, &p.declare_label)))
    return;
  successfull(&p, name, file_cor, header);
}

/*
** si la commande tab[p->i] n'existe pas, on regarde si c'est un label
** si oui on l'ajoute a la liste des labels trouvés
** sinon c'est une erreur
*/

int	compile_cmd_and_label(t_compile *p, char **tab, char *file_cor)
{
  p->label = NULL;
  if (!command_exist(tab[p->i]))
    if (!(p->label = is_label(tab[p->i], &p->declare_label, p->k)))
      {
	error_unknow(p->i, tab, p->call_label, p->declare_label);
	free(file_cor);
	return (EXIT_FAILURE);
      }
  return (EXIT_SUCCESS);
}

/*
** Si la commande existe, on vérifie les paramètres, si tout est ok
** on l'écrit dans notre char * final
*/

int	compile_existing_cmd(char **tab, char **file_cor, t_compile *p)
{
  if (command_exist(tab[p->i]))
    {
      if (check_params(tab[p->i], command_exist(tab[p->i])) == -1)
	{
	  error_param(p->i, tab, p->call_label, p->declare_label);
	  free(*file_cor);
	  return (EXIT_FAILURE);
	}
      if (!(*file_cor = write_command(*file_cor, &p->k,
				      &p->call_label, tab[p->i])))
	{
	  my_free_list(p->declare_label);
	  my_free_list(p->call_label);
	  return (EXIT_FAILURE);
	}
    }
  return (EXIT_SUCCESS);
}

/*
** Si un label n'est pas null on associe a la case tab[p.i] une copie de ce label
*/

void	is_label_null(char **tab, char *label)
{
  if (label)
    {
      free(*tab);
      *tab = my_strdup(label);
      free(label);
    }
}

/*
** Après la compilation du bytecode, on écrit la taille en octet des instructions
** Après le nom dans le header, soit, la taille des instruct = k - HEADER_SIZE
** Ensuite on fait un seul write dans le fichier de destination
*/

void	final_name(char *name, char *file_cor, int k, header_t *header)
{
  int	fd;
  char	*name_final;

  header->prog_size = k;
  if ((name_final = find_name_final(name)) != NULL)
    {
      fd = open(name_final, O_CREAT | O_WRONLY | O_TRUNC, 0644);
      if (fd != -1)
	{
	  change_endian(header);
	  write(fd, header, sizeof(header_t));
	  write(fd, file_cor, sizeof(char) * k);
	  close(fd);
	}
      else
	{
	  my_error("file ", 0);
	  my_error(name_final, 0);
	  my_error(" not accesible.\n", 0);
	}
      free(name_final);
    }
  free(file_cor);
}
