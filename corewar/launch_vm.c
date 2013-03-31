/*
** init_vm.c for init_vm in /home/remi/Projet/corewar/corewar
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Thu Jan 24 23:12:01 2013 remi
** Last update Sun Mar 31 03:47:29 2013 guillaume fillon
*/

#include "lib.h"
#include "vm.h"
#include "couleur.h"

t_vm		*init_vm(int mem_tmp, t_proc *lproc)
{
  t_vm		*vm;

  if (mem_tmp > MEM_SIZE || (vm = malloc(sizeof(t_vm))) == NULL)
    my_error("File is too big.\n", 1);
  if ((vm->mem = malloc(sizeof(char) * MEM_SIZE)) == NULL)
    my_error("Can’t perform malloc\n", 1);
  vm->prg_alive[0] = 1;
  vm->prg_alive[1] = 1;
  vm->prg_alive[2] = 1;
  vm->prg_alive[3] = 1;
  vm->cycle_champion[0] = 0;
  vm->cycle_champion[1] = 0;
  vm->cycle_champion[2] = 0;
  vm->cycle_champion[3] = 0;
  vm->proc = lproc;
  vm->old_live = -1;
  vm->nb_live = 0;
  vm->cycle = 0;
  vm->cycle_to_die = CYCLE_TO_DIE;
  reset_mem(&vm);
  return (vm);
}

int	load_champ(char *file, t_vm **vm, header_t *header, int pos_mem)
{
  char	*buf;
  int	size;
  int	pos_buf;

  buf = get_champ(file, &size);
  pos_buf = 0;
  size = pos_mem;
  printf("POS_MEM : %d\n", pos_mem);
  while (pos_mem + pos_buf < header->prog_size + size)
    {
      (*vm)->mem[pos_mem + pos_buf] = buf[pos_buf];
      pos_buf += 1;
    }
  free(buf);
  return (pos_mem + pos_buf);
}

t_proc		*load_champions(t_vm *vm,char **argv,
				header_t *header, int mem_tmp)
{
  int		i;
  int		interval;
  int		pos_mem;

  i = 0;
  pos_mem = 0;
  interval = calc_interval(vm->prg_nb, mem_tmp);
  while (i < vm->prg_nb)
    {
      add_to_list(&(vm)->proc, pos_mem, i + 1);
      pos_mem = load_champ(argv[i + 1], &vm, &header[i], pos_mem) + interval;
      i = i + 1;
    }
  return (vm->proc);
}

int		launch_vm(t_proc *lproc, header_t *header,
			  char **argv, int prg_nb)
{
  t_proc	*lproc;
  t_sdl		sdl;
  t_vm		*vm;
  int		i;
  int		mem_tmp;

  i = 0;
  mem_tmp = 0;
  vm = NULL;
  lproc = NULL;
  while (i < prg_nb)
    mem_tmp += header[i++].prog_size;
  vm = init_vm(mem_tmp, lproc);
  vm->prg_nb = prg_nb;
  vm->nb_proc = prg_nb;
  vm->header = header;
  vm->sdl = &sdl;
  vm->proc = load_champions(vm, argv, header, mem_tmp);
  if (launch_sdl(&sdl) == EXIT_FAILURE)
    {
      free_vm(vm);
      exit(EXIT_FAILURE);
    }
  sync_cycle(vm);
  free_vm(vm);
  return (0);
}
