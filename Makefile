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
	  src/common/objloader.cpp \
	  src/generation/generate_chunk.cpp

CFLAGS = -Wall -Wextra -I ./include/

OBJ = $(SRC:.c=.o)

LIB = -L/usr/local/include/

FLAGS = -lGLEW -lglfw -lGL -lm -lX11 -lpthread -lXi -lXrandr -ldl

NAME = minecraft

all: NAME

NAME: $(OBJ)
	$(CXX) $(OBJ) -o $(NAME) $(LIB) $(FLAGS) $(CFLAGS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

debug: CFLAGS += -g
debug: re

.PHONY: all clean fclean re debug