/*
** pop.c for List Lib in /home/fillon_g/ubuntu-bck/projets/minishell1/list
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Sun Dec  9 21:29:40 2012 guillaume fillon
** Last update Tue Jan 29 04:38:23 2013 guillaume fillon
*/

#include "lib.h"
#include "vm.h"

void		pop(t_proc *elem)
{
  elem->prev->next = elem->next;
  elem->next->prev = elem->prev;
  free(elem);
}
