/*
** main.h for main.h in /home/bridou_n//corewar
**
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
**
** Started on  Wed Jan 16 17:58:40 2013 nicolas bridoux
** Last update Mon Jan 21 19:46:46 2013 remi robert
*/

#ifndef LIB_H_
# define LIB_H_

# include <stdio.h>
# include <stdlib.h>
# include "../lib/include/op.h"

void	my_putchar(char c);
void	my_putstr(char *str);
void	my_put_nbr(int nb);
void	my_error(char *str, int nb);
int	my_strlen(char *str);
int	my_strcmp(char *s1, char *s2);
void	my_strcpy(char *dest, char *src);
int	my_strncmp(char *s1, char *s2, int n);
char	*my_strdup(char *str);
char	*read_fd(int fd, int *nb_carac);

#endif /* LIB_H_ */
