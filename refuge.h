#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Enumeration species
typedef enum {
  DOG, CAT, HAMSTER, OSTRICH
} Species;

// Structure date
typedef struct {
  int day;
  int month;
  int year;
} Date;

// Structure animal
typedef struct {
  int identification_number;
  char* name;
  Species species;
  Date date_of_birth;
  int weight;
  char* description;
} Animal;

//Prototypes
Date constructeur();
Animal constructeur();
void day_clean(Animal* tab, int size);
