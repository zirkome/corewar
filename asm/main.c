/*
** main.c for main.c in /home/bridou_n//corewar/asm
**
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
**
** Started on  Mon Jan 21 18:27:50 2013 nicolas bridoux
** Last update Wed Mar 27 19:55:27 2013 guillaume fillon
*/

#include "asm.h"

int	main(int ac, char *av[])
{
  if (ac < 2)
    my_error("Usage : ./asm [file1.s] [file2.s] [...]\n", 1);
  while (ac != 1)
    load(av[--ac]);
  return (EXIT_SUCCESS);
}

/*
** Cette fonction charge le fichier en mémoire, et l'envoit à la compilation.
*/

void	load(char *name)
{
  int	len_name;
  char	*new_name;

  len_name = my_strlen(name);
  if (len_name > 1 && (name[len_name - 1] != 's' || name[len_name - 2] != '.'))
    {
      if ((new_name = malloc(sizeof(char) * len_name + 3)) == NULL)
	my_error("Can't perform malloc.\n", 1);
      my_strcpy(new_name, name);
      my_strcat(new_name, ".s");
    }
  else
    new_name = my_strdup(name);
  check_file(new_name);
}

/*
** Vérifie simplement qu'on peux ouvrir le fichier passé en parametre
** si oui, elle le lis et le referme.
*/

void	check_file(char *new_name)
{
  int	fd;
  char	*file;

  if ((fd = open(new_name, O_RDONLY)) == -1)
    {
      my_putstr(RED_BOLD);
      my_error("[ERROR] ", 0);
      my_putstr(INIT);
      my_error("file :", 0);
      my_error(new_name, 0);
      free(new_name);
      my_error(" not accessible.\n", 0);
      return;
    }
  file = read_fd(fd);
  close(fd);
  my_putstr(CYAN_BOLD);
  my_putstr("Compiling :");
  my_putstr(INIT);
  my_putstr(new_name);
  my_putchar('\n');
  my_parsing(file, new_name);
  free(new_name);
}
