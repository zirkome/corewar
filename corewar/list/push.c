/*
** push.c for List Lib in /home/fillon_g/ubuntu-bck/projets/minishell1/list
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Sun Dec  9 21:30:11 2012 guillaume fillon
** Last update Wed Mar 20 09:16:56 2013 remi
*/

#include "lib.h"
#include "vm.h"

void		push_before(t_proc *elem, int pc, int cid)
{
  t_proc	*new_elem;

 if ((new_elem = (t_proc *) malloc(sizeof(*new_elem))) != NULL)
    {
      init_reg(new_elem->reg, cid);
      new_elem->wait = -1;
      new_elem->carry = 0;
      new_elem->pc = pc;
      new_elem->prev = elem->prev;
      new_elem->next = elem;
      elem->prev->next = new_elem;
      elem->prev = new_elem;
#ifdef DEBUG
      printf ("r1:%d\n", new_elem->reg[0]);
      printf ("PC:%d\n\n", new_elem->pc);
#endif
    }
}

void		queue(t_proc **root, int pc, int cid)
{
  push_before(*root, pc, cid);
}
