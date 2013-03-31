/*
** display_func.c for Corewar in /home/kokaz/projets/corewar/corewar
**
** Made by guillaume fillon
** Login   <kokaz@epitech.net>
**
** Started on  Sun Mar 31 19:26:17 2013 guillaume fillon
** Last update Sun Mar 31 19:26:30 2013 guillaume fillon
*/

#include "lib.h"
#include "vm.h"

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
