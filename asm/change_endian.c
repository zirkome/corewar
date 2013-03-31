/*
** change_endian.c for change_endian.c in /home/bridou_n/corewar
** 
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
** 
** Started on  Wed Mar 13 23:26:54 2013 nicolas bridoux
** Last update Wed Mar 20 14:35:36 2013 nicolas bridoux
*/

#include "asm.h"

/*
** Cette fonction change l'endian, sa inverse tout les octet des deux int.
*/
void	change_endian(header_t *header)
{
  int	tmp;
  char	dev;

  tmp = header->magico;
  header->magico = 0;
  dev = -8;
  while ((dev += 8) != sizeof(int) * 8)
    {
      header->magico <<= 8;
      header->magico |= ((tmp >> dev) & 0xFF);
    }
  tmp = header->prog_size;
  header->prog_size = 0;
  dev = -8;
  while ((dev += 8) != sizeof(int) * 8)
    {
      header->prog_size <<= 8;
      header->prog_size |= ((tmp >> dev) & 0xFF);
    }
}
