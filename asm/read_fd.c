/*
** main.c for main.c in /home/bridou_n//corewar
**
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
**
** Started on  Wed Jan 16 17:57:04 2013 nicolas bridou
** Last update Wed Mar 13 15:34:32 2013 nicolas bridoux
*/

#include "asm.h"

/*
** Fonction qui retourne un char *, contenu du fd passé en param
** fais le café.
*/

char	*read_fd(const int fd)
{
  char	*buffer;
  char	*buffer_realloc;
  char	*final;
  int	i;
  int	size_read;

  i = 0;
  if ((buffer = malloc(sizeof(char) * READ + 1)) == NULL)
    my_error("Can not malloc\n", 1);
  while ((size_read = read(fd, &buffer[READ * i], READ)) == READ)
    {
      buffer_realloc = realloc(buffer, (++i * READ + READ) * sizeof(char));
      if (!buffer_realloc)
	{
	  close(fd);
	  my_error("Can't perform malloc\n", 1);
	}
      buffer = buffer_realloc;
    }
  buffer[READ * i + size_read] = '\0';
  final = my_strdup(buffer);
  free(buffer);
  return (final);
}

int	my_getnbr(char *str)
{
  int	sign;
  int	result;

  sign = 1;
  result = 0;
  while (*str == '-' || *str == '+')
    {
      if (*str == '-')
	sign = - sign;
      str = str + 1;
    }
  while (*str != '\0' && *str >= '0' && *str <= '9')
    {
      result = result * 10 + *str - 48;
      str = str + 1;
    }
  if (*str && *str != ',')
    return (0);
  if (sign == -1)
    result = - result;
  return (result);
}

/*
** Cette fonction decale toute la chaine d'un caractère à partir de i.
*/

void	shift_string(char *str, int i)
{
  while (str[i])
    {
      str[i] = str[i + 1];
      ++i;
    }
}
