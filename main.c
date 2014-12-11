/*
** main.c for Impossible_Game in /home/david_h/Personnal_Project
** 
** Made by Sullivan David
** Login   <david_h@epitech.net>
** 
** Started on  Sun Dec  7 15:46:33 2014 david_h
** Last update Thu Dec 11 00:24:42 2014 david_h
*/

#include <stdio.h>
#include <stdlib.h>
#include "./include/struct.h"

int	**get_map(char *path, int *x, int *y);

int	main()
{
  s_sdl	*s_init;
  int	**table;
  int	x, c;

  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    return (1);
  if ((table = get_map("./Ressources/map.txt", &x, &c)) == NULL)
    return (printf("Loading error.\n"));
  s_init = create_win(x, c);
  s_init = create_renderer(s_init);
  event(s_init, table, x, c);
  // print_tile(s_init, table, x, c);
  destroy_sdl(s_init);
  return (0);
}
