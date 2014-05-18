/*
** zjmp.c for zjmp in /home/linard_f//corewar/homework/asm
**
** Made by fabien linardon
** Login   <linard_f@epitech.net>
**
** Started on  Fri Feb  1 15:51:59 2013 fabien linardon
** Last update Wed Mar 13 14:18:04 2013 nicolas bridoux
*/

#include "asm.h"

/*
** Cette fonction code le parametre de live
*/

char	*my_live(char *file_cor, char *cmd, t_cmd *cmd_oct,
		 t_list **call_label)
{
  int	i;

  i = cmd_oct->i;
  if (cmd[i + 1] == LABEL_CHAR)
    fill_call_label(call_label, &cmd[i + 2], *cmd_oct->k - 1, *cmd_oct->k);
  file_cor = my_write_octets(file_cor, DIR_SIZE, my_getnbr(&cmd[i + 1]),
			     cmd_oct->k);
  return (file_cor);
}

/*
** Cette fonction code le parametre de zjmp
*/

char	*my_zjmp(char *file_cor, char *cmd, t_cmd *cmd_oct,
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

/*
** Cette fonction code le parametre de aff
*/

char	*my_aff(char *file_cor, char *cmd, t_cmd *cmd_oct,
		 t_list **call_label)
{
  int	i;

  i = cmd_oct->i;
  file_cor = my_write_octets(file_cor, 1, my_getnbr(&cmd[i + 1]), cmd_oct->k);
  call_label = call_label;
  return (file_cor);
}
