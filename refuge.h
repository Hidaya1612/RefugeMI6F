#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TAILLE 50

// Enumeration species
typedef enum {
  DOG, CAT, HAMSTER, OSTRICH
} Species;

// Structure animal
typedef struct {
  int identification_number;
  char* name;
  Species species;
  int year_of_birth;
  float weight;
  char* description;
} Animal;

//Prototypes
Date constructeur();
Animal constructeurAnimal();
void day_clean(Animal* tab, int size);
void afficherMenu();
