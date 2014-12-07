/*
** main.c for Impossible_Game in /home/david_h/Personnal_Project
** 
** Made by Sullivan David
** Login   <david_h@epitech.net>
** 
** Started on  Sun Dec  7 15:46:33 2014 david_h
** Last update Sun Dec  7 22:29:22 2014 david_h
*/

#include <stdio.h>
#include <stdlib.h>
#include "./include/struct.h"

char *table[] = {
  "0000000000",
  "0000000000",
  "0010010000",
  "0000000000",
  "0030020000"};

int	main()
{
  s_sdl	*s_init;

  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    return (1);
  
  s_init = create_win();
  s_init = create_renderer(s_init);

  print_tile(s_init, table);
  SDL_Delay(5000);
  destroy_sdl(s_init);
  return (0);
}

