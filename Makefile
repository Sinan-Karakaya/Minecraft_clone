##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## make things
##

SRC = src/main.cpp \
	  src/shader.cpp \
	  src/texture.cpp \
	  src/common/control.cpp \
	  src/common/objloader.cpp

CFLAGS = -Wall -Wextra -g -I ./include/

OBJ = $(SRC:.c=.o)

LIB = -L/usr/local/include/

FLAGS = -lGLEW -lglfw -lGL -lm -lX11 -lpthread -lXi -lXrandr -ldl

NAME = open_gl

all: NAME

NAME: $(OBJ)
	g++ -g $(OBJ) -o $(NAME) $(LIB) $(FLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug: fclean $(OBJ)
	make -C lib/my/
	make clean -C lib/my/
	$(CC) -g $(OBJ) -o $(NAME) $(INCLUDE) $(LIB) $(FLAGS)
