CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS = -lgmp

SRC = main.c utils.clean
OBJ = $(SRC:.c=.o)

clean:
	rm -rf $(OBJ)