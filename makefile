# Variables
CC = gcc
SRC = main.c fonction_variante.c fonction_ajouter.c fonction_stockage.c fonction_adoption.c menu.c rechercheNv.c
OBJ = $(SRC:.c=.o)
EXEC = Projet

# Règles
all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ 

%.o: %.c refuge.h
	$(CC) -o $@ -c 

clean:
	rm -f $(OBJ)

