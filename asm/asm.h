/*
** main.h for main.c in /home/bridou_n//putchar
** 
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
** 
** Started on  Thu Jan 17 16:25:45 2013 nicolas bridoux
** Last update Tue Jan 22 16:13:46 2013 nicolas bridoux
*/

#ifndef ASM_H_
# define ASM_H_

# define READ 4096

# include "op.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

void	my_putchar(char c);
void	my_putstr(char *str);
void	my_error(char *str, int quit);
int	my_strlen(char *str);
void	my_strcat(char *s1, char *s2);
int	my_strcmp(char *s1, char *s2);
void	my_put_nbr(int nb);
int	my_getnbr(char *str);
int	my_strncmp(char *s1, char *s2, int n);
void	my_strcpy(char *dest, char *src);
char	*my_strdup(char *str);
char	*read_fd(const int fd);
void	load(char *name);
void	my_parsing(char *file, char *name);

/* check_label.c */
int	check_label(char *file);
int	label_exist(char *label, char *file, int line);
int	fill_label(char *file, int *i, int *line);

#endif /* ASM_H_ */
