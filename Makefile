CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS = -lgmp

TARGET = x25519
SRC = main.c utils.c curve25519.c
OBJ = $(SRC:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJ)