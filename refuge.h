// Bibliothèques
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define TAILLE 50

// Enumeration espèces
typedef enum {
    CHIEN, CHAT, HAMSTER, AUTRUCHE
  } Espece;

// Structure animal
typedef struct {
    int num_identification;
    char* nom;
    Espece espece;
    int annee_de_naissance;
    float poids;
    char* description;
} Animal;

//Prototypes

void scan(char* mode, void* input); // procédure verification scanf
int corrigeNom(char mot[]); // fonction qui corrige le prenom
int stockage_animaux(Animal* tab, int taille); // fonction sauvegarde fichier
void ajouter_Animal(Animal* tab, int taille, int* pnb_animaux); // procedure qui demande les informations de l'animal a l'utilisateur et qui l'ajoute ensuite dans le fichier
void adoption_animal(Animal* tab, int taille, int* pnb_animaux); // procedure qui retire un animal du fichier a partir de son numero d'identification
void afficherMenu(Animal* tab, int taille, int nb_animaux); // affichage du menu et des differents choix
Animal* rechercheparNom(char* nomRecherche, Animal animaux[], int* nb_animaux); // fonction qui recherche un animal a partir de son nom
Animal* rechercheparEspece(Espece s, Animal animaux[], int* nb_animaux); // fonction qui recherche un animal a partir de son espece
Animal* rechercheparAge(int ageType, Animal animaux[], int* nb_animaux); // fonction qui recherche un animal a partir de son age
void afficheAnimaux(Animal tab[], int nb_animaux); // procedure qui affiche les differentes informations des animaux 
void rechercherAnimaux(Animal tab[], int nb_animaux); // procedure qui recherche un ou des animal/animaux en fonction du critere choisi
void extremums(Animal* tab, int nb_animaux, int* pMin, int* pMax); // procedure qui recupere l'age maximum et l'age minimum des animaux du refuge
void inv_age_asc(Animal* tab, int nb_animaux); // procedure qui affiche le nombre total d'animaux et qui affiche le nombre d'animaux par quartile
void nettoyage(Animal* tab, int taille, int nb_animaux); // procedure qui affiche le temps de nettoyage necessaire pour le refuge
