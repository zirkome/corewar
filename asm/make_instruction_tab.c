/*
** make_instruction_tab.c for make_instruction_tab.c in /home/bridou_n//corewar
**
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
**
** Started on  Wed Jan 23 23:10:41 2013 nicolas bridoux
** Last update Wed Mar 13 23:08:09 2013 nicolas bridoux
*/

#include "asm.h"

/*
** Cette fonction appelle les fonctions pour epurer et parser le fichier recu en param
** ensuite elle lance la compilation avec le tableau d'instructions
*/

void	make_instruction_tab(char *file, char *name_file, header_t *header)
{
  char	**tab;

  remove_comment_and_name(file);
  tab = fill_instruction_tab(file, -1, -1, 0);
  free(file);
  make_compile(name_file, header, tab);
  my_free_tab(tab);
}

/*
** J'ai oublié le role de cette fonction
*/

void	remove_comment_and_name(char *file)
{
  int	i;

  i = -1;
  while (file[++i])
    {
      if (!my_strncmp(&file[i], NAME_CMD_STRING, my_strlen(NAME_CMD_STRING)))
	while (file[i] != '\n' && file[i])
	  shift_string(file, i);
      if (!my_strncmp(&file[i], COMMENT_CMD_STRING,
		      my_strlen(COMMENT_CMD_STRING)))
	while (file[i] != '\n' && file[i])
	  shift_string(file, i);
    }
}

/*
** Cette fonction parcours le char *passé en param et met chaque ligne dans un
** char ** pour compiler ligne par ligne
*/

char	**fill_instruction_tab(char *file, int i, int k, int j)
{
  char	**tab;

  if ((tab = malloc(sizeof(char*) * (nb_line(file) + 1))) == NULL)
    {
      free(file);
      my_error("Can't perfom malloc.\n", 1);
    }
  tab[++k] = my_strdup("");
  while (file[++i])
    if (file[i] == '\n')
      {
	file[i] = '\0';
	tab[++k] = my_strdup(&file[j]);
	j = i + 1;
      }
    else if (file[i] == '\n' && file[i + 1] == '\n')
      {
	tab[++k] = my_strdup("");
	j = i + 1;
      }
  if (j)
    tab[++k] = my_strdup(&file[j]);
  tab[++k] = NULL;
  return (tab);
}

/*
** Compte le nb de \n dans le char * passé en para.
*/

int	nb_line(char *file)
{
  int	i;
  int	nb_lines;

  nb_lines = 1;
  i = -1;
  while (file[++i])
    if (file[i] == '\n')
      ++nb_lines;
  return (++nb_lines);
}
