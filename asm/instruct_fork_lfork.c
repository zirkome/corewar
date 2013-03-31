/*
** fork_lfork.c for fork_lfork in /home/linard_f//corewar/homework/asm
**
** Made by fabien linardon
** Login   <linard_f@epitech.net>
**
** Started on  Fri Feb  1 16:26:41 2013 fabien linardon
** Last update Wed Mar 13 14:15:15 2013 nicolas bridoux
*/

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
