#include"refuge.h"

//procédure du menu
void afficherMenu(Animal* tab_animaux, int taille, int nb_animaux){
    int choix;
    printf("\n**************MENU PRINCIPAL**************\n");
    printf("1. Rechercher un animal\n");
    printf("2. Ajouter un animal qui vous a ete confie\n");
    printf("3. Adopter un animal\n");
    printf("4. Inventaire du refuge (par age)\n");
    printf("5. Gestion du nettoyage hebdomadaire\n");
    printf("6. Quitter\n");

    printf("Votre choix : ");//demande à l'utilsateur l'action qu'il souhaite effectuer
    scan("%d", &choix);
    while(choix < 0 || choix > 6){
        printf("mauvaise saisie du choix.\n");
        printf("ressaisir votre choix\n");
        scan("%d", &choix);
    }

    //appel des fonctions par rapport à la saisie
    switch (choix) {
        case 1:
            rechercherAnimaux(tab_animaux, nb_animaux);
        afficherMenu(tab_animaux, TAILLE, nb_animaux);
        break;
        case 2:
            ajouter_Animal(tab_animaux,TAILLE,&nb_animaux);

        break;
        case 3:
            adoption_animal(tab_animaux,TAILLE,&nb_animaux);
        break;
        case 4:
            inv_age_asc(tab_animaux, nb_animaux);
        break;

        case 5:
            nettoyage(tab_animaux,TAILLE,nb_animaux);
        break;
        case 6:
            printf("Au revoir !\n");
        break;
    }
}
