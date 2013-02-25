/*
** main.h for main.h in /home/bridou_n//corewar
**
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
**
** Started on  Wed Jan 16 17:58:40 2013 nicolas bridoux
** Last update Mon Feb 25 10:17:06 2013 remi robert
*/

#ifndef VM_H_
# define VM_H_

# include <stdio.h>
# include <stdlib.h>
# include "op.h"
# include "couleur.h"

# define READ 4096

typedef struct	s_options
{
  int		options;
  int		dump_nbr;
  int		prog_nbr;
  int		load_address;
}		t_options;

typedef struct	s_proc
{
  char		carry;
  int		code;
  char		cmd[17];
  int		reg[REG_NUMBER];
  int		pc;
  int		wait;
  struct s_proc	*next;
  struct s_proc	*prev;
}		t_proc;

typedef struct	s_vm
{
  char		prg_nb;
  char		prg_alive[4];
  char		nbr_live;
  int		cycle;
  char		*mem;
  t_proc	*proc;
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
** vm_utils.c
*/
int		calc_interval(int nb_elem, int total_size);
void		reset_mem(t_vm **vm);
void		dump_memory(t_vm *vm);
void		init_reg(int *buf, int cid);

/*
** init_vm.c
*/
int		load_champ(char *file, t_vm **vm, header_t *header, int pos_mem);
t_vm		*init_vm(int mem_tmp, t_proc *lproc);
int		launch_vm(t_proc *l_proc, header_t *header, char **av, int nb_ch);

/*
** parser.c
*/
void		parser(t_vm *vm, t_proc **l_proc);

/*
** doubly linked list
*/
t_proc		*create_list(void);
void		free_proc(t_proc *lproc);
void		queue(t_proc **root, int pc, int cid);
void		pop(t_proc *elem);

/*
** run_cycle.c
*/
void		sync_cycle(t_vm *vm);
int		handle_schedule(t_vm **vm);
int		exec_instruction(t_vm *vm, t_proc **proc);
int		get_cmd(char code);

/*
** instruction / interval_mem.c
*/
int		interval_memory(char *cmd, int i, int interval, int indice);

#endif /* VM_H_ */
