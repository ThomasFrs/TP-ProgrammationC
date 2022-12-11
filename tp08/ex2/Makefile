CC=gcc
LDFLAGS=-lm
CFLAGS=-std=c99 -Werror -Wall -Wextra
SRC=ex2.c image.c matrice.c
OBJ=$(SRC:.c=.o)
EXE=ex2

all=$(EXE)

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

$(EXE): $(OBJ)
	@$(CC) -o $@ $^ $(LDFLAGS)

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXE)
