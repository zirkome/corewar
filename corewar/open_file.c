/*
** open_file.c for iopen_file in /home/robert_r//Corewar/Corewar/vm
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Jan 21 18:34:30 2013 remi robert
** Last update Fri Mar 29 22:35:30 2013 remi
*/

#include <sys/stat.h>
#include <fcntl.h>
#include "lib.h"
#include "vm.h"

/*
** ouvre les champions par rapport au path.
*/
char	*get_champ(char *path, int *size)
{
  char	buf[2];
  char	*file;
  int	fd;
  int	ret;

  file = NULL;
  buf[1] = '\0';
  *size = 0;
  if ((fd = open(path, O_RDONLY)) == -1)
      my_error("File not found\n", 1);
  if (lseek(fd, HEADER_LENGTH, SEEK_CUR) == -1)
    my_error("Error lseek\n", 1);
  ret = 1;
  while ((ret = read(fd, buf, 1)) != 0)
    {
      if (ret == -1)
	my_error("Error read file\n", 1);
      if ((file = realloc(file, (*size + ret) * sizeof(char))) == NULL)
	my_error("Can’t perform malloc\n", 1);
      file[*size] = buf[0];
      *size += ret;
    }
  close(fd);
  return (file);
}

char	*read_file(const int fd, int *nb_carac)
{
  int	ret;
  char	buf[2];
  char	*file;

  *nb_carac = 0;
  file = NULL;
  buf[1] = '\0';
  while ((ret = read(fd, buf, 1)) != 0)
    {
      if (ret == -1)
	my_error("Error read file\n", 1);
      if ((file = realloc(file, *nb_carac + ret)) == NULL)
	my_error("Can't perform malloc\n", 1);
      file[*nb_carac] = buf[0];
      *nb_carac += ret;
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
