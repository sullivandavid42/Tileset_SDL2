/*
** tile_map.c for Impossible_Game in /home/david_h/Personnal_Project/Impossible_Game
** 
** Made by Sullivan David
** Login   <david_h@epitech.net>
** 
** Started on  Sun Dec  7 20:52:29 2014 david_h
** Last update Sun Dec  7 22:29:00 2014 david_h
*/

#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "./include/struct.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

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

void		print_tile(s_sdl *s_init, char **map)
{
  int	        i;
  int		j;
  SDL_Rect	rect_dest;
  SDL_Rect	rect_src;
  SDL_Texture	*sprite;

  sprite = load_tileset(s_init);
  if (sprite == NULL)
    printf("Il est NULL ton sprite");
  rect_src.w = L_TILE;
  rect_src.h = H_TILE;
  rect_dest.w = L_TILE;
  rect_dest.h = H_TILE;
  for (i = 0; i < NB_BLOC_MAP_L; i++)
    {
      for (j = 0; j < NB_BLOC_MAP_H; j++)
	{
	  rect_dest.x = i * L_TILE;
	  rect_dest.y = j * H_TILE;
	  rect_src.x = (map[j][i] - '0') * L_TILE;
	  rect_src.y = 0;
	  SDL_RenderCopy(s_init->renderer, sprite, &rect_src, &rect_dest);
	}
    }
  SDL_RenderPresent(s_init->renderer);
}
