/*
** check_label.c for check_label.c in /home/bridou_n//corewar
** 
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
** 
** Started on  Tue Jan 22 15:09:59 2013 nicolas bridoux
** Last update Tue Jan 22 16:13:27 2013 nicolas bridoux
*/

#include "asm.h"

int	label_exist(char *label, char *file, int line)
{
  int	i;

  i = -1;
  while (file[++i])
    if (file[i] == '\n')
      if (!my_strncmp(&file[i + 1], label, my_strlen(label)))
	return (1);
  my_error("Label ", 0);
  my_error(label, 0);
  my_error(" undefine line ", 0);
  my_put_nbr(line); /* stderr */
  my_error(".\n", 0);
  free(label);
  return (0);
}

int	check_label(char *file)
{
  int	i;
  int	line;

  i = -1;
  line = 1;
  while (file[++i])
    {
      if (file[i] == '\n')
	++line;
      if (file[i] == LABEL_CHAR && file[i + 1] != '\t' && file[i + 1] != ' ')
	if (!fill_label(file, &i, &line))
	  return (0);
    }
  return (1);
}

int	fill_label(char *file, int *i, int *line)
{
  int	k;
  char	tmp;
  char	*label;

  k = *i + 1;
  while (file[*i] != '\n' && file[*i] != '\0' &&
	 file[*i] != SEPARATOR_CHAR && file[*i] != '\t' && file[*i] != ' ')
    ++(*i);
  if (file[*i] == '\n')
    ++(*line);
  tmp = file[*i];
  file[*i] = '\0';
  label = my_strdup(&file[k]);
  file[*i] = tmp;
  if (!label_exist(label, file, *line - 1))
    return (0);
  return (1);
}
