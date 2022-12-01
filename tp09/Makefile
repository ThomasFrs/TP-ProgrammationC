### ATTENTION : les retraits == tabulation et NON espaces !!! ###

# commande de compilation
CC=gcc
# options de compilation (-Wall indispensable, -g pour le debug)
CFLAGS= -Wextra -Wall -pedantic -g
# options d'édition de liens : librairies utilisées
LDFLAGS=  -lm # pour math.h facultatif selon le compilateur
# emplacement des .a (librairies) du TP (s'il y a lieu)
LIB= .
# emplacement des .h du TP
INC= .
# A modifier en fonction du TP courant avec les .c (sources) nécessaire
SRC= ex.c matrice.c image.c ti.c
# Génère la liste *.o (binaires) correspondant aux *.c
OBJ= $(SRC:.c=.o)
# nom de l'exécutable, à modifier en fonction du TP courant
EXE= ex
# pour pouvoir utiliser la commande make
all: $(EXE)

# sans généricité :
$(EXE): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJ) -I $(INC) -L $(LIB) $(LDFLAGS)
#ex1.o: tp08ex1.c
#	$(CC) $(CFLAGS) -c tp08ex1.c
#matrice.o: matrice.c $(INC)/matrice.h
#	$(CC) $(CFLAGS) -c matrice.c

# exécution en mode debug
debug:
	lldb $(EXE)        # lldb, gdb ou ddd selon le système

# exécution
run:
	./$(EXE)

# suppression de tous les binaires
clean:
	rm $(EXE) *.o


