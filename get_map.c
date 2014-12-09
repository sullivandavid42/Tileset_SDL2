/*
** get_map.c for Impossible Game in /home/carle-s/home/guard
** 
** Made by carle_s
** Login   <carle-s@epitech.net>
** 
** Started on  Tue Dec  9 00:05:53 2014 carle_s
** Last update Tue Dec  9 17:54:27 2014 david_h
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

static int	get_dim(const char *path, int *line, int *column)
{
  int		fd;
  char		*str;
  int		ret;
  int		j;
  int		c;

  *line = 0;
  *column = 1;
  ret = 64;
  c = 1;
  if ((fd = open(path, O_RDONLY)) != -1 &&
      (str = (char *)malloc(sizeof(char) * 64)) != NULL)
    {
      while (ret == 64)
	{
	  ret = read(fd, str, 64);
	  if (ret == -1)
	    return (0);
	  str[ret] = '\0';
	  for (j = 1; str[j] != '\0'; j++)
	    {
	      if (str[j] == '\n')
		{
		  *line += 1;
		  *column = (c > *column) ? c : *column;
		  c = 1;
		}
	      c += (str[j] == ' ');
	    }
	}
      close(fd);
    }
}

static char	*get_map_line(const int fd, int lenght)
{
  int		i;
  char		*ret;
  int		r;

  i = 0;
  r = 1;
  if ((ret = (char *)malloc(sizeof(char) * (lenght + 1))) == NULL)
    return (NULL);
  while (r == 1)
    {
      r = read(fd, &ret[i], 1);
      if (r == -1)
	return (NULL);
      if (r == 0 || ret[i] == '\n')
	break;
      i += 1;
    }
  ret[i + 1] = '\0';
  return (ret);
}

static int	*get_line(char *line, int nbr)
{
  int		*ret;
  int		i;
  int		k;

  if ((ret = (int *)malloc(sizeof(int) * nbr)) == NULL)
    return (NULL);
  i = 0;
  k = 0;
  while (k < nbr)
    {
      ret[k] = atoi(line + i);
      i = i + ((ret[k] < 10) ? 2 : 3);
      k += 1;
    }
  return (ret);
}

int	**get_map(const char *path, int *line, int *column)
{
  int	fd;
  int	**map;
  char	*str;
  int	i;

  get_dim(path, line, column);
  if ((fd = open(path, O_RDONLY)) == -1 || *line < 0 || *column < 0
      || (map = (int **)malloc(sizeof(int *) * *line)) == NULL) 
    return ((int **)(printf("Error : An error occurs in the file : %s.\n", path) == 0));
  i = 0;
  while (i < *line)
    {
      if ((map[i] = (int *)malloc(sizeof(int) * (*column))) == NULL
	  || (str = get_map_line(fd, *column * 3)) == NULL)
	return ((int **)(printf("get_map : Malloc error.\n") == 0));
      map[i] = get_line(str, *column);
      i += 1;
    }
  close(fd);
  *line--;
  return (map);
}
