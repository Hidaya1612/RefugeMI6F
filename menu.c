#include"refuge.h"

//procédure du menu
void afficherMenu(Animal* tab_animaux, int taille, int nb_animaux){
    int choix;
    printf("\n**************MENU PRINCIPAL**************\n");
    printf("1. Afficher les animaux du refuge\n");
    printf("2. Rechercher un animal\n");
    printf("3. Ajouter un animal qui vous a ete confie\n");
    printf("4. Adopter un animal\n");
    printf("5. Inventaire du refuge (par age)\n");
    printf("6. Gestion du nettoyage hebdomadaire\n");
    printf("7. Quitter\n");

    printf("Votre choix : ");//demande à l'utilsateur l'action qu'il souhaite effectuer
    scan("%d", &choix);
    while(choix < 0 || choix > 7){
        printf("mauvaise saisie du choix.\n");
        printf("ressaisir votre choix\n");
        scan("%d", &choix);
    }

    //appel des fonctions par rapport à la saisie
    switch (choix) {
        case 1:
            afficheAnimaux(tab_animaux, nb_animaux);
            
        afficherMenu(tab_animaux, TAILLE, nb_animaux);
        break;
        case 2:
            rechercherAnimaux(tab_animaux, nb_animaux);
            afficherMenu(tab_animaux, TAILLE, nb_animaux);
        break;
        case 3:
            ajouter_Animal(tab_animaux,TAILLE,&nb_animaux);

        break;
        case 4:
            adoption_animal(tab_animaux,TAILLE,&nb_animaux);
        break;
        case 5:
            inv_age_asc(tab_animaux, nb_animaux);
        break;

        case 6:
            nettoyage(tab_animaux,TAILLE,nb_animaux);
        break;
        case 7:
            printf("Au revoir !\n");
        break;
    }
}
