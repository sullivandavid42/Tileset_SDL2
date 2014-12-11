/*
** event.c for Impossible_Game in /home/david_h/Personnal_Project/Tileset_SDL2
** 
** Made by Sullivan David
** Login   <david_h@epitech.net>
** 
** Started on  Tue Dec  9 18:17:29 2014 david_h
** Last update Wed Dec 10 15:26:23 2014 david_h
*/

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "./include/struct.h"
#include <SDL2/SDL_image.h>

SDL_Texture	*load_character(s_sdl *s_init)
{
  SDL_Texture	*character;
  int		w;
  int		h;

  w = 64;
  h = 64;
  character = IMG_LoadTexture(s_init->renderer, CHARACTER_PATH);
  if (character == NULL)
    printf("Loading Error : %s", CHARACTER_PATH);
  SDL_QueryTexture(character, NULL, NULL, &w, &h);
  return (character);
}

void			pos_character(SDL_Rect *character, int *x_char, int *y_char)
{
  character->x = *x_char;
  character->y = *y_char;
  character->w = 64;
  character->h = 64;
}

int			event(s_sdl *s_init, int **table, int xe, int ce)
{
  SDL_Event		event;
  int			i;
  SDL_Texture		*character;
  SDL_Rect		dest;
  int			x;
  int			y;
  SDL_Texture		*tileset;

  tileset = load_tileset(s_init);
  if (tileset == NULL)
    return (0);
  if (!(character = (load_character(s_init))))
    printf("Character NULL");
  i = 0;
  x = 100;
  y = 100;
  while (!i)
    {
      SDL_PollEvent(&event);
      switch (event.type)
	{
	case SDL_KEYDOWN:
	  switch (event.key.keysym.sym)
	    {
	    case SDLK_ESCAPE:
	      i = 1;
	      return (0);
	    case SDLK_LEFT:
	      x = x - 1;
	      break;
	    case SDLK_RIGHT:
	      x = x + 1;
	      break;
	    case SDLK_UP:
	      y = y - 1;
	      break;
	    case SDLK_DOWN:
	      y = y + 1;
	      break;
	    }
	  break;
	}
      pos_character(&dest, &x, &y);
      print_tile(s_init, table, xe, ce, tileset);
      SDL_RenderCopy(s_init->renderer, character, NULL, &dest);
      SDL_RenderPresent(s_init->renderer);
    }
}
