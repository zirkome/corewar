/*
** show_list.c for List Lib in /home/fillon_g/ubuntu-bck/projets/minishell1/list
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Sun Dec  9 21:35:11 2012 guillaume fillon
** Last update Sat Jan 19 23:38:32 2013 guillaume fillon
*/

#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <term.h>
#include "list.h"

int		check_list(t_list *l, struct winsize *win)
{
  int		i;
  int		j;
  int		max;
  t_list	*list;

  i = 0;
  j = 0;
  list = l->next;
  max = 0;
  tputs(tgetstr("cl", NULL), 1, my_putchar);
  while (list != l && i < win->ws_col)
    {
      while (list != l && j < win->ws_row - 1)
	{
	  max = MAX(max, my_strlen(list->data->name));
	  list = list->next;
	  j++;
	  if ((i + max) > win->ws_col)
	    return (0);
	}
      i += max + 2;
      max = 0;
      j = 0;
    }
  return (1);
}

void	disp_elem(t_list *list)
{
  if (list->data->selected)
    inv_video_unselect(list->data->name);
  else
    my_fputstr(get_tty(), list->data->name);
}

void		show_list(t_list *l, struct winsize *win)
{
  int		i;
  int		j;
  int		max;
  t_list	*list;

  i = 0;
  j = 0;
  list = l->next;
  max = 0;
  tputs(tgetstr("cl", NULL), 1, my_putchar);
  while (list != l && i < win->ws_col)
    {
      while (list != l && j < win->ws_row - 1)
	{
	  max = MAX(max, my_strlen(list->data->name));
	  tputs(tgoto(tgetstr("cm", NULL), i, j), 1, my_putchar);
	  list->data->col = i;
	  list->data->row = j;
	  disp_elem(list);
	  list = list->next;
	  j++;
	}
      i += max + 2;
      max = 0;
      j = 0;
    }
}
