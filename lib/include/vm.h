/*
** main.h for main.h in /home/bridou_n//corewar
**
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
**
** Started on  Wed Jan 16 17:58:40 2013 nicolas bridoux
** Last update Thu Jan 24 23:50:58 2013 remi
*/

#ifndef VM_H_
# define VM_H_

# include <stdio.h>
# include <stdlib.h>
# include "op.h"

# define READ 4096

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
int	open_file_champion(char *path, header_t *header);
char	*read_file(const int fd, int *nb_carac);

/*
** check_header.c
*/
header_t	*check_header(const int fd, header_t *header);

#endif /* LIB_H_ */
