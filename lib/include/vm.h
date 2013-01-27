/*
** main.h for main.h in /home/bridou_n//corewar
**
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
**
** Started on  Wed Jan 16 17:58:40 2013 nicolas bridoux
<<<<<<< HEAD
** Last update Sun Jan 27 21:41:17 2013 guillaume fillon
=======
** Last update Sun Jan 27 20:51:20 2013 guillaume fillon
>>>>>>> 088b414518fce5c4187a72d1a7e955a765534a10
*/

#ifndef VM_H_
# define VM_H_

# include <stdio.h>
# include <stdlib.h>
# include "op.h"

# define READ 4096

typedef char    mem_t;

typedef struct	s_options
{
  int		options;
  int		dump_nbr;
  int		prog_nbr;
  int		load_address;
}		t_options;

typedef struct	s_proc
{
  int		pid;
  int		reg[REG_NUMBER];
  int		pc;
  struct s_proc	*next;
  struct s_proc	*prev;
}		t_proc;

typedef struct	s_vm
{
  char		*mem;
}		t_vm;


/*
** tmp
*/
void		free_champ(header_t *header, int nb);

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
int		init_vm(t_proc *l_proc, header_t *header, char **av, int nb_ch);
int		calc_interval(int nb_elem, int total_size);
int		fill_mem(char *file, t_vm **vm, header_t *header, int pos_mem);
void		reset_mem(t_vm **vm);

/*
** parser.c
*/
void		parser(t_vm *vm);

/*
** doubly linked list
*/
t_proc		*create_list(void);
void		free_proc(t_proc *lproc);
void		queue(t_proc *root, int pc, int cid);
void		pop(t_proc *elem);

#endif /* VM_H_ */
