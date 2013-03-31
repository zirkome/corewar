/*
** my_string.c for my_string.c in /home/bridou_n//corewar
**
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
**
** Started on  Wed Jan 16 17:59:57 2013 nicolas bridoux
** Last update Sat Mar 30 21:49:59 2013 guillaume fillon
*/

#include "lib.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = -1;
  while (s1[++i] && s2[i])
    {
      if (s1[i] < s2[i])
        return (-1);
      if (s1[i] > s2[i])
        return (1);
    }
  if (s1[i] == s2[i])
    return (0);
  return (0);
}

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = -1;
  while (++i < n)
    {
      if (s1[i] < s2[i])
        return (-1);
      if (s1[i] > s2[i])
        return (1);
    }
  return (0);
}

void	my_strcpy(char *dest, char *src)
{
  int	i;

  i = -1;
  while (src[++i])
    dest[i] = src[i];
  dest[i] = '\0';
}

void	my_strcat(char *dest, char *src)
{
  int	len_dest;
  int	k;

  k = -1;
  len_dest = my_strlen(dest);
  while (src[++k])
    dest[len_dest + k] = src[k];
  dest[len_dest + k] = '\0';
}

char	*my_strdup(char *src)
{
  char	*str;
  int	len;

  if (src == NULL)
    return (NULL);
  len = my_strlen(src);
  if ((str = malloc(sizeof(char) * (len + 1))) == NULL)
    my_error("Can not malloc\n", 1);
  my_strcpy(str, src);
  return (str);
}
