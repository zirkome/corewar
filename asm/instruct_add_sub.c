/*
** add_sub.c for add_sub in /home/linard_f//corewar/homework/asm
**
** Made by fabien linardon
** Login   <linard_f@epitech.net>
**
** Started on  Fri Feb  1 15:18:57 2013 fabien linardon
** Last update Wed Mar 13 14:34:39 2013 nicolas bridoux
*/

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
