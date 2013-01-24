/*
** main.h for main.h in /home/bridou_n//corewar
**
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
**
** Started on  Wed Jan 16 17:58:40 2013 nicolas bridoux
** Last update Tue Jan 22 18:47:21 2013 guillaume fillon
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
  int		nb_cmd;
}		t_champion;

typedef char    mem_t;

typedef struct	s_vm
{
  mem_t		*mem;
  int		size_rempl;
}t_vm;

typedef struct	s_options
{
  int		options;
  int		dump_nbr;
  int		prog_nbr;
  int		load_address;
}		t_options;

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
char	*extract_comment(char *tab, int nb_carac, int *nb_cmd);

/*
** print_file.c
*/
int	print_file(char *tab, t_champion *champion);
void	print_memory(t_vm *vm);

/*
** check_command.c
*/
int	return_number_param(int number);
int	detect_fonction(int number, char *tab, int n);
int	detect_param(int number, char *tab);

#endif /* LIB_H_ */
