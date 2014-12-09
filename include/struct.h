/*
** struct.h for Impossible_Game in /home/david_h/Personnal_Project/Impossible_Game/include
** 
** Made by Sullivan David
** Login   <david_h@epitech.net>
** 
** Started on  Sun Dec  7 15:48:34 2014 david_h
** Last update Tue Dec  9 17:49:59 2014 david_h
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <SDL2/SDL.h>

#define L_TILE 64
#define H_TILE 64

//#define NB_BLOC_MAP_L 10
//#define NB_BLOC_MAP_H 6

#define TITLE "Impossible_Game"
#define X_WIN (NB_BLOC_MAP_L * L_TILE) 
#define Y_WIN (NB_BLOC_MAP_H * H_TILE)

#define TILESET_PATH "./Ressources/tileset.png"
#define BACKGROUND_PATH "./Ressources/bg.jpg"

typedef struct
{
  SDL_Window	*window;
  SDL_Renderer	*renderer;
}s_sdl;

s_sdl	*create_win(int x, int c);
s_sdl	*create_renderer(s_sdl *s_init);
void	print_tile(s_sdl *s_init, int **map, int x, int c);
#endif /* _STRUCT_H_ */
