/*
** tile_map.c for Impossible_Game in /home/david_h/Personnal_Project/Impossible_Game
** 
** Made by Sullivan David
** Login   <david_h@epitech.net>
** 
** Started on  Sun Dec  7 20:52:29 2014 david_h
** Last update Mon Dec  8 11:26:37 2014 david_h
*/

#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "./include/struct.h"

SDL_Texture	*load_tileset(s_sdl *s_init)
{
  SDL_Texture	*tileset;
  int		w;
  int		h;

  w = L_TILE;
  h = H_TILE;
  tileset = IMG_LoadTexture(s_init->renderer, TILESET_PATH);
  if (tileset == NULL)
    printf("Loading Error : %s", TILESET_PATH);
  SDL_QueryTexture(tileset, NULL, NULL, &w, &h);
  return (tileset);
}

void		print_tile(s_sdl *s_init, int **map, int x, int c)
{
  int	        i;
  int		j;
  SDL_Rect	rect_dest;
  SDL_Rect	rect_src;
  SDL_Texture	*sprite;
  SDL_Texture	*background;
  int		X;
  int		Y;

  sprite = load_tileset(s_init);
  if (sprite == NULL)
    printf("Il est NULL ton sprite");
  rect_src.w = L_TILE;
  rect_src.h = H_TILE;
  rect_dest.w = L_TILE;
  rect_dest.h = H_TILE;
  for (i = 0; i < c; i++)
    {
      for (j = 0; j < x; j++)
	{
	  rect_dest.x = i * L_TILE;
	  rect_dest.y = j * H_TILE;
	  X = map[j][i] % 8;
	  Y = map[j][i] / 8;
	  rect_src.x = X * L_TILE;
	  rect_src.y = Y * H_TILE;
	  SDL_RenderCopy(s_init->renderer, sprite, &rect_src, &rect_dest);
	}
    }
  SDL_RenderPresent(s_init->renderer);
}
