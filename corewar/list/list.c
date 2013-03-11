/*
** list.c for list in /home/remi/Projet/corewar/corewar/corewar
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Mon Mar 11 09:18:32 2013 remi
** Last update Mon Mar 11 15:44:45 2013 remi
*/

#include <stdlib.h>
#include "lib.h"
#include "vm.h"

t_proc	*suppr_elem_list(t_proc **ptete, t_proc **pcourant)
{
  if ((*pcourant)->back == NULL && (*pcourant)->next == NULL)
    {
      free(*pcourant);
      return (NULL);
    }
  if ((*pcourant)->back == NULL)
    {
      *ptete = (*pcourant)->next;
      (*ptete)->back = NULL;
      return (*ptete);
    }
  if ((*pcourant)->next == NULL)
    {
      (*pcourant)->back->next = NULL;
      free(*pcourant);
      return (*ptete);
    }
  (*pcourant)->back->next = (*pcourant)->next;
  (*pcourant)->next->back = (*pcourant)->back;
  free(*pcourant);
  return (*ptete);
}

int		free_elem_prog(t_proc **proc, int prg)
{
  t_proc	*pcourant;

  if (*proc == NULL)
    return (0);
  pcourant = *proc;
  while (pcourant != NULL)
    {
      if (pcourant->reg[0] == prg)
	{
	  *proc = suppr_elem_list(proc, &pcourant);
	  return (1);
	}
      pcourant = pcourant->next;
    }
  return (0);
}

void		init_elem(t_proc **new_elem, int pc, int cid)
{
  init_reg((*new_elem)->reg, cid);
  (*new_elem)->wait = -1;
  (*new_elem)->carry = 1;
  (*new_elem)->pc = pc;
}

void		add_to_list(t_proc **proc, int pc , int cid)
{
  t_proc	*pcourant;
  t_proc	*elem;

  if ((*proc) == NULL)
    {
      if (((*proc) = malloc(sizeof(t_proc))) == NULL)
	return ;
      init_elem(proc, pc, cid);
      (*proc)->next = NULL;
      (*proc)->back = NULL;
      return ;
    }
  if ((elem = malloc(sizeof(t_proc))) == NULL)
    return ;
  pcourant = (*proc);
  while (pcourant->next != NULL)
    pcourant = pcourant->next;
  init_elem(&elem, pc, cid);
  elem->next = NULL;
  elem->back = pcourant;
  pcourant->next = elem;
}
