/*
** main.h for main.h in /home/bridou_n//corewar
**
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
**
** Started on  Wed Jan 16 17:58:40 2013 nicolas bridoux
** Last update Sat Jan 26 11:08:45 2013 remi robert
*/

#ifndef VM_H_
# define VM_H_

# include <stdio.h>
# include <stdlib.h>
# include "op.h"

# define READ 4096

<<<<<<< HEAD
=======
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

>>>>>>> origin
typedef struct	s_options
{
  int		options;
  int		dump_nbr;
  int		prog_nbr;
  int		load_address;
}		t_options;

typedef struct	s_vm
{
  char		*mem;
}		t_vm;

typedef struct	s_param_mem
{
  int		nb_octet;
  int		indice;
}		t_param_mem;

/*
** open_file.c
*/
int		open_file_champion(char *path, header_t *header);
char		*read_file(const int fd, int *nb_carac);
char		*get_champ(char *file, int *size);

/*
** check_header.c
*/
header_t	*check_header(const int fd, header_t *header);

/*
** init_vm.c
*/
<<<<<<< HEAD
int		init_vm(int nb_elem, char **argv, header_t *header);
int		calc_interval(int nb_elem, int total_size);
int		fill_mem(char *file, t_vm **vm, header_t *header, int pos_mem);
void		reset_mem(t_vm **vm);
=======
int	print_file(char *tab, t_champion *champion);
void	print_memory(t_vm *vm);
>>>>>>> origin

/*
** parser.c
*/
<<<<<<< HEAD
void		parser_fct(t_vm *vm);
=======
int	return_number_param(int number);
int	detect_fonction(int number, char *tab, int n);
int	detect_param(int number, char *tab);
>>>>>>> origin

#endif /* LIB_H_ */
