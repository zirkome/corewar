/*
** debug.c for debug in /home/remi/Projet/save_projet/corewar/corewar
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Thu Mar 28 17:05:43 2013 remi
** Last update Sun Mar 31 01:10:20 2013 guillaume fillon
*/

#include "lib.h"
#include "vm.h"

void			display_sidebar(SDL_Surface *screen)
{
  static SDL_Color	fg = {0, 255, 0};
  TTF_Font		*font288;
  TTF_Font		*font144;
  SDL_Surface		*gfx_octet;
  SDL_Surface		*text;
  SDL_Rect		pos;

  SDL_FillRect(screen, NULL, 0x000000);
  pos.x = 0;
  pos.y = HEIGHT - SIDEBAR_SIZE;
  gfx_octet = SDL_CreateRGBSurface(SDL_HWSURFACE, WIDTH, SIDEBAR_SIZE, 32, 0, 0, 0, 0);
  SDL_FillRect(gfx_octet, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
  SDL_BlitSurface(gfx_octet, NULL, screen, &pos);
  if (SDL_Flip(screen) == -1)
    return ;
  SDL_FreeSurface(gfx_octet);
  font288 = TTF_OpenFont("game_over.ttf", FONT_SIZE1);
  font144 = TTF_OpenFont("game_over.ttf", FONT_SIZE2);
  text = TTF_RenderText_Blended(font288, "CoreWar", fg);
  pos.x = (WIDTH / 2) - (text->w / 2);
  pos.y = HEIGHT - SIDEBAR_SIZE - (text->h / 10);
  SDL_BlitSurface(text, NULL, screen, &pos);
  text = TTF_RenderText_Blended(font144, "v1.0 build 151", fg);
  pos.x = WIDTH - text->w - 3;
  pos.y = HEIGHT - text->h;
  SDL_BlitSurface(text, NULL, screen, &pos);
  text = TTF_RenderText_Blended(font144, "Made by Remi Robert, Guillaume Fillon, Nicolas Bridoux & Fabien Linardon", fg);
  pos.x = 3;
  pos.y = HEIGHT - text->h;
  SDL_BlitSurface(text, NULL, screen, &pos);
}

void		display_octet(SDL_Surface *screen, int color, int i, int j)
{
  char		clr[3];
  SDL_Surface	*gfx_octet;
  SDL_Rect	pos;

  clr[0] = (char) (color) & 0xFF;
  clr[1] = (char) (color >> 8) & 0xFF;
  clr[2] = (char) (color >> 16) & 0xFF;
  pos.x = 1 + (i * (MEM_OCTET + 1));
  pos.y = 1 + (j * (MEM_OCTET + 1));
  gfx_octet = SDL_CreateRGBSurface(SDL_HWSURFACE, MEM_OCTET, MEM_OCTET, 32, 0, 0, 0, 0);
  SDL_FillRect(gfx_octet, NULL, SDL_MapRGB(screen->format, clr[0], clr[1], clr[2]));
  SDL_BlitSurface(gfx_octet, NULL, screen, &pos);
  SDL_FreeSurface(gfx_octet);
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
  static int	cmd_color[] = {0xFF6666, 0x66FF66, 0x6666FF, 0xFBEC5D};
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
  	  display_octet(vm->sdl->screen, 0xFFFFFF, (*lproc)->pc % 113, (*lproc)->pc / 113);
  	}
      else
  	{
  	  display_octet(vm->sdl->screen, pc_color[(*lproc)->reg[0] % 4],
  			(*lproc)->pc % 113, (*lproc)->pc / 113);
  	  display_octet(vm->sdl->screen, cmd_color[(*lproc)->reg[0] % 4],
  			(*lproc)->pc % 113, (*lproc)->pc / 113);
  	}
    }
}

void		display_cycle_to_die(SDL_Surface *screen, int ccl, SDL_Color color)
{
  TTF_Font	*font50;
  SDL_Surface	*surface;
  char		*cycle;
  char		*txt;
  SDL_Rect	pos;

  if ((cycle = malloc(15 * sizeof(char))) == NULL)
    return;
  if ((txt = malloc(24 * sizeof(char))) == NULL)
    return;
  cycle = my_itoa(ccl, cycle);
  my_strcpy(txt, "Cycle to die : ");
  my_strcat(txt, cycle);
  font50 = TTF_OpenFont("game_over.ttf", 60);
  surface = TTF_RenderText_Blended(font50, txt, color);
  pos.x = 5;
  pos.y = 910;
  SDL_BlitSurface(surface, NULL, screen, &pos);
  SDL_FreeSurface(surface);
  TTF_CloseFont(font50);
  free(cycle);
  free(txt);
}

void		display_cycle(SDL_Surface *screen, int ccl, SDL_Color color)
{
  TTF_Font	*font50;
  SDL_Surface	*surface;
  char		*cycle;
  char		*txt;
  SDL_Rect	pos;

  if ((cycle = malloc(10 * sizeof(char))) == NULL)
    return;
  if ((txt = malloc(19 * sizeof(char))) == NULL)
    return;
  cycle = my_itoa(ccl, cycle);
  my_strcpy(txt, "Cycle : ");
  my_strcat(txt, cycle);
  font50 = TTF_OpenFont("game_over.ttf", 60);
  surface = TTF_RenderText_Blended(font50, txt, color);
  pos.x = 5;
  pos.y = 880;
  SDL_BlitSurface(surface, NULL, screen, &pos);
  SDL_FreeSurface(surface);
  TTF_CloseFont(font50);
  free(cycle);
  free(txt);
}

void		display_nb_live(SDL_Surface *screen, int nb_live, SDL_Color color)
{
  TTF_Font	*font50;
  SDL_Surface	*surface;
  char		*live;
  char		*txt;
  SDL_Rect	pos;

  if ((live = malloc(17 * sizeof(char))) == NULL)
    return;
  if ((txt = malloc(28 * sizeof(char))) == NULL)
    return;
  live = my_itoa(nb_live, live);
  my_strcpy(txt, "Nombre de live : ");
  my_strcat(txt, live);
  font50 = TTF_OpenFont("game_over.ttf", 60);
  surface = TTF_RenderText_Blended(font50, txt, color);
  pos.x = 5;
  pos.y = 940;
  SDL_BlitSurface(surface, NULL, screen, &pos);
  SDL_FreeSurface(surface);
  TTF_CloseFont(font50);
  free(live);
  free(txt);
}

void		display_nb_proc(SDL_Surface *screen, int nb_proc, SDL_Color color)
{
  TTF_Font	*font50;
  SDL_Surface	*surface;
  char		*proc;
  char		*txt;
  SDL_Rect	pos;

  if ((proc = malloc(22 * sizeof(char))) == NULL)
    return;
  if ((txt = malloc(39 * sizeof(char))) == NULL)
    return;
  proc = my_itoa(nb_proc, proc);
  my_strcpy(txt, "Nombre de processus : ");
  my_strcat(txt, proc);
  font50 = TTF_OpenFont("game_over.ttf", 60);
  surface = TTF_RenderText_Blended(font50, txt, color);
  pos.x = 5;
  pos.y = 850;
  SDL_BlitSurface(surface, NULL, screen, &pos);
  SDL_FreeSurface(surface);
  TTF_CloseFont(font50);
  free(proc);
  free(txt);
}

void			actualize_data(t_vm *vm, t_proc **lproc)
{
  static SDL_Color	color = {0, 255, 0};
  SDL_Rect		pos;
  SDL_Surface		*surface;

  pos.x = 50;
  pos.y = HEIGHT - SIDEBAR_SIZE;
  surface = SDL_CreateRGBSurface(SDL_HWSURFACE, 400, SIDEBAR_SIZE - 15, 32, 0, 0, 0, 0);
  SDL_FillRect(surface, NULL, SDL_MapRGB(vm->sdl->screen->format, 0, 0, 0));
  SDL_BlitSurface(surface, NULL, vm->sdl->screen, &pos);
  SDL_FreeSurface(surface);
  display_cycle(vm->sdl->screen, vm->cycle, color);
  display_cycle_to_die(vm->sdl->screen, vm->cycle_to_die, color);
  display_nb_live(vm->sdl->screen, vm->nb_live, color);
  display_nb_proc(vm->sdl->screen, vm->nb_proc, color);
}

void	debug(t_vm *vm, t_proc **lproc)
{
  my_putstr("[");
  my_put_nbr((*lproc)->nb_proc);
  my_putstr("] ");
  my_putstr("[");
  my_put_nbr((*lproc)->num_proc);
  my_putstr("] ");
  my_putstr(op_tab[((*lproc)->code - 1) % REG_NUMBER].mnemonique);
  my_putstr("\n");
  actualize_memory(vm, lproc);
  actualize_data(vm, lproc);
  if (SDL_Flip(vm->sdl->screen) == -1)
    return ;
}
