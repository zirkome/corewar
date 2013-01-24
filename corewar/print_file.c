/*
** print_file.c for print_file in /home/robert_r//Corewar/Corewar/vm
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Jan 21 18:49:13 2013 remi robert
** Last update Tue Jan 22 23:11:45 2013 guillaume fillon
*/

#include "vm.h"
#include "lib.h"
#include "op.h"
#include "couleur.h"

void	print_memory(t_vm *vm)
{
  int	i;

  i = 0;
  while (i++ < vm->size_rempl)
    printf("%X ", vm->mem[i]);
  printf("\n");
}

int	print_file(char *tab, t_champion *champion)
{
  int	i;
  int	n;

  i = 0;
  printf("%d\n", champion->nb_carac);
  printf("%s%s%X%s \n\n", INTENSITE, VERT, ((tab[i] & 0xFF) << 24) 
	 + ((tab[i + 1] & 0xFF) << 16) + ((tab[i + 2] & 0xFF) << 8)
	 + ((tab[i + 3] & 0xFF)), REZ);
  i = 3;
  while (i < COMMENT_LENGTH)
    {
      //printf("%s%s%X%s ", INTENSITE, BLEU, tab[i] & 0xFF, REZ);
      i = i + 1;
    }
  n = 0;
  printf("[%d] ", i);
  i = champion->nb_carac - champion->nb_cmd;
  while (i < champion->nb_carac)
    {
      n = tab[i] & 0xFF;
      /* if (n <= 16) */
      /* 	{ */
      /* 	  4printf("%s%s%X%s ", INTENSITE, ROUGE, n, REZ); */
      /* 	  i = i + return_number_param(n); */
      /* 	  printf("[%d] ", i); */
      /* 	} */
      /* else */
      /* 	{ */
      /* 	  //i = i + detect_fonction(i, &tab[i], n - 1); */
      printf("%s%s%X%s ", INTENSITE, VERT, n, REZ);
	  i = i + 1;
	  //}
    }
  printf("\n");
  return (0);
}
