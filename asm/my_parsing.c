/*
** my_parsing.c for my_parsing in /home/linard_f//corewar/homework/asm
**
** Made by fabien linardon
** Login   <linard_f@epitech.net>
**
** Started on  Mon Jan 21 19:23:51 2013 fabien linardon
** Last update Wed Mar 13 15:16:38 2013 nicolas bridoux
*/

#include "asm.h"

/*
** Fais un epur_str, et lance la compilation du header
*/

void	my_parsing(char *file, char *name)
{
  replace_space_ignore_comment(file);
  remove_comment(file);
  make_header(file, name);
}

/*
** Cette fonction supprime les commentaires et laisse une ligne vide à la place
*/

void	remove_comment(char *f)
{
  int	i;

  i = -1;
  while (f[++i])
    {
      if (!my_strncmp(&f[i], COMMENT_CMD_STRING, my_strlen(COMMENT_CMD_STRING))
	  || !my_strncmp(&f[i], NAME_CMD_STRING, my_strlen(NAME_CMD_STRING)))
	while (f[++i] != '\n');
      if (f[i] == COMMENT_CHAR)
	while (f[i] != '\n')
	  shift_string(f, i);
    }
  remove_spaces_added(f);
}

/*
** Cette fonction vérifie, qu'après supression des commentaires
** il ne reste pas deux espaces qui se suivent etc..
*/

void	remove_spaces_added(char *f)
{
  int	i;

  i = -1;
  while (f[++i])
    {
      if (!my_strncmp(&f[i], COMMENT_CMD_STRING, my_strlen(COMMENT_CMD_STRING))
	  || !my_strncmp(&f[i], NAME_CMD_STRING, my_strlen(NAME_CMD_STRING)))
	while (f[++i] != '\n');
      if (f[i] == ' ' && f[i + 1] == '\n')
	shift_string(f, i);
    }
  i = -1;
  while (f[++i])
    {
      if (!my_strncmp(&f[i], COMMENT_CMD_STRING, my_strlen(COMMENT_CMD_STRING))
	  || !my_strncmp(&f[i], NAME_CMD_STRING, my_strlen(NAME_CMD_STRING)))
	while (f[++i] != '\n');
      if (f[i] == ',' && f[i + 1] == ' ')
	shift_string(f, i + 1);
    }
}

/*
** Cette fonction suprime les espaces et tabulations aux mauvais endroits,
** elle fait en sorte que chaque instruction se trouve après un '\n' et que
** elle soient suivit d'un seul espace avant leurs parametres,
** comme dans l'exemple du sujet, pour faciliter le parsing.
*/

void	replace_space_ignore_comment(char *f)
{
  int	i;

  i = -1;
  while (f[++i])
    {
      if (!my_strncmp(&f[i], COMMENT_CMD_STRING, my_strlen(COMMENT_CMD_STRING))
	  || !my_strncmp(&f[i], NAME_CMD_STRING, my_strlen(NAME_CMD_STRING)))
	while (f[++i] != '\n');
      if (f[i] == '\t')
	f[i] = ' ';
      if (f[i] == ';')
	while (f[i] != '\n')
	  shift_string(f, i);
    }
  remove_space_and_tab(f);
}

/*
** Un epur_str (qui ignore le .comment et .name)
*/

void	remove_space_and_tab(char *f)
{
  int	i;

  i = -1;
  while (f[++i])
    {
      if (!my_strncmp(&f[i], COMMENT_CMD_STRING, my_strlen(COMMENT_CMD_STRING))
	  || !my_strncmp(&f[i], NAME_CMD_STRING, my_strlen(NAME_CMD_STRING)))
	while (f[++i] != '\n');
      while (f[i] == '\t' && f[i + 1] == '\t')
	shift_string(f, i);
      while (f[i] == ' ' && f[i + 1] == ' ')
	shift_string(f, i);
      if ((f[i] == ' ' || f[i] == '\t') && f[i + 1] == '\n')
	shift_string(f, i);
      while (f[i] == '\n' && (f[i + 1] == ' ' || f[i + 1] == '\t'))
      	shift_string(f, i + 1);
    }
}

