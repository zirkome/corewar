/*
** and_or_xor.c for and_or_xor in /home/linard_f//corewar/homework/asm
**
** Made by fabien linardon
** Login   <linard_f@epitech.net>
**
** Started on  Fri Feb  1 15:31:13 2013 fabien linardon
** Last update Wed Mar 13 14:29:40 2013 nicolas bridoux
*/

#include "asm.h"

/*
** Cette fonction code le premier parametres des instructions
** and xor et or
*/

char	*my_and_or_xor(char *file_cor, char *cmd, t_cmd *cmd_oct,
		 t_list **call_label)
{
  int	i;

  i = cmd_oct->i;
  if (cmd[i] != 'r' && cmd[i] != DIRECT_CHAR)
    {
      file_cor = my_write_octets(file_cor, IND_SIZE, my_getnbr(&cmd[i]),
				 cmd_oct->k);
      cmd_oct->size_cmd = 4;
    }
  if (cmd[i] == 'r')
    {
      cmd_oct->size_cmd = 3;
      file_cor = my_write_octets(file_cor, 1, my_getnbr(&cmd[i + 1]),
				 cmd_oct->k);
    }
  if (cmd[i] == DIRECT_CHAR)
    {
      if (cmd[i + 1] == LABEL_CHAR)
	fill_call_label(call_label, &cmd[i + 2], *cmd_oct->k - 2, *cmd_oct->k);
      file_cor = my_write_octets(file_cor, DIR_SIZE, my_getnbr(&cmd[i + 1]),
				 cmd_oct->k);
      cmd_oct->size_cmd = 6;
    }
  return (check_and_or_xor_param(file_cor, cmd, cmd_oct, call_label));
}

/*
** Cette fonction code les deux derniers parametres des instructions
** and xor et or
*/

char	*check_and_or_xor_param(char *file_cor, char *cmd, t_cmd *cmd_oct,
		 t_list **call_label)
{
  int	i;

  i = cmd_oct->i;
  while (cmd[++i] && cmd[i] != ',');
  if (cmd[++i] != 'r' && cmd[i] != '%')
    file_cor = my_write_octets(file_cor, 2, my_getnbr(&cmd[i]), cmd_oct->k);
  if (cmd[i] == 'r')
    file_cor = my_write_octets(file_cor, 1, my_getnbr(&cmd[i + 1]),
			       cmd_oct->k);
  if (cmd[i] == DIRECT_CHAR)
    {
      if (cmd[i + 1] == LABEL_CHAR)
	fill_call_label(call_label, &cmd[i + 2],
			*cmd_oct->k - cmd_oct->size_cmd, *cmd_oct->k);
      file_cor = my_write_octets(file_cor, DIR_SIZE, my_getnbr(&cmd[i + 1]),
				 cmd_oct->k);
    }
  while (cmd[++i] && cmd[i] != ',');
  file_cor = my_write_octets(file_cor, 1, my_getnbr(&cmd[i + 2]), cmd_oct->k);
  return (file_cor);
}
