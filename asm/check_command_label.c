/*
** make_compile.c for make_compile.c in /home/bridou_n//corewar
**
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
**
** Started on  Thu Jan 24 11:02:04 2013 nicolas bridoux
** Last update Wed Mar 13 16:21:01 2013 nicolas bridoux
*/

#include "asm.h"

extern op_t	op_tab[];

/*
** A partir du nom original, cette fonction retourne le nom final
** on supprime .s on ajoute .cor , pas sorcier
*/

char	*find_name_final(char *name)
{
  int	i;
  char	*name_final;

  i = -1;
  while (name[++i])
    {
      if (!my_strncmp(&name[i], ".s", my_strlen(".s")))
	{
	  name[i] = '\0';
	  if ((name_final = malloc(sizeof(char) * my_strlen(name) + 5)) == NULL)
	    {
	      my_error("Can't perform malloc.\n", 0);
	      return (NULL);
	    }
	  my_strcpy(name_final, name);
	  my_strcat(name_final, ".cor");
	  return (name_final);
	}
    }
  return (NULL);
}

/*
** Cette fonction vérifie que la commande passé en parametre est bien présente dans
** op_tab, donc qu'elle éxiste
*/

int	command_exist(char *cmd)
{
  int	i;
  int	k;

  k = -1;
  i = -1;
  while (cmd[++i] && cmd[i] != ' ');
  while (op_tab[++k].code)
    if (!my_strncmp(cmd, op_tab[k].mnemonique, i))
      return (++k);
  return (EXIT_SUCCESS);
}

/*
** Cette fonction vérifie que la commande passé en param est un label, si oui
** elle l'ajoute a la liste chainée des labels déclarés
*/

char	*is_label(char *cmd, t_list **declare_label, int pos)
{
  int	i;
  char	tmp;

  i = -1;
  while (cmd[++i] && cmd[i] != ' ');
  if (cmd[i - 1] == LABEL_CHAR)
    {
      tmp = cmd[i - 1];
      cmd[i - 1] = '\0';
      my_put_in_list(declare_label, my_strdup(&cmd[0]), pos, 0);
      cmd[i - 1] = tmp;
      if (cmd[i] == '\0')
	return (my_strdup(""));
      else
	return (my_strdup(&cmd[i + 1]));
    }
  return (NULL);
}

/*
** Verifie que les labels de la liste passé en param sont dans LABEL_CHARS
*/

int		check_label_chars(t_list **declare_label, t_list **call_label,
				  char *file_cor)
{
  t_list	*tmp;
  int		i;

  tmp = *declare_label;
  while (tmp)
    {
      i = -1;
      while (tmp->name[++i])
	if (in_label_chars(tmp->name[i], LABEL_CHARS))
	  {
	    my_free_list(*declare_label);
	    my_free_list(*call_label);
	    free(file_cor);
	    return (wrong_label_name());
	  }
      tmp = tmp->next;
    }
  return (EXIT_SUCCESS);
}

/*
** Verifie que le char passé en param soit bien dans LABEL_CHARS
*/

int	in_label_chars(char c, char *label_chars)
{
  int	i;

  i = -1;
  while (label_chars[++i])
    if (label_chars[i] == c)
      return (EXIT_SUCCESS);
  return (EXIT_FAILURE);
}
