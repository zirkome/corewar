/*
** check_header.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Thu Jan 24 21:46:54 2013 guillaume fillon
** Last update Thu Jan 24 23:44:09 2013 remi
*/

#include "lib.h"
#include "op.h"
#include "vm.h"

header_t	*check_header(const int fd, header_t *header)
{
  int		rt;
  int		i;
  char		word;
  char		buf[HEADER_LENGTH];

  i = 0;
  while ((rt = read(fd, &word, 1)) != 0 && i < HEADER_LENGTH)
    {
      if (rt == -1)
	my_error("Error: Can't read the file.", 1);
      buf[i] = word;
      printf("%X", buf[i++]);
    }
  return (header);
}
