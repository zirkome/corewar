/*
** debug.c for debug in /home/remi/Projet/save_projet/corewar/corewar
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Thu Mar 28 17:05:43 2013 remi
** Last update Sun Mar 31 09:15:46 2013 guillaume fillon
*/

#include "lib.h"
#include "vm.h"

void		display_intro(char *label, char type, SDL_Surface *screen)
{
  static SDL_Color	fg = {0, 255, 0};
  TTF_Font		*font1;
  TTF_Font		*font2;
  SDL_Surface		*surface;
  SDL_Rect		pos;

  font1 = TTF_OpenFont("game_over.ttf", FONT_SIZE1);
  font2 = TTF_OpenFont("game_over.ttf", FONT_SIZE2);
  surface = TTF_RenderText_Blended((type == 0) ? font1 : font2, label, fg);
  pos.x = (type == 0 || type == 2) ?
    (WIDTH / 2) - (surface->w / 2) : WIDTH - surface->w - 3;
  if (type == 0)
    pos.y = HEIGHT - SIDEBAR_SIZE - (surface->h / 10);
  else if (type == 1)
    pos.y = HEIGHT - surface->h;
  else if (type == 2)
    pos.y = HEIGHT - surface->h - 20;
  SDL_BlitSurface(surface, NULL, screen, &pos);
  SDL_FreeSurface(surface);
  TTF_CloseFont(font1);
  TTF_CloseFont(font2);
}

void			display_sidebar(SDL_Surface *screen)
{
  SDL_Surface		*surface;
  SDL_Rect		pos;

  SDL_FillRect(screen, NULL, 0x000000);
  pos.x = 0;
  pos.y = HEIGHT - SIDEBAR_SIZE;
  surface = SDL_CreateRGBSurface(SDL_HWSURFACE, WIDTH, SIDEBAR_SIZE, 32, 0, 0, 0, 0);
  SDL_FillRect(surface, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
  SDL_BlitSurface(surface, NULL, screen, &pos);
  SDL_FreeSurface(surface);
  display_intro("CoreWar", 0, screen);
  display_intro("v1.0 build 151", 1, screen);
  display_intro("Made by Remi Robert, " \
		"Guillaume Fillon, Nicolas Bridoux" \
		" & Fabien Linardon", 2, screen);
}

void		display_octet(SDL_Surface *screen, int color, int i, int j)
{
  char		clr[3];
  SDL_Surface	*surface;
  SDL_Rect	pos;

  clr[0] = (char) (color) & 0xFF;
  clr[1] = (char) (color >> 8) & 0xFF;
  clr[2] = (char) (color >> 16) & 0xFF;
  pos.x = 1 + (i * (MEM_OCTET + 1));
  pos.y = 1 + (j * (MEM_OCTET + 1));
  surface = SDL_CreateRGBSurface(SDL_HWSURFACE, MEM_OCTET, MEM_OCTET, 32, 0, 0, 0, 0);
  SDL_FillRect(surface, NULL, SDL_MapRGB(screen->format, clr[0], clr[1], clr[2]));
  SDL_BlitSurface(surface, NULL, screen, &pos);
  SDL_FreeSurface(surface);
}

void		display_mem_grid(t_vm *vm, t_proc *lproc)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (j < 50)
    {
      while (i < 113)
	display_octet(vm->sdl->screen, 0x000000, i++, j);
      i = 0;
      ++j;
    }
}

void		actualize_memory(t_vm *vm, t_proc **lproc)
{
  static int	pc_color[] = {0xFF0000, 0x00FF00, 0x0000FF, 0xFFE600};
  //  static int	cmd_color[] = {0xFF6666, 0x66FF66, 0x6666FF, 0xFBEC5D};
  static int	first = 1;

  if (first == 1)
    {
      first = 0;
      display_mem_grid(vm, *lproc);
    }
  else
    {
      if (!(*lproc)->live)
  	{
  	  display_octet(vm->sdl->screen, 0xFFFFFF,
			(*lproc)->pc % 113, (*lproc)->pc / 113);
  	}
      else
  	{
  	  display_octet(vm->sdl->screen, pc_color[(*lproc)->reg[0] % 4],
  			(*lproc)->pc % 113, (*lproc)->pc / 113);
  	  /* display_octet(vm->sdl->screen, cmd_color[(*lproc)->reg[0] % 4], */
  	  /* 		(*lproc)->pc % 113, (*lproc)->pc / 113); */
  	}
    }
}

void			actualize_data(t_vm *vm, t_proc **lproc)
{
  SDL_Rect		pos;
  SDL_Surface		*surface;

  pos.x = 50;
  pos.y = HEIGHT - SIDEBAR_SIZE;
  surface = SDL_CreateRGBSurface(SDL_HWSURFACE, 400, SIDEBAR_SIZE - 15, 32, 0, 0, 0, 0);
  SDL_FillRect(surface, NULL, SDL_MapRGB(vm->sdl->screen->format, 0, 0, 0));
  SDL_BlitSurface(surface, NULL, vm->sdl->screen, &pos);
  SDL_FreeSurface(surface);
  display_data(vm->sdl->screen, vm->cycle, &display_cycle, "Cycle : ");
  display_data(vm->sdl->screen, vm->ctd, &display_ctd, "Cycle to die : ");
  display_data(vm->sdl->screen, vm->nb_proc, &display_nb_proc, "Number of procs : ");
  display_data(vm->sdl->screen, vm->nb_live, &display_nb_live, "Number of live : ");
}

void	debug(t_vm *vm, t_proc **lproc)
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
  actualize_memory(vm, lproc);
  actualize_data(vm, lproc);
  if (SDL_Flip(vm->sdl->screen) == -1)
    return ;
}
