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

int	print_file(char *tab, t_champion *champion)
{
  int	i;
  int	n;

  i = 0;
  printf("%d\n", champion->nb_carac);
  printf("%s%s%X%s ", INTENSITE, VERT, ((tab[i] & 0xFF) << 24) 
	 + ((tab[i + 1] & 0xFF) << 16) + ((tab[i + 2] & 0xFF) << 8)
	 + ((tab[i + 3] & 0xFF)), REZ);
  i = 3;
  while (i < COMMENT_LENGTH)
    {
      printf("%s%s%X%s ", INTENSITE, BLEU, tab[i] & 0xFF, REZ);
      i = i + 1;
    }
  i = champion->nb_carac - champion->nb_cmd;
  n = 0;
  while (i < champion->nb_carac)
    {
	  /* printf("%s%s%X%s ", INTENSITE, JAUNE, tab[i] & 0xFF, REZ); */
	  /* n = tab[i] & 0xFF; */
	  /* if (n >= 0x01 && n <= 0x10) */
	  /*   i = i + detect_fonction(n - 1 , &tab[i]); */
      printf("%X ", tab[i] & 0xFF);
      i += 1;
      n = n + 1;
    }
  printf("\n");
  printf("Nb incrementation : %d\n", n);
  return (0);
}
