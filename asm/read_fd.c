/*
** main.c for main.c in /home/bridou_n//corewar
**
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
**
** Started on  Wed Jan 16 17:57:04 2013 nicolas bridou
** Last update Tue Jan 22 12:55:27 2013 guillaume fillon
*/

#include "asm.h"

char	*read_fd(const int fd)
{
  char	*buffer;
  char	*final;
  int	i;
  int	size_read;

  i = 0;
  if ((buffer = malloc(sizeof(char) * READ + 1)) == NULL)
    my_error("Can not malloc\n", 1);
  while ((size_read = read(fd, &buffer[READ * i], READ)) == READ)
    buffer = realloc(buffer, (++i * READ + READ) * sizeof(char));
  buffer[READ * i + size_read] = '\0';
  final = my_strdup(buffer);
  free(buffer);
  return (final);
}
