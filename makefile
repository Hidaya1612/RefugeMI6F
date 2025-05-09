# Variables
CC = gcc
CFLAGS = -Wall -Wextra -std=c11
LDFLAGS = 
SRC = main.c refuge.h fonction_variante.c fonction_ajouter.c fonction_stockage.c Autres.cpp fonction_adoption.c menu.c rechercheNv.c
OBJ = $(SRC:.c=.o)
EXEC = Projet

# Règles
all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f $(OBJ)

mrproper: clean
	rm -f $(EXEC)
