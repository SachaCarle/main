##
## Makefile for python in /home/scarle/shared/python/emb
## 
## Made by Sacha Carle
## Login   <scarle@epitech.net>
## 
## Started on  Tue Feb  9 14:29:08 2016 Sacha Carle
## Last update Tue Feb  9 14:45:23 2016 Sacha Carle
##

NAME = exec

SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

PYVER = python3.4

CC = g++

PYFLAGS = $(shell $(PYVER)-config --cflags --libs --includes)

LDFLAGS = $(PYFLAGS) $(shell $(PYVER)-config --ldflags)

CPPFLAGS = $(PYFLAGS)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
