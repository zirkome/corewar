/*
** instruction.h for Corewar in /home/fillon_g/projets/groups/corewar/corewar
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Tue Jan 29 07:51:02 2013 guillaume fillon
** Last update Mon Feb 25 08:39:09 2013 remi robert
*/

#ifndef INSTRUCTION_H_
#define INSTRUCTION_H_

typedef struct	s_cmd
{
  char		code;
  int		cycle;
  void		(*f)(t_vm *, t_proc **);
  char		*mnemonique;
}		t_cmd;

extern t_cmd	cmd_tab[];

/*
** instruction
*/
void		op_live(t_vm *vm, t_proc **lproc);
void		op_ld(t_vm *vm, t_proc **lproc);
void		op_st(t_vm *vm, t_proc **lproc);
void		op_add(t_vm *vm, t_proc **lproc);
void		op_sub(t_vm *vm, t_proc **lproc);
void		op_and(t_vm *vm, t_proc **lproc);
void		op_or(t_vm *vm, t_proc **lproc);
void		op_xor(t_vm *vm, t_proc **lproc);
void		op_zjmp(t_vm *vm, t_proc **lproc);
void		op_ldi(t_vm *vm, t_proc **lproc);
void		op_sti(t_vm *vm, t_proc **lproc);
void		op_fork(t_vm *vm, t_proc **lproc);
void		op_lld(t_vm *vm, t_proc **lproc);
void		op_lldi(t_vm *vm, t_proc **lproc);
void		op_lfork(t_vm *vm, t_proc **lproc);
void		op_aff(t_vm *vm, t_proc **lproc);
int		interval_memory(char *cmdn, int i, int interval, int indice);

#endif /* INSTRUCTION_H_ */
