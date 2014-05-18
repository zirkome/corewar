/*
** replace_label.c for replace_label.c in /home/bridou_n//corewar
** 
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
** 
** Started on  Fri Jan 25 21:36:22 2013 nicolas bridoux
** Last update Wed Mar 13 16:20:38 2013 nicolas bridoux
*/

#include "asm.h"

/*
** Cette fonction repasse sur tout les labels trouvés et les change par leur valeur
** en comparant dans la 2eme liste chainée qui contient les positions des declarations
** des labels.
*/

char		*replace_label(char *file_cor, t_list **call_label,
			       t_list **declare_label)
{
  t_list	*declare;
  t_list	*found;
  int		good_label;

  found = *call_label;
  while (found)
    {
      good_label = 0;
      declare = *declare_label;
      while (declare)
	{
	  if (!my_strcmp(found->name, declare->name))
	    {
	      ++good_label;
	      file_cor[found->pos_label] = ((declare->pos - found->pos) >> 8) & 0xFF;
	      file_cor[found->pos_label + 1] = (declare->pos - found->pos) & 0xFF;
	    }
	  declare = declare->next;
	}
      if (!good_label)
	return (error_unknow_label(file_cor, call_label, declare_label, found->name));
      found = found->next;
    }
  return (file_cor);
}

/*
** Si un label n'existe pas, on affiche une erreur , on free et on return NULL
*/

char	*error_unknow_label(char *file_cor, t_list **call_label,
			    t_list **declare_label, char *name)
{
  my_putstr(RED_BOLD);
  my_error("[Erorr] ", 0);
  my_putstr(INIT);
  my_error("unknown label : ", 0);
  my_putstr(BLUE_BOLD);
  my_error(name, 0);
  my_putstr(INIT);
  my_error("\n", 0);
  my_free_list(*declare_label);
  my_free_list(*call_label);
  free(file_cor);
  return (NULL);
}

/*
** Deux boucles pour vérifier que les labels ne sont présents qu'une fois
*/

int		check_multi_labels(t_list **declare_label,
				   t_list **call_label, char *file_cor)
{
  char		*cmp;
  t_list	*tmp;
  t_list	*tmp2;
  int		found;

  tmp = *declare_label;
  while (tmp)
    {
      cmp = my_strdup(tmp->name);
      tmp2 = *declare_label;
      found = 0;
      while (tmp2)
	{
	  if (!my_strcmp(cmp, tmp2->name))
	    ++found;
	  tmp2 = tmp2->next;
	}
      if (found != 1)
	return (error_multiple_label(declare_label, call_label, file_cor, cmp));
      free(cmp);
      tmp = tmp->next;
    }
  return ((check_label_chars(declare_label, call_label, file_cor))
	  ? (EXIT_FAILURE) : (EXIT_SUCCESS));
}

/*
** En cas de multiple def d'un label => Erreur, free + return
*/

int	error_multiple_label(t_list **declare_label,
			     t_list **call_label, char *file_cor, char *cmp)
{
  my_putstr(RED_BOLD);
  my_error("[Erorr] ", 0);
  my_putstr(INIT);
  my_error("multiple definition of : ", 0);
  my_putstr(BLUE_BOLD);
  my_error(cmp, 0);
  my_putstr(INIT);
  my_error("\n", 0);
  my_free_list(*declare_label);
  my_free_list(*call_label);
  free(file_cor);
  free(cmp);
  return (EXIT_FAILURE);
}
