/*
** debug.c for debug in /home/remi/Projet/save_projet/corewar/corewar
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Thu Mar 28 17:05:43 2013 remi
** Last update Sun Mar 31 13:33:12 2013 guillaume fillon
*/

#include "lib.h"
#include "vm.h"

void		actualize_memory(t_vm *vm, t_proc **lproc, int address)
{
  static int	pc_color[] = {0xFF0000, 0x00FF00, 0x0000FF, 0xFFE600};
  static int	cmd_color[] = {0xFF6666, 0x66FF66, 0x6666FF, 0xFBEC5D};
  static int	first = 1;
  int		i;

  i = -1;
  if (first == 1 && !(first = 0))
    display_mem_grid(vm, *lproc);
  else
    {
      display_octet(vm->sdl->screen, pc_color[(*lproc)->nb_proc % 4],
		    (*lproc)->pc % 113, (*lproc)->pc / 113);
      if ((*lproc)->code == 0x03 || (*lproc)->code == 0x0B)
	{
	  while (++i < 4)
	    {
	      display_octet(vm->sdl->screen, cmd_color[(*lproc)->nb_proc % 4],
			    (((*lproc)->pc + address + i) % MEM_SIZE) % 113,
			    (((*lproc)->pc + address + i) % MEM_SIZE) / 113);
	    }
	}
    }
}

void			actualize_data(t_vm *vm, t_proc **lproc)
{
  SDL_Rect		pos;
  SDL_Surface		*surface;

  pos.x = 50;
  pos.y = HEIGHT - SIDEBAR_SIZE;
  surface = SDL_CreateRGBSurface(SDL_HWSURFACE, 400,
				 SIDEBAR_SIZE - 15, 32, 0, 0, 0, 0);
  SDL_FillRect(surface, NULL, SDL_MapRGB(vm->sdl->screen->format, 0, 0, 0));
  SDL_BlitSurface(surface, NULL, vm->sdl->screen, &pos);
  SDL_FreeSurface(surface);
  display_data(vm->sdl->screen, vm->cycle, &display_cycle, "Cycle : ");
  display_data(vm->sdl->screen, vm->ctd, &display_ctd, "Cycle to die : ");
  display_data(vm->sdl->screen, vm->nb_proc, &display_nb_proc,
	       "Number of procs : ");
  display_data(vm->sdl->screen, vm->nb_live, &display_nb_live,
	       "Number of live : ");
}

void	debug(t_vm *vm, t_proc **lproc, int address)
{
  my_putstr(INTENSITE);
  my_putstr("[wait : ");
  my_put_nbr(vm->cycle_champion[(*lproc)->nb_proc % 4]);
  my_putstr("] ");
  my_putstr("[cycle : ");
  my_put_nbr(vm->cycle);
  my_putstr("] ");
  my_putstr(BLEU);
  my_putstr("[N°proc : ");
  my_put_nbr((*lproc)->num_proc + 1);
  my_putstr("] ");
  my_putstr(CYAN);
  my_putstr("[Champion ");
  my_put_nbr((*lproc)->nb_proc + 1);
  my_putstr("] ");
  my_putstr(REZ);
  my_putstr(op_tab[((*lproc)->code - 1) % REG_NUMBER].mnemonique);
  my_putstr("\n");
  actualize_memory(vm, lproc, address);
  actualize_data(vm, lproc);
  if (SDL_Flip(vm->sdl->screen) == -1)
    return ;
}
