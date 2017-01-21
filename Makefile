CC = gcc
CFLAGS = -Wall -lpanel -lncurses
LDFLAGS = -lpanel -lncurses

SRC = tetris.c board.c tetrimino.c
EXEC = tetris

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) $^ $(CFLAGS) -o $@

clean:
	rm *~
	rm $(EXEC)