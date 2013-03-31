/*
** main.h for main.h in /home/bridou_n//corewar
**
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
**
** Started on  Wed Jan 16 17:58:40 2013 nicolas bridoux
** Last update Sun Mar 31 18:45:28 2013 guillaume fillon
*/

#ifndef LIB_H_
# define LIB_H_

# define DEBUG

# include <stdlib.h>
# include <unistd.h>

void	my_putchar(char c);
void	my_putstr(char *str);
void	my_put_nbr(int nb);
void	my_error(char *str, int nb);
int	my_strlen(char *str);
int	my_strcmp(char *s1, char *s2);
void	my_strcpy(char *dest, char *src);
int	my_strncmp(char *s1, char *s2, int n);
char	*my_strdup(char *str);
char	*my_itoa(int i, char b[]);
void	my_strcat(char *dest, char *src);
void	*my_memset(void *s, int c, size_t n);

#endif /* LIB_H_ */
