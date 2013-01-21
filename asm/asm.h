/*
** main.h for main.c in /home/bridou_n//putchar
** 
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
** 
** Started on  Thu Jan 17 16:25:45 2013 nicolas bridoux
** Last update Mon Jan 21 18:41:43 2013 nicolas bridoux
*/

#ifndef ASM_H_
# define ASM_H_

# define READ 4096

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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

#endif /* ASM_H_ */
