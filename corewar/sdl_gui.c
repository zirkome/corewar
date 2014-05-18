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
  if ((font288 = TTF_OpenFont("game_over.ttf", FONT_SIZE1)) == NULL)
    abort();
  if ((font200 = TTF_OpenFont("game_over.ttf", 100)) == NULL)
    abort();
  intro_corewar(font288, "CoreWar", sdl->screen, 0);
  intro_corewar(font200, "An original game by Victor A. Vyssotsky, Robert " \
		"Morris Sr. & M. Douglas McIlroy", sdl->screen, 100);
  intro_corewar(font200, "Coded by Le Gang de la Toundra", sdl->screen, 200);
  intro_corewar(font200, "(Insert coin to play)", sdl->screen, 400);
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
