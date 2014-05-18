#include "asm.h"

/*
** Cette fonction code les aprametres des instructions ld et lld
*/

char	*my_ld_lld(char *file_cor, char *cmd, t_cmd *cmd_oct,
		 t_list **call_label)
{
  int	i;

  i = cmd_oct->i;
  if (cmd[i] == DIRECT_CHAR)
    {
      if (cmd[i + 1] == LABEL_CHAR)
	fill_call_label(call_label, &cmd[i + 2], *cmd_oct->k - 2, *cmd_oct->k + 2);
      file_cor = my_write_octets(file_cor, DIR_SIZE, my_getnbr(&cmd[i + 1]),
				 cmd_oct->k);
    }
  else
    {
      if (cmd[i] == LABEL_CHAR)
	fill_call_label(call_label, &cmd[i + 1], *cmd_oct->k - 2, *cmd_oct->k);
      file_cor = my_write_octets(file_cor, IND_SIZE, my_getnbr(&cmd[i]),
				 cmd_oct->k);
    }
  while (cmd[++i] && cmd[i] != ',');
  file_cor = my_write_octets(file_cor, 1, my_getnbr(&cmd[i + 2]), cmd_oct->k);
  return (file_cor);
}
