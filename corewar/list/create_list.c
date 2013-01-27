/*
** create_list.c for listlib in /home/fillon_g/projets/my_select/list
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Fri Jan 11 16:33:52 2013 guillaume fillon
** Last update Sun Jan 27 01:15:06 2013 guillaume fillon
*/

#include <stdlib.h>
#include "lib.h"
#include "vm.h"

t_proc		*create_list(void)
{
  t_proc	*root;

  if ((root = (t_proc *) malloc(sizeof(*root))) == NULL)
    {
      exit(EXIT_FAILURE);
    }
  if (root != NULL)
    {
      root->prev = root;
      root->next = root;
    }
  return (root);
}
