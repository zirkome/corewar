/*
** check_header.c for check_header in /home/robert_r//Corewar/Corewar/vm
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Tue Jan 22 10:57:56 2013 remi robert
** Last update Tue Jan 22 16:09:33 2013 remi robert
*/

#include "op.h"
#include "lib.h"

int	check_magic_code(char *tab, int nb_carac)
{
  if (nb_carac < COMMENT_LENGTH)
    my_error("Error header file\n", 1);
  my_putstr("MAGIC NUMBER : ");
  if (((tab[0] & 0xFF) << 24) + ((tab[1] & 0xFF) << 16)
      + ((tab[2] & 0xFF) << 8) + ((tab[3] & 0xFF)) != COREWAR_EXEC_MAGIC)
    my_error("fail\n", 1);
  my_putstr("OK\n");
  return (0);
}

char	*extract_comment(char *tab, int nb_carac, int *nb_cmd)
{
  int	i;

  if (nb_carac < COMMENT_LENGTH)
    my_error("Error header file\n", 1);
  *nb_cmd = ((tab[126 + 12] & 0xFF) << 8) + (tab[127 + 12] & 0xFF);
  i = 128 + 12;
  my_putstr("COMMENT : ");
  while (i < COMMENT_LENGTH)
    {
      if ((tab[i] & 0xFF) < 127 && (tab[i] & 0xFF) >= 32)
	my_putchar(tab[i]);
      i = i + 1;
    }
  my_putstr("\n");
  return (tab);
}

char	*extract_name(char *tab, int nb_carac)
{
  char	*name;
  int	i;

  if (nb_carac < COMMENT_LENGTH ||
      (name = malloc(sizeof(128 * sizeof(char *)))) == NULL)
    my_error("Error hearder file\n", 1);
  i = 0;
  while (i < 128 && tab[i + 4] != 0x0)
    {
      name[i] = tab[i + 4];
      i = i + 1;
    }
  name[i] = '\0';
  return (name);
}
