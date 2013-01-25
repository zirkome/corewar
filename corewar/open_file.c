/*
** open_file.c for iopen_file in /home/robert_r//Corewar/Corewar/vm
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Jan 21 18:34:30 2013 remi robert
** Last update Fri Jan 25 13:25:10 2013 remi robert
*/

#include <sys/stat.h>
#include <fcntl.h>
#include "lib.h"
#include "op.h"
#include "vm.h"

char	*return_buf_mem(char *file, int *size)
{
  char	buf[2];
  char	*tab;
  int	fd;
  int	size_tab;
  int	ret;

  tab = NULL;
  buf[1] = '\0';
  size_tab = 0;
  *size = 0;
  if ((fd = open(file, O_RDONLY)) == -1)
    my_error("File not found\n", 1);
  if (lseek(fd, 2192, SEEK_CUR) == -1)
    my_error("Error lseek\n", 1);
  ret = 1;
  while ((ret = read(fd, buf, 1)) != 0)
    {
      if (ret == -1)
	my_error("Error read file\n", 1);
      if ((tab = realloc(tab, (*size + ret) * sizeof(char))) == NULL)
	my_error("Error malloc\n", 1);
      tab[*size] = buf[0];
      *size = *size + ret;
    }
  *size = size_tab;
  close(fd);
  return (tab);
}

char	*read_file(const int fd, int *nb_carac)
{
  int	size_read;
  char	buff[2];
  char	*file;

  *nb_carac = 0;
  size_read = 1;
  file = NULL;
  buff[1] = '\0';
  while ((size_read = read(fd, buff, 1)) != 0)
    {
      if (size_read == -1)
	my_error("Error read file\n", 1);
      if ((file = realloc(file, *nb_carac + size_read)) == NULL)
	my_error("Can't perform malloc\n", 1);
      file[*nb_carac] = buff[0];
      *nb_carac = *nb_carac + size_read;
    }
  return (file);
}

int	open_file_champion(char *path, header_t *header)
{
  int	fd;

  if ((fd = open(path, O_RDONLY)) == -1)
    {
      my_error("File ", 0);
      my_error(path, 0);
      my_error(" not accessible\n", 1);
    }
  if ((header = check_header(fd, header)) == NULL)
    {
      my_error(path, 0);
      my_error(" is not a corewar executable\n", 1);
    }
  close(fd);
  return (0);
}
