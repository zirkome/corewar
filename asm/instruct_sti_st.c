#include "asm.h"

/*
** Cette fonction code les parametres de l'instruction st
*/

char	*my_st(char *file_cor, char *cmd, t_cmd *cmd_oct,
		 t_list **call_label)
{
  int	i;

  i = cmd_oct->i;
  file_cor = my_write_octets(file_cor, 1, my_getnbr(&cmd[i + 1]), cmd_oct->k);
  while (cmd[++i] && cmd[i] != ',');
  if (cmd[i + 1] == 'r')
    file_cor = my_write_octets(file_cor, 1, my_getnbr(&cmd[i + 2]),
			       cmd_oct->k);
  else
    {
      if (cmd[i + 1] == LABEL_CHAR)
	fill_call_label(call_label, &cmd[i + 2], *cmd_oct->k - 3, *cmd_oct->k);
      file_cor = my_write_octets(file_cor, IND_SIZE, my_getnbr(&cmd[i + 1]),
				 cmd_oct->k);
    }
  return (file_cor);
}

/*
** Cette fonction code le premier param de l'instruction sti
*/

char	*my_sti(char *file_cor, char *cmd, t_cmd *cmd_oct,
		 t_list **call_label)
{
  int	i;

  i = cmd_oct->i;
  if (cmd_oct->nb_cmd == STI)
    {
      file_cor = my_write_octets(file_cor, 1, my_getnbr(&cmd[i + 1]),
				 cmd_oct->k);
      while (cmd[++i] != ',' && cmd[i]);
      if (cmd[i + 1] == DIRECT_CHAR)
	{
	  if (cmd[i + 2] == LABEL_CHAR)
	    fill_call_label(call_label, &cmd[i + 3], *cmd_oct->k - 3,
			    *cmd_oct->k);
	  file_cor = my_write_octets(file_cor, IND_SIZE,
				     my_getnbr(&cmd[i + 2]), cmd_oct->k);
	  cmd_oct->size_cmd = 5;
	}
      cmd_oct->i = i;
      file_cor = check_my_sti_param(file_cor, cmd, cmd_oct, call_label);
    }
  return (file_cor);
}

/*
** Cette fonction code les 2 derniers param de l'instruction sti
*/

char	*check_my_sti_param(char *file_cor, char *cmd, t_cmd *cmd_oct,
		 t_list **call_label)
{
  int	i;

  i = cmd_oct->i;
  if (cmd[i + 1] == 'r')
    {
      cmd_oct->size_cmd = 4;
      file_cor = my_write_octets(file_cor, 1, my_getnbr(&cmd[i + 2]),
				 cmd_oct->k);
    }
  while (cmd[++i] != ',' && cmd[i]);
  if (cmd[i + 1] == DIRECT_CHAR)
    {
      if (cmd[i + 2] == LABEL_CHAR)
	fill_call_label(call_label, &cmd[i + 3],
			*cmd_oct->k - cmd_oct->size_cmd, *cmd_oct->k);
      file_cor = my_write_octets(file_cor, IND_SIZE,
				 my_getnbr(&cmd[i + 2]), cmd_oct->k);
    }
  if (cmd[i + 1] == 'r')
    file_cor = my_write_octets(file_cor, 1, my_getnbr(&cmd[i + 2]),
			       cmd_oct->k);
  return (file_cor);
}
