/*
** main.c for SDL in /home/kokaz/projets/corewar_sdl
**
** Made by guillaume fillon
** Login   <kokaz@epitech.net>
**
** Started on  Tue Mar 26 10:24:47 2013 guillaume fillon
** Last update Sun Mar 31 07:06:01 2013 guillaume fillon
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "vm.h"

SDL_Surface	*init_sdl(SDL_Surface *screen)
{
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_NOPARACHUTE) == -1)
    return (NULL);
  if ((screen = SDL_SetVideoMode(WIDTH, HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
    return (NULL);
  SDL_WM_SetCaption("VM Corewar", NULL);
  if (SDL_Flip(screen) == -1)
    return (NULL);
  if(TTF_Init() == -1)
    {
      write(2, "Erreur d'initialisation de TTF_Init\n", 36);
      exit(EXIT_FAILURE);
    }
  return (screen);
}

Mix_Music	*play_music(Mix_Music *music)
{
  if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, HEIGHT) == -1)
    printf("%s", Mix_GetError());
  Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
  music = Mix_LoadMUS("corewar.xm");
  Mix_PlayMusic(music, -1);
  return (music);
}

int			launch_sdl(t_sdl *sdl)
{
  static SDL_Color	color = {255, 255, 255};
  TTF_Font		*font288;
  TTF_Font		*font200;
  SDL_Surface		*text;
  SDL_Event		event;
  SDL_Rect		pos;

  sdl->screen = NULL;
  sdl->music = NULL;
  if ((sdl->screen = init_sdl(sdl->screen)) == NULL)
    return (EXIT_FAILURE);
  font288 = TTF_OpenFont("game_over.ttf", FONT_SIZE1);
  font200 = TTF_OpenFont("game_over.ttf", 100);
  text = TTF_RenderText_Blended(font288, "CoreWar", color);
  pos.x = (WIDTH / 2) - (text->w / 2);
  pos.y = (HEIGHT / 2) - (text->h / 2);
  SDL_BlitSurface(text, NULL, sdl->screen, &pos);
  text = TTF_RenderText_Blended(font200, "A game by Victor A. Vyssotsky, Robert Morris Sr. " \
				"& M. Douglas McIlroy ", color);
  pos.x = (WIDTH / 2) - (text->w / 2);
  pos.y = (HEIGHT / 2) - (text->h / 2) + 100;
  SDL_BlitSurface(text, NULL, sdl->screen, &pos);
  text = TTF_RenderText_Blended(font200, "Coded by Le Gang de la Toundra", color);
  pos.x = (WIDTH / 2) - (text->w / 2);
  pos.y = (HEIGHT / 2) - (text->h / 2) + 200;
  SDL_BlitSurface(text, NULL, sdl->screen, &pos);
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
