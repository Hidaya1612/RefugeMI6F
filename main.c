#include "refuge.h"

int main(){

    Animal* tab_animaux[TAILLE];
    int nb_animaux = stockage_animaux(tab_animaux, TAILLE);


    afficherMenu(tab_animaux, TAILLE, nb_animaux);
    return 0;
}
