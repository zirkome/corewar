#include "asm.h"

extern op_t	op_tab[];

/*
** Cette fonction appele la fonction qui check le nombres de parametres d'une instruction
** En cas d'erreur => message d'erreur + return
** Sinon, elle appelle la fonction qui check le type de chacun des parametres
*/

int	check_params(char *cmd, int nb_cmd)
{
  int	i;
  int	ret;

  ret = 0;
  i = -1;
  while (cmd[++i] && cmd[i] != ' ');
  if (!cmd[i] || check_nb_p(&cmd[i + 1], nb_cmd) == -1)
    {
      my_putstr(RED_BOLD);
      my_error("[ERROR] ", 0);
      my_putstr(INIT);
      my_error("Wrong number of parameter at line : ", 0);
      return (-1);
    }
  ret = check_param_type(&cmd[i + 1], nb_cmd);
  return (check_ret(ret));
}

/*
** Si le retour est égal a -1 ou -2, il y a eu une erreur dans le type des parametres
** ou un registre inexistant
*/

int	check_ret(int ret)
{
  if (ret == -1)
    {
      my_putstr(RED_BOLD);
      my_error("[ERROR] ", 0);
      my_putstr(INIT);
      my_error("Wrong parameter type at line : ", 0);
      return (-1);
    }
  if (ret == -2)
    {
      my_putstr(RED_BOLD);
      my_error("[ERROR] ", 0);
      my_putstr(INIT);
      my_error("No such register line : ", 0);
      return (-1);
    }
  return (42);
}

/*
** Cette fonction regarde les parametres de l'instruction passé en parametre
** Après avoir récupérer le type de paramètre, elle vérifie avec un & binaire
** dans op_tab si l'opération renvoit 0 => les bits de mm poids sont les mêmes
** Donc bon type de param, sinon erreur dans le type des paramètres.
*/

int	check_param_type(char *cmd, int nb_cmd)
{
  int	i;
  int	k;
  char	type;

  i = -1;
  k = -1;
  while (cmd[++i])
    {
      type = 0;
      if (cmd[i] == '%')
	type |= T_DIR;
      else if (cmd[i] == 'r')
	{
	  if (my_getnbr(&cmd[i + 1]) > REG_NUMBER || my_getnbr(&cmd[i + 1]) <= 0)
	    return (-2);
	  type |= T_REG;
	}
      else if ((cmd[i] <= '9' && cmd[i] >= '0') || cmd[i] == '-'
	       || cmd[i] == '+' || cmd[i] == LABEL_CHAR)
	type |= T_IND;
      i = check_params_type(i, cmd);
      if (!(op_tab[nb_cmd - 1].type[++k] & type))
	return (-1);
    }
  return (1);
}

/*
** Juste une boucle pour passer au paramètre suivant
*/

int	check_params_type(int i, char *cmd)
{
  while (cmd[i] != ',' && cmd[i])
    ++i;
  if (!cmd[i])
    --i;
  return (i);
}

/*
** On compte le nombre de paramètre, si le nombre de paramètre est mauvais
** rien ne sert de controller leur type
*/

int	check_nb_p(char *cmd, int nb_cmd)
{
  int	rk;
  char	nb;

  rk = - 1;
  nb = 1;
  while (cmd[++rk])
    if (cmd[rk] == ',')
      ++nb;
  if (rk && op_tab[nb_cmd - 1].nbr_args == nb)
    return (nb);
  return (-1);
}
