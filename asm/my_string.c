#include "asm.h"

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
  if (s1[i] != s2[i])
    return (1);
  return (0);
}

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = -1;
  if (!n)
    return (1);
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

  len = my_strlen(src);
  if ((str = malloc(sizeof(char) * (len + 1))) == NULL)
    my_error("Can't perform malloc.\n", 1);
  my_strcpy(str, src);
  return (str);
}
