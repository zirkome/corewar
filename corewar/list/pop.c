/*
** pop.c for List Lib in /home/fillon_g/ubuntu-bck/projets/minishell1/list
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Sun Dec  9 21:29:40 2012 guillaume fillon
** Last update Sat Jan 19 23:54:41 2013 guillaume fillon
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

void		pop(t_list *elem)
{
  elem->prev->next = elem->next;
  elem->next->prev = elem->prev;
  free(elem->data);
  free(elem);
}
