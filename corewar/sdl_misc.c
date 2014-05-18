/*
** sdl_misc.c for Corewar in /home/kokaz/projets/corewar/corewar
**
** Made by guillaume fillon
** Login   <kokaz@epitech.net>
**
** Started on  Sun Mar 31 19:28:56 2013 guillaume fillon
** Last update Sun Mar 31 19:33:20 2013 guillaume fillon
*/

#include "lib.h"
#include "vm.h"

void		handle_event2(SDL_Event *event)
{
  int		flag;

  flag = 1;
  while (flag)
    {
      SDL_WaitEvent(event);
      if (event->type == SDL_KEYDOWN)
	if (event->key.keysym.sym == SDLK_ESCAPE)
	  flag = 0;
      if (event->type == SDL_QUIT)
	flag = 0;
    }
}

void		handle_event(SDL_Event *event, t_sdl *sdl)
{
  while (SDL_PollEvent(event))
    {
      if (event->type == SDL_KEYDOWN)
	if (event->key.keysym.sym == SDLK_ESCAPE)
	  sdl_free(sdl->music);
      if (event->type == SDL_QUIT)
	sdl_free(sdl->music);
    }
}

void		sdl_free(Mix_Music *music)
{
  Mix_FreeMusic(music);
  Mix_CloseAudio();
  TTF_Quit();
  SDL_Quit();
  exit(EXIT_SUCCESS);
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
