#include "refuge.h"

int main(){

    Animal tab_animaux[TAILLE];
    int nb_animaux = stockage_animaux(tab_animaux, TAILLE);
    
    printf("\n\nBienvenue dans le refuge blabla !\n\n");
    afficherMenu(tab_animaux, TAILLE, nb_animaux);
    return 0;
}
