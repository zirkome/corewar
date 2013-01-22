/*
** print_file.c for print_file in /home/robert_r//Corewar/Corewar/vm
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Jan 21 18:49:13 2013 remi robert
** Last update Tue Jan 22 13:17:28 2013 remi robert
*/

#include "lib.h"
#include "couleur.h"

int	print_file(char *tab, int nb_carac)
{
  int	i;

  i = -1;
  printf("%d\n", nb_carac);
  while (i++ < nb_carac)
    {
      if (i <= 2048)
	printf("%s%s%d%s ", INTENSITE, VERT, tab[i], REZ);
      else
	printf("%X ", tab[i]);
    }
  printf("\n");
  return (0);
}
