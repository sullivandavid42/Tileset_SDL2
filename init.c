/*
** init.c for Impossible_Game in /home/david_h/Personnal_Project/Impossible_Game
** 
** Made by Sullivan David
** Login   <david_h@epitech.net>
** 
** Started on  Sun Dec  7 15:51:11 2014 david_h
** Last update Sun Dec  7 19:04:13 2014 david_h
*/

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "./include/struct.h"

s_sdl		*create_win()
{
  s_sdl		*s_init;

  if(!(s_init = malloc(sizeof(s_sdl))));
  s_init->window = SDL_CreateWindow(TITLE,
				    SDL_WINDOWPOS_CENTERED,
				    SDL_WINDOWPOS_CENTERED,
				    X_WIN,
				    Y_WIN,
				    0);
  return (s_init);
}

s_sdl		*create_renderer(s_sdl *s_init)
{
  s_init->renderer = SDL_CreateRenderer(s_init->window, -1, SDL_RENDERER_ACCELERATED);
  return (s_init);
}

void		*destroy_sdl(s_sdl *s_init)
{
  SDL_DestroyWindow(s_init->window);
  SDL_DestroyRenderer(s_init->renderer);
  SDL_Quit();
}
