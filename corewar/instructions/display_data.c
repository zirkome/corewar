/*
** display_data.c for CoreWar in /home/kokaz/projets/corewar/corewar
**
** Made by guillaume fillon
** Login   <kokaz@epitech.net>
**
** Started on  Sun Mar 31 07:51:57 2013 guillaume fillon
** Last update Sun Mar 31 08:50:37 2013 guillaume fillon
*/

#include "lib.h"
#include "vm.h"

char		*display_cycle(char *name, int value, SDL_Rect *p)
{
  char		*nb;
  char		*full;

  if ((nb = malloc(10 * sizeof(char))) == NULL)
    return (NULL);
  if ((full = malloc(19 * sizeof(char))) == NULL)
    return (NULL);
  nb = my_itoa(value, nb);
  my_strcpy(full, name);
  my_strcat(full, nb);
  p->x = 200;
  p->y = 880;
  free(nb);
  return (full);
}

char	*display_ctd(char *name, int value, SDL_Rect *p)
{
  char	*nb;
  char	*full;

  if ((nb = malloc(15 * sizeof(char))) == NULL)
    return (NULL);
  if ((full = malloc(24 * sizeof(char))) == NULL)
    return (NULL);
  nb = my_itoa(value, nb);
  my_strcpy(full, name);
  my_strcat(full, nb);
  p->x = 200;
  p->y = 910;
  free(nb);
  return (full);
}

char		*display_nb_live(char *name, int value, SDL_Rect *p)
{
  char		*nb;
  char		*full;

  if ((nb = malloc(17 * sizeof(char))) == NULL)
    return (NULL);
  if ((full = malloc(28 * sizeof(char))) == NULL)
    return (NULL);
  nb = my_itoa(value, nb);
  my_strcpy(full, name);
  my_strcat(full, nb);
  p->x = 200;
  p->y = 940;
  free(nb);
  return (full);
}

char		*display_nb_proc(char *name, int value, SDL_Rect *p)
{
  char		*nb;
  char		*full;

  if ((nb = malloc(22 * sizeof(char))) == NULL)
    return (NULL);
  if ((full = malloc(39 * sizeof(char))) == NULL)
    return (NULL);
  nb = my_itoa(value, nb);
  my_strcpy(full, name);
  my_strcat(full, nb);
  p->x = 200;
  p->y = 970;
  free(nb);
  return (full);
}

void			display_data(SDL_Surface *screen, int value,
				     char *(*fptr)(), char *name)
{
  static SDL_Color	color = {0, 255, 0};
  TTF_Font		*font50;
  SDL_Surface		*surface;
  SDL_Rect		pos;

  font50 = TTF_OpenFont("game_over.ttf", 60);
  surface = TTF_RenderText_Blended(font50, fptr(name, value, &pos),
				   color);
  SDL_BlitSurface(surface, NULL, screen, &pos);
  SDL_FreeSurface(surface);
  TTF_CloseFont(font50);
}
