/*
** struct.h for Impossible_Game in /home/david_h/Personnal_Project/Impossible_Game/include
** 
** Made by Sullivan David
** Login   <david_h@epitech.net>
** 
** Started on  Sun Dec  7 15:48:34 2014 david_h
** Last update Sun Dec  7 22:19:41 2014 david_h
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <SDL2/SDL.h>

#define TITLE "Impossible_Game"
#define X_WIN 160
#define Y_WIN 80

#define L_TILE 16
#define H_TILE 16

#define NB_BLOC_MAP_L 10
#define NB_BLOC_MAP_H 5
#define TILESET_PATH "./Ressources/sprite.png"


typedef struct
{
  SDL_Window	*window;
  SDL_Renderer	*renderer;
}s_sdl;

s_sdl	*create_win();
s_sdl	*create_renderer(s_sdl *s_init);
void	print_tile(s_sdl *s_init, char **map);
#endif /* _STRUCT_H_ */