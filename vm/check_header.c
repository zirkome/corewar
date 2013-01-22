/*
** check_header.c for check_header in /home/robert_r//Corewar/Corewar/vm
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Tue Jan 22 10:57:56 2013 remi robert
** Last update Tue Jan 22 12:15:49 2013 remi robert
*/

#include "lib.h"

int	check_magic_code(char *tab, int nb_carac)
{
  int	magic;

  if (nb_carac < COMMENT_LENGTH)
    my_error("Error hearder file\n", 1);
  if (((tab[0] & 0xFF) << 24) + ((tab[1] & 0xFF) << 16)
      + ((tab[2] & 0xFF) << 8) + ((tab[3] & 0xFF)) != COREWAR_EXEC_MAGIC)
    my_error("Error : file not corewar file\n", 1);
  my_putstr("MAGIC PACKET OK\n");
}

char	*extract_name(char *tab, int nb_carac)
{
  char	*name;
  int	i;

  if (nb_carac < COMMENT_LENGTH ||
      (name = malloc(sizeof(128 * sizeof(char *)))) == NULL)
    my_error("Error hearder file\n", 1);
  i = 0;
  while (i <= 128 && tab[i + 4] != 0x0)
    {
      name[i] = tab[i + 4];
      i = i + 1;
    }
  name[i] = '\0';
  return (name);
}
