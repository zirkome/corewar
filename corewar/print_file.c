/*
** print_file.c for print_file in /home/robert_r//Corewar/Corewar/vm
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Jan 21 18:49:13 2013 remi robert
** Last update Tue Jan 22 16:09:07 2013 remi robert
*/

#include "vm.h"
#include "lib.h"
#include "op.h"
#include "couleur.h"

int	print_file(char *tab, int nb_carac)
{
  int	i;
  int	n;

  i = 0;
  printf("%d\n", nb_carac);
  while (i < nb_carac)
    {
      if (i < 1)
	{
	  printf("%s%s%X%s ", INTENSITE, VERT, ((tab[i] & 0xFF) << 24)
		 + ((tab[i + 1] & 0xFF) << 16) + ((tab[i + 2] & 0xFF) << 8)
		 + ((tab[i + 3] & 0xFF)), REZ);
	  i += 4;
	}
      else if (i >= 4 && i < COMMENT_LENGTH)
	{
	  printf("%s%s%X%s ", INTENSITE, BLEU, tab[i] & 0xFF, REZ);
	}
      else
	{
	  n = tab[i] & 0xFF;
	  if (n >= 0x01 && n <= 0x10)
	    i = i + detect_fonction(n - 1, &tab[i]);
	  else
	    printf("%X ", tab[i] & 0xFF);
	}
      i += 1;
    }
  printf("\n");
  return (0);
}
