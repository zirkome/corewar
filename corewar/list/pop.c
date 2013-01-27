/*
** pop.c for List Lib in /home/fillon_g/ubuntu-bck/projets/minishell1/list
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Sun Dec  9 21:29:40 2012 guillaume fillon
** Last update Sun Jan 27 01:14:52 2013 guillaume fillon
*/

#include "lib.h"
#include "vm.h"

void		pop(t_proc *elem)
{
  elem->prev->next = elem->next;
  elem->next->prev = elem->prev;
  free(elem);
}
