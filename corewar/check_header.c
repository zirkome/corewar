#include "lib.h"
#include "vm.h"

int	little_to_big_endian(int val)
{
  val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF );
  return (val << 16) | ((val >> 16) & 0xFFFF);
}

/*
** Check la validité du header en fonction du .h
*/
header_t	*check_header(const int fd, header_t *header)
{
  int		i;

  i = read(fd, header, sizeof(header_t));
  if (i < sizeof(header_t))
    return (NULL);
  if ((header->magic = little_to_big_endian(header->magic))
      != COREWAR_EXEC_MAGIC)
    return (NULL);
  if (header->prog_name == NULL)
    return (NULL);
  if ((header->prog_size = little_to_big_endian(header->prog_size)) < 0)
    return (NULL);
  if (header->comment == NULL)
    return (NULL);
  return (header);
}
