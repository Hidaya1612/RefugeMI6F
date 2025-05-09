#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
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
//Date constructeur();
int stockage_animaux(Animal* tab, int taille);
void scan(char* mode, void* input);
void corrigeNom(char mot[]);
void ajouter_Animal(Animal* tab, int taille, int* pnb_animaux);
void adoption_animal(Animal* tab, int taille, int* pnb_animaux);
void day_clean(Animal* tab, int taille, int nb_animaux);
void afficherMenu(Animal* tab, int taille, int nb_animaux);
void rechercherAnimaux(Animal tab[], int nb_animaux);
Animal* rechercheparNom(char* nomRecherche, Animal animaux[], int* nb_animaux);
Animal* rechercheparEspece(Species s, Animal animaux[], int* nb_animaux);
Animal* rechercheparAge(int ageType, Animal animaux[], int* nb_animaux);
void extremums(Animal* tab, int nb_animaux, int* pMin, int* pMax);
void inv_age_asc(Animal* tab, int nb_animaux);



