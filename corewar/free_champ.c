/*
** free_champ.c for CoreWar in /home/fillon_g/projets/groups/corewar/corewar
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Sun Jan 27 20:48:10 2013 guillaume fillon
** Last update Thu Mar 28 13:37:42 2013 remi
*/

#include "lib.h"
#include "vm.h"

void		free_champ(header_t *header, int nb)
{
  int		i;

  i = 0;
  while (i < nb)
    {
      /* free(header[i].comment); */
      /* free(header[i].prog_name); */
      free(header);
      i += 1;
    }
  free(header);
}

void	nb_proc_list(t_proc *ptete)
{
  t_proc	*pcourant;
  int		indice;

  pcourant = ptete;
  indice = 0;
  if (ptete == NULL)
    {
      printf("%sNULL = [%d]%s\n", F_ROUGE, 0, REZ);
      return ;
    }
  while (pcourant != NULL)
    {
      pcourant = pcourant->next;
      indice = indice + 1;
    }
  printf("%s[%d]%s\n", F_ROUGE, indice, REZ);
}

void		free_vm(t_vm *vm)
{
  if (vm == NULL)
    return ;
  if (vm->mem != NULL)
    free(vm->mem);
  nb_proc_list(vm->proc);
  /* if (vm->proc != NULL) */
  /*   { */
  /*     while (free_elem_prog(&(vm->proc), 0) == 1); */
  /*     while (free_elem_prog(&(vm->proc), 1) == 1); */
  /*     while (free_elem_prog(&(vm->proc), 2) == 1); */
  /*     while (free_elem_prog(&(vm->proc), 3) == 1); */
  /*     free(vm->proc); */
  /*   } */
  nb_proc_list(vm->proc);
  free(vm);
}
