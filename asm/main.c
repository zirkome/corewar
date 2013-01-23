/*
** main.c for main.c in /home/bridou_n//corewar/asm
** 
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
** 
** Started on  Mon Jan 21 18:27:50 2013 nicolas bridoux
** Last update Tue Jan 22 16:18:33 2013 nicolas bridoux
*/

#include "asm.h"

int	main(int ac, char *av[])
{
  if (ac < 2)
    my_error("Usage : ./asm [file1.s] [file2.s] [...]\n", 1);
  while (ac != 1)
    load(av[--ac]);
  my_putchar('\n');
  return (0);
}

void	load(char *name)
{
  int	fd;
  char	*file;
  int	len_name;

  len_name = my_strlen(name);
  if (len_name > 1 && (name[len_name - 1] != 's' || name[len_name - 2] != '.'))
    {
      my_error(name, 0);
      my_error(" : is not a [.s] file.\n", 1);
    }
  if ((fd = open(name, O_RDONLY)) == -1)
    {
      my_error("Error while openning :", 0);
      my_error(name, 1);
    }
  file = read_fd(fd);
  close(fd);
  if (!check_label(file))
    return;
  my_parsing(file, name);
}
