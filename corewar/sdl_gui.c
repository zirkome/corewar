/*
** main.c for SDL in /home/kokaz/projets/corewar_sdl
**
** Made by guillaume fillon
** Login   <kokaz@epitech.net>
**
** Started on  Tue Mar 26 10:24:47 2013 guillaume fillon
** Last update Sun Mar 31 14:12:53 2013 guillaume fillon
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "vm.h"

SDL_Surface	*init_sdl(SDL_Surface *screen)
{
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_NOPARACHUTE) == -1)
    return (NULL);
  if ((screen = SDL_SetVideoMode(WIDTH, HEIGHT, 32,
				 SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
    return (NULL);
  SDL_WM_SetCaption("VM Corewar", NULL);
  if (SDL_Flip(screen) == -1)
    return (NULL);
  if (TTF_Init() == -1)
    my_error("Erreur d'initialisation de TTF_Init\n", 1);
  return (screen);
}

Mix_Music	*play_music(Mix_Music *music)
{
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,
		   MIX_DEFAULT_CHANNELS, HEIGHT) == -1)
    my_error("Can't play the music. So sad...", 0);
  Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
  music = Mix_LoadMUS("corewar.xm");
  Mix_PlayMusic(music, -1);
  return (music);
}

void			intro_corewar(TTF_Font *font, char *label,
				      SDL_Surface *screen, int offset)
{
  static SDL_Color	color = {255, 255, 255};
  SDL_Surface		*text;
  SDL_Rect		pos;

  text = TTF_RenderText_Blended(font, label, color);
  pos.x = (WIDTH / 2) - (text->w / 2);
  pos.y = (HEIGHT / 2) - (text->h / 2) + offset;
  SDL_BlitSurface(text, NULL, screen, &pos);
  SDL_FreeSurface(text);
}

int			launch_sdl(t_sdl *sdl)
{
  TTF_Font		*font288;
  TTF_Font		*font200;
  SDL_Event		event;

  sdl->screen = NULL;
  sdl->music = NULL;
  if ((sdl->screen = init_sdl(sdl->screen)) == NULL)
    return (EXIT_FAILURE);
  font288 = TTF_OpenFont("game_over.ttf", FONT_SIZE1);
  font200 = TTF_OpenFont("game_over.ttf", 100);
  intro_corewar(font288, "CoreWar", sdl->screen, 0);
  intro_corewar(font200, "An original game by Victor A. Vyssotsky, Robert Morris Sr. " \
		"& M. Douglas McIlroy of the Bell Labs", sdl->screen, 100);
  intro_corewar(font200, "Coded by Le Gang de la Toundra", sdl->screen, 200);
  intro_corewar(font200, "(Press any key to start)", sdl->screen, 400);
  SDL_Flip(sdl->screen);
  while (1)
    {
      SDL_WaitEvent(&event);
      if (event.type == SDL_KEYUP)
	break;
    }
  sdl->music = play_music(sdl->music);
  return (EXIT_SUCCESS);
}
