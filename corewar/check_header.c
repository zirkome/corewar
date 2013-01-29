/*
** check_header.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Thu Jan 24 21:46:54 2013 guillaume fillon
** Last update Tue Jan 29 18:01:13 2013 remi robert
*/

#include "lib.h"
#include "vm.h"

int		check_magic(char *buf)
{
  int magic;

  magic = ((buf[0] & 0xFF) << 24) + ((buf[1] & 0xFF) << 16)
    + ((buf[2] & 0xFF) << 8) + ((buf[3] & 0xFF) << 0);
  return (magic);
}

char		*check_name(char *buf)
{
  char		name[128 + 1];
  int		i;

  i = 4;
  while (i < PROG_NAME_LENGTH)
    {
      name[i - 4] = buf[i];
      i++;
    }
  return (my_strdup(name));
}

int		check_size(char *buf)
{
  int		size;
  int		i;

  i = PROG_NAME_LENGTH + 8;
  size = ((buf[i] & 0xFF) << 24) + ((buf[i + 1] & 0xFF) << 16)
    + ((buf[i + 2] & 0xFF) << 8) + ((buf[i + 3] & 0xFF) << 0);
  return (size);
}

char		*check_comment(char *buf)
{
  char		comment[2048 + 1];
  int		i;

  i = PROG_NAME_LENGTH + 12;
  while (i < (COMMENT_LENGTH + PROG_NAME_LENGTH + 12))
    {
      comment[i - PROG_NAME_LENGTH - 12] = buf[i];
      i++;
    }
  if ((i - PROG_NAME_LENGTH - 12) !=  2048)
    return (NULL);
  return (my_strdup(comment));
}

header_t	*check_header(const int fd, header_t *header)
{
  int		i;
  header_t	*buf;

  buf = malloc(sizeof(header_t));
  printf ("%lu\n", sizeof(header_t));
  i = read(fd, buf, sizeof(header_t));
  if (i < sizeof(header_t))
    return (NULL);
  printf ("%X\n", buf->magic);
  /* while ((rt = read(fd, &word, 1)) != 0 && i < HEADER_LENGTH) */
  /*   { */
  /*     if (rt == -1) */
  /* 	my_error("Error: Can't read the file.", 1); */
  /*     buf[i++] = word; */
  /*   } */
  /* if (i < HEADER_LENGTH) */
  /*   return (NULL); */
  /* if ((header->magic = check_magic(buf)) != COREWAR_EXEC_MAGIC) */
  /*   return (NULL); */
  /* if ((header->prog_name = check_name(buf)) == NULL) */
  /*   return (NULL); */
  /* if ((header->prog_size = check_size(buf)) <= 0) */
  /*   return (NULL); */
  /* if ((header->comment = check_comment(buf)) == NULL) */
  /*   return (NULL); */
  return (buf);
}
