#include "refuge.h"

int main(){

    Animal* tab_animaux=NULL;


    tab_animaux=malloc(TAILLE*sizeof(Animal));
    if (tab_animaux==NULL){
        printf("Allocation échouée\n");
        exit(1);
    }

    int nb_animaux = stockage_animaux(tab_animaux, TAILLE);


    afficherMenu(tab_animaux, TAILLE, nb_animaux);
    return 0;
}
