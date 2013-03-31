/*
** display_intro.c for Corewar in /home/kokaz/projets/corewar/corewar
**
** Made by guillaume fillon
** Login   <kokaz@epitech.net>
**
** Started on  Sun Mar 31 09:36:31 2013 guillaume fillon
** Last update Sun Mar 31 14:10:54 2013 guillaume fillon
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

void			display_text(char *name,
				     SDL_Rect pos, SDL_Surface *screen)
{
  static SDL_Color	fg = {0, 255, 0};
  SDL_Surface		*surface;
  TTF_Font		*font;

  font = TTF_OpenFont("game_over.ttf", FONT_SIZE2 * 2);
  surface = TTF_RenderText_Blended(font, name, fg);
  pos.x += 60;
  pos.y -= 5;
  SDL_BlitSurface(surface, NULL, screen, &pos);
  SDL_FreeSurface(surface);
  TTF_CloseFont(font);
}

void		display_champions(t_vm *vm)
{
  static int	pc_color[] = {0xFF0000, 0x00FF00, 0x0000FF, 0xFFE600};
  SDL_Surface	*surface;
  SDL_Rect	pos;
  char		c[3];
  int		i;

  i = -1;
  while (++i < 4)
    {
      c[0] = (char) (pc_color[i]) & 0xFF;
      c[1] = (char) (pc_color[i] >> 8) & 0xFF;
      c[2] = (char) (pc_color[i] >> 16) & 0xFF;
      pos.x = WIDTH - 650;
      pos.y = HEIGHT - SIDEBAR_SIZE + (i * 45);
      surface = SDL_CreateRGBSurface(SDL_HWSURFACE, 50, 30, 32, 0, 0, 0, 0);
      SDL_FillRect(surface, NULL, SDL_MapRGB(vm->sdl->screen->format,
					     c[2], c[1], c[0]));
      display_text(vm->header[i].prog_name, pos, vm->sdl->screen);
      SDL_BlitSurface(surface, NULL, vm->sdl->screen, &pos);
      SDL_FreeSurface(surface);
    }
  SDL_Flip(vm->sdl->screen);
}

void		display_sidebar(SDL_Surface *screen)
{
  SDL_Surface	*surface;
  SDL_Rect	pos;

  SDL_FillRect(screen, NULL, 0x000000);
  pos.x = 0;
  pos.y = HEIGHT - SIDEBAR_SIZE;
  surface = SDL_CreateRGBSurface(SDL_HWSURFACE, WIDTH,
				 SIDEBAR_SIZE, 32, 0, 0, 0, 0);
  SDL_FillRect(surface, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
  SDL_BlitSurface(surface, NULL, screen, &pos);
  SDL_FreeSurface(surface);
  display_intro("CoreWar", 0, screen);
  display_intro("v1.0 build 155", 1, screen);
  display_intro("Made by Remi Robert, " \
		"Guillaume Fillon, Nicolas Bridoux" \
		" & Fabien Linardon", 2, screen);
  SDL_Flip(screen);
}

void		display_octet(SDL_Surface *screen, int color, int i, int j)
{
  char		c[3];
  SDL_Surface	*surface;
  SDL_Rect	pos;

  c[0] = (char) (color) & 0xFF;
  c[1] = (char) (color >> 8) & 0xFF;
  c[2] = (char) (color >> 16) & 0xFF;
  pos.x = 1 + (i * (MEM_OCTET + 1));
  pos.y = 1 + (j * (MEM_OCTET + 1));
  surface = SDL_CreateRGBSurface(SDL_HWSURFACE, MEM_OCTET,
				 MEM_OCTET, 32, 0, 0, 0, 0);
  SDL_FillRect(surface, NULL, SDL_MapRGB(screen->format, c[2], c[1], c[0]));
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
