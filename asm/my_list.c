/*
** my_list.c for my_list in /home/linard_f//corewar/homework/asm/corewar
**
** Made by fabien linardon
** Login   <linard_f@epitech.net>
**
** Started on  Thu Jan 24 11:17:03 2013 fabien linardon
** Last update Wed Mar 13 14:56:10 2013 nicolas bridoux
*/

#include "asm.h"

/*
** Fonctions de manip des listes chainées, ajoute l'élément en début de liste
*/ 

void		my_put_in_list(t_list **list, char *name, int pos, int pos_label)
{
  t_list	*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    {
      my_free_list(*list);
      my_error("Can't perform malloc.\n", 1);
    }
  elem->name = name;
  elem->pos = pos;
  elem->pos_label = pos_label;
  elem->next = *list;
  *list = elem;
}

/*
** Fonction uniquement de debug pour afficher la liste
*/

void		my_show_list(t_list *list)
{
  t_list	*tmp;

  tmp = list;
  while (tmp)
    {
      my_putstr(tmp->name);
      my_putstr("|");
      my_put_nbr(tmp->pos);
      my_putstr("->");
      tmp = tmp->next;
    }
}
