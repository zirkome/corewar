/*
** push.c for List Lib in /home/fillon_g/ubuntu-bck/projets/minishell1/list
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Sun Dec  9 21:30:11 2012 guillaume fillon
** Last update Tue Jan 15 17:20:15 2013 guillaume fillon
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void		push_before(t_list *elem, t_data *data)
{
  t_list	*new_elem;

  if ((new_elem = (t_list *) malloc(sizeof(*new_elem))) != NULL)
    {
      new_elem->size = elem->prev->size++;
      new_elem->data = data;
      new_elem->prev = elem->prev;
      new_elem->next = elem;
      elem->prev->next = new_elem;
      elem->prev = new_elem;
    }
}

void		push_after(t_list *elem, t_data *data)
{
  t_list	*new_elem;

  if ((new_elem = (t_list *) malloc(sizeof(*new_elem))) != NULL)
    {
      new_elem->size = elem->next->size++;
      new_elem->data = data;
      new_elem->prev = elem;
      new_elem->next = elem->next;
      elem->next->prev = new_elem;
      elem->next = new_elem;
    }
}

void		stack(t_list *root, char *name, char selected)
{
  t_data	*data;

  if ((data = malloc(sizeof(*data))) == NULL)
    exit(EXIT_FAILURE);
  data->name = name;
  data->selected = selected;
  push_after(root, data);
}

void		queue(t_list *root, char *name, char selected)
{
  t_data	*data;

  if ((data = malloc(sizeof(*data))) == NULL)
    exit(EXIT_FAILURE);
  data->name = name;
  data->selected = selected;
  push_before(root, data);
}
