/*
** make_header.c for make_header.c in /home/bridou_n//corewar
**
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
**
** Started on  Wed Jan 23 15:00:56 2013 nicolas bridoux
** Last update Wed Mar 13 23:14:55 2013 nicolas bridoux
*/

#include "asm.h"

/*
** Cette fonction fait le header, elle remplit le nom, le comment et le
** magic number useless
*/

void		make_header(char *file, char *name)
{
  char		*champ_name;
  char		*comment;
  header_t	header;

  if ((champ_name = find_name(file)) == NULL)
    {
      free(file);
      my_putstr(RED_BOLD);
      my_error("[ERROR] :", 0);
      my_putstr(INIT);
      my_error("improperly formated .name line.\n", 0);
      return;
    }
  comment = find_comment(file);
  if (make_comment_and_size(comment, file, champ_name))
    return;
  fill_name_champ(champ_name, &header);
  fill_comment(comment, &header);
  header.magico = COREWAR_EXEC_MAGIC;
  make_instruction_tab(file, name, &header);
}

/*
** Vérifie qu'il n'y a pas d'erreur dans le .comment et remplit la taille sur 4 octets
*/ 

int	make_comment_and_size(char *comment, char *file, char *champ_name)
{
  if (comment == NULL)
    {
      free(file);
      free(champ_name);
      my_putstr(RED_BOLD);
      my_error("[ERROR] :", 0);
      my_putstr(INIT);
      my_error("improperly formated .comment line.\n", 0);
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

/*
** Cette fonction trouve le comment après le .comment dans le fichier .s
*/

char	*find_comment(char *file)
{
  int	i;
  int	k;
  char	tmp;
  char	*name;

  i = -1;
  while (file[++i])
    if (!my_strncmp(&file[i], COMMENT_CMD_STRING,
		    my_strlen(COMMENT_CMD_STRING)))
      {
	while (file[i] != '"' && file[i])
	  ++i;
	k = i + 1;
	while (file[++i] != '"' && file[i]);
	if (!file[i])
	  return (NULL);
	tmp = file[i];
	file[i] = '\0';
	name = my_strdup(&file[k]);
	file[i] = tmp;
	return (name);
      }
  return (my_strdup(""));
}

/*
** Cette fonction trouve le nom, après .name dans le fichier .s
*/

char	*find_name(char *file)
{
  int	i;
  int	k;
  char	tmp;
  char	*name;

  i = -1;
  while (file[++i])
    if (!my_strncmp(&file[i], NAME_CMD_STRING, my_strlen(NAME_CMD_STRING)))
      {
	while (file[i] != '"' && file[i])
	  ++i;
	k = i + 1;
	while (file[++i] != '"' && file[i]);
	if (!file[i])
	  return (NULL);
	tmp = file[i];
	file[i] = '\0';
	name = my_strdup(&file[k]);
	file[i] = tmp;
	return (name);
      }
  return (my_strdup(""));
}
