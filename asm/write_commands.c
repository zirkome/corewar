#include "asm.h"

/*
** Cette fonction ecrit l'octet de la commande, puis realloc, puis ecrit l'octet de codage
** puis envoit à la fonction qui ecrit les parametres.
*/

char	*write_command(char *file_cor, int *k, t_list **call_label, char *cmd)
{
  char	nb_cmd;
  char	*file_cor_realloc;

  file_cor_realloc = NULL;
  nb_cmd = command_exist(cmd);
  if ((file_cor_realloc = realloc(file_cor, sizeof(char) * ++(*k))) == NULL)
    {
      my_error("Can't perform malloc.\n", 0);
      return (NULL);
    }
  file_cor = file_cor_realloc;
  file_cor[(*k) - 1] = nb_cmd;
  if (!(file_cor = no_param_instruct(nb_cmd, file_cor, k, cmd)))
    return (NULL);
  file_cor = write_param(cmd, call_label, file_cor, k);
  return (file_cor);
}

/*
** Cette fonction ecrit les parametres de l'instruction
*/

char	*write_param(char *cmd, t_list **call_label, char *file_cor, int *k)
{
  int	i;
  int	nb_cmd;
  t_cmd	cmd_oct;

  nb_cmd = command_exist(cmd);
  i = -1;
  while (cmd[++i] != ' ' && cmd[i]);
  ++i;
  cmd_oct.i = i;
  cmd_oct.nb_cmd = nb_cmd;
  cmd_oct.k = k;
  file_cor = cmd_pointer_tab(file_cor, cmd, &cmd_oct, call_label);
  return (file_cor);
}

/*
** Cette fonction ecrit dans file_cor à l'endroit *k
** Elle écrit param, sur size octets (masques binaires)
*/

char	*my_write_octets(char *file_cor, int size, int param, int *k)
{
  char	*file_cor_realloc;

  file_cor_realloc = NULL;
  *k += size;
  if ((file_cor_realloc = realloc(file_cor, sizeof(char) * (*k))) == NULL)
    {
      my_error("Can't perform malloc.\n", 0);
      return (NULL);
    }
  file_cor = file_cor_realloc;
  if (size == DIR_SIZE)
    {
      file_cor[(*k) - 4] = param >> 24;
      file_cor[(*k) - 3] = (param >> 16) & 0xFF;
      file_cor[(*k) - 2] = (param >> 8) & 0xFF;
      file_cor[(*k) - 1] = param & 0xFF;
    }
  else if (size == IND_SIZE)
    {
      file_cor[(*k) - 2] = (param >> 8) & 0xFF;
      file_cor[(*k) - 1] = param & 0xFF;
    }
  else
    file_cor[(*k) - 1] = param & 0xFF;
  return (file_cor);
}

/*
** Si on trouve un label dans un param, on remplit la liste chainee avec son nom
** et sa position et la position de l'instruction pour pouvoir faire la soustraction.
*/

void	fill_call_label(t_list **call_label, char *cmd, int pos, int pos_label)
{
  int	i;
  char	tmp;

  i = -1;
  while (cmd[++i] && cmd[i] != ',' && cmd[i] != ' ');
  tmp = cmd[i];
  cmd[i] = '\0';
  my_put_in_list(call_label, my_strdup(&cmd[0]), pos, pos_label);
  cmd[i] = tmp;
}

/*
** Cette fonction retourne l'octet de codage en fonctions des parametres de la commande
*/

char		arg_type(char *cmd)
{
  int		i;
  int		k;
  unsigned char	type;

  i = -1;
  k = 6;
  type = 0;
  while (cmd[++i] && cmd[i] != ' ');
  while (cmd[++i])
    {
      if (cmd[i] == 'r')
	type |= (1 << k);
      else if (cmd[i] == DIRECT_CHAR)
	type |= (2 << k);
      else if ((cmd[i] <= '9' && cmd[i] >= '0') || cmd[i] == '-'
	       || cmd[i] == '+' || cmd[i] == LABEL_CHAR)
	type |= (3 << k);
      while (cmd[i] != ',' && cmd[i])
	++i;
      k -= 2;
      if (!cmd[i])
	--i;
    }
  return (type);
}
