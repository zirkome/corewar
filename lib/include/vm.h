/*
** main.h for main.h in /home/bridou_n//corewar
**
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
**
** Started on  Wed Jan 16 17:58:40 2013 nicolas bridoux
** Last update Mon Jan 28 22:45:04 2013 remi robert
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
  int		cycle;
  int		pid;
  char		param[17];
  char		instruction;
  int		reg[REG_NUMBER];
  int		pc;
  int		carry : 4;
  struct s_proc	*next;
  struct s_proc	*prev;
}		t_proc;

typedef struct	s_vm
{
  char		nb_ch;
  char		is_ch_alive[4];
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
** init_vm.c
*/
int		calc_interval(int nb_elem, int total_size);
int		fill_mem(char *file, t_vm **vm, header_t *header, int pos_mem);
void		reset_mem(t_vm **vm);
t_vm		*init_vm(int mem_tmp, t_proc *lproc);
int		launch_vm(t_proc *l_proc, header_t *header, char **av, int nb_ch);
void		init_reg(int *buf, int cid);

/*
** parser.c
*/
void		parser(t_vm *vm, t_proc *l_proc);
void		rempl_param(t_proc *lproc, char *buf);

/*
** doubly linked list
*/
t_proc		*create_list(void);
void		free_proc(t_proc *lproc);
void		queue(t_proc *root, int pc, int cid);
void		pop(t_proc *elem);

/*
** run_cylce.c
*/
void		run_cycle(t_vm *vm);

/*
** instruction
*/
void		op_live(t_vm *vm, t_proc *lproc);
void		op_ld(t_vm *vm, t_proc *lproc);
void		op_st(t_vm *vm, t_proc *lproc);
void		op_add(t_vm *vm, t_proc *lproc);
void		op_sub(t_vm *vm, t_proc *lproc);
void		op_and(t_vm *vm, t_proc *lproc);
void		op_or(t_vm *vm, t_proc *lproc);
void		op_xor(t_vm *vm, t_proc *lproc);
void		op_zjmp(t_vm *vm, t_proc *lproc);
void		op_ldi(t_vm *vm, t_proc *lproc);
void		op_sti(t_vm *vm, t_proc *lproc);
void		op_fork(t_vm *vm, t_proc *lproc);
void		op_lld(t_vm *vm, t_proc *lproc);
void		op_lldi(t_vm *vm, t_proc *lproc);
void		op_lfork(t_vm *vm, t_proc *lproc);
void		op_aff(t_vm *vm, t_proc *lproc);

#endif /* VM_H_ */
