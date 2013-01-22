/*
** main.h for main.h in /home/bridou_n//corewar
**
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
**
** Started on  Wed Jan 16 17:58:40 2013 nicolas bridoux
** Last update Tue Jan 22 15:07:53 2013 remi robert
*/

#ifndef VM_H_
# define VM_H_

# include <stdio.h>
# include <stdlib.h>

# define READ 4096

typedef struct	s_champion
{
  int		nb_carac;
  char		*file;
  char		*name;
}		t_champion;

/*
** open_file.c
*/
t_champion	*open_file_champion(char *path, t_champion *champion);
char		*read_file(const int fd, int *nb_carac);

/*
** check_header.c
*/
int	check_magic_code(char *tab, int nb_carac);
char	*extract_name(char *tab, int nb_carac);
char	*extract_comment(char *tab, int nb_carac);

/*
** print_file.c
*/
int	print_file(char *tab, int nb_carac);

/*
** check_command.c
*/
int	detect_fonction(int number, char *tab);
int	detect_param(int number, char *tab);

#endif /* LIB_H_ */
