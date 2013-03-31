/*
** init_vm.c for init_vm in /home/remi/Projet/corewar/corewar
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Thu Jan 24 23:12:01 2013 remi
** Last update Sun Mar 31 18:25:10 2013 guillaume fillon
*/

#include "lib.h"
#include "vm.h"
#include "couleur.h"

/*
** initialisation de la vm.
** malloc de la memoire virtuelle
*/
t_vm		*init_vm(int mem_tmp, t_proc *lproc,
			 int prg_nb, header_t *header)
{
  t_vm		*vm;

  if (mem_tmp > MEM_SIZE || (vm = malloc(sizeof(t_vm))) == NULL)
    my_error("File is too big.\n", 1);
  if ((vm->mem = malloc(sizeof(char) * MEM_SIZE)) == NULL)
    my_error("Can’t perform malloc\n", 1);
  my_memset(vm->prg_alive, 1, 4);
  my_memset(vm->cycle_champion, 0, 4);
  vm->proc = lproc;
  vm->old_live = -1;
  vm->nb_live = 0;
  vm->cycle = 0;
  vm->ctd = CYCLE_TO_DIE;
  vm->prg_nb = prg_nb;
  vm->nb_proc = prg_nb;
  vm->header = header;
  reset_mem(&vm);
  return (vm);
}

/*
** charge les champions dans la memoire.
*/
int	load_champ(char *file, t_vm **vm, header_t *header, int pos_mem)
{
  char	*buf;
  int	size;
  int	pos_buf;

  buf = get_champ(file, &size);
  pos_buf = 0;
  size = pos_mem;
  while (pos_mem + pos_buf < header->prog_size + size)
    {
      (*vm)->mem[(pos_mem + pos_buf) % MEM_SIZE] = buf[pos_buf];
      pos_buf += 1;
    }
  free(buf);
  return (pos_mem + pos_buf);
}

/*
** charge les differents champions et applique les options.
*/
t_proc		*load_champions(t_vm *vm, t_prog *tab,
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
      if (tab[i % 4].load_add >= 0)
	pos_mem = tab[i % 4].load_add % MEM_SIZE;
      add_to_list(&(vm)->proc, pos_mem, i + 1);
      init_option_number_proc(vm->proc, tab[i % 4].prog_numb);
      pos_mem = load_champ(tab[i].prog_name, &vm,
			   &header[i], pos_mem) + interval;
      i = i + 1;
    }
  return (vm->proc);
}

/*
** Demmare la vm => initialisation => execution => free
*/
int		launch_vm(t_proc *lproc, header_t *header,
			  t_prog *tab, int prg_nb)
{
  t_sdl		sdl;
  t_vm		*vm;
  int		i;
  int		mem_tmp;

  i = 0;
  mem_tmp = 0;
  vm = NULL;
  while (i < prg_nb)
    mem_tmp += header[i++].prog_size;
  vm = init_vm(mem_tmp, lproc, prg_nb, header);
  vm->sdl = &sdl;
  if (launch_sdl(&sdl) == EXIT_FAILURE)
   {
      free_vm(vm);
      exit(EXIT_FAILURE);
    }
  vm->option = tab;
  reset_mem(&vm);
  vm->proc = load_champions(vm, tab, header, mem_tmp);
  if (vm->option[0].dump != -1)
    dump_memory(vm);
  sync_cycle(vm);
  free_vm(vm);
  return (0);
}
