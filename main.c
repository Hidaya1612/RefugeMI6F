#include "refuge.h"

int main(){
    
    //Initialisation
    Animal tab_animaux[TAILLE];
    int nb_animaux = stockage_animaux(tab_animaux, TAILLE);
    
    printf("\n\nBienvenue dans le refuge AdoptMe !\n\n");
    //appel du menu
    afficherMenu(tab_animaux, TAILLE, nb_animaux);
    return 0;
}
