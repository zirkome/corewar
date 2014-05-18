#include "asm.h"

/*
** Cette fonction code les parametres des fonctions add et sub
*/

char	*my_add_sub(char *file_cor, char *cmd, t_cmd *cmd_oct,
		 t_list **call_label)
{
  int	i;

  i = cmd_oct->i;
  file_cor = my_write_octets(file_cor, 1, my_getnbr(&cmd[i + 1]), cmd_oct->k);
  while (cmd[++i] && cmd[i] != ',');
  file_cor = my_write_octets(file_cor, 1, my_getnbr(&cmd[i + 2]), cmd_oct->k);
  while (cmd[++i] && cmd[i] != ',');
  file_cor = my_write_octets(file_cor, 1, my_getnbr(&cmd[i + 2]), cmd_oct->k);
  call_label = call_label;
  return (file_cor);
}
