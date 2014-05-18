#include "asm.h"

/*
** Cette fonction code l'unique parametre des instructions
** fork et lfork
*/

char	*my_fork_lfork(char *file_cor, char *cmd, t_cmd *cmd_oct,
		 t_list **call_label)
{
  int	i;

  i = cmd_oct->i;
  if (cmd[i + 1] == LABEL_CHAR)
    fill_call_label(call_label, &cmd[i + 2], *cmd_oct->k - 1, *cmd_oct->k);
  file_cor = my_write_octets(file_cor, IND_SIZE, my_getnbr(&cmd[i + 1]),
			     cmd_oct->k);
  return (file_cor);
}
