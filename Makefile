##
## Makefile for Impossible_Game in /home/david_h/Personnal_Project/Impossible_Game
## 
## Made by Sullivan David
## Login   <david_h@epitech.net>
## 
## Started on  Sun Dec  7 15:56:21 2014 david_h
## Last update Sun Dec  7 21:59:14 2014 david_h
##

NAME 	= Impossible_Game

HEADER	= ./include/struct.h

LIB	= -lSDL2 -lSDL2_image

SRC	= main.c \
	  init.c \
	  tile_map.c

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc -c $(SRC)
	gcc -o $(NAME) $(OBJ) $(LIB) -g

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

my_clean: clean
	rm *~