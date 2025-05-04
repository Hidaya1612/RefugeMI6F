#include "refuge.h"

void  corrigeNom(Animal* a){
    // Vérification si le nom est vide
    if (a->name == NULL || a->name[0] == '\0') {
        printf("Erreur : Le nom est vide.\n");
        return;
    }

    for (int i = 0; a->name[i] != '\0'; i++) {
        if ((a->name[i] < 'a' || a->name[i] > 'z') && (a->name[i] < 'A' || a->name[i] > 'Z')) {
            printf("Erreur : Le nom contient un caractère non alphabétique : '%c'\n", a->name[i]);
            exit(1);
        }
    }

    // Correction de la première lettre
    if (a->name[0] >= 'a' && a->name[0] <= 'z') { // La première est minuscule
        a->name[0] -= 32;
    }

    // Les autres lettres
    int i = 1;
    while (a->name[i] != '\0') {
        if (a->name[i] >= 'A' && a->name[i] <= 'Z') { // Si majuscule
            a->name[i] += 32; // Convertir en minuscule
        }
        i++;
    }
}

Animal ajouter_Animal(FILE* f1){
    Animal a;

    //Gestion des fichiers
    if (f1 == NULL){
        printf("Ouverture du fichier impossible\n");
        exit(1);
    }

    // Allocation mémoire
    a.name = malloc(50 * sizeof(char));;
    a.description = malloc(50 * sizeof(char));
    if (a.name==NULL || a.description==NULL) {
        printf("Erreur d'allocation mémoire\n");
        exit(1);
    }

    // Saisie des informations de l'animal
    printf("Veuillez saisir le numéro d'identification de l'animal\n");
    if(scanf("%d",&a.identification_number)!=1 || a.identification_number<1 || a.identification_number>39 ){
        printf("Erreur dans la saisie du numéro d'identification ! \n");
        exit(1);
    }

    printf("Veuillez saisir le nom de l'animal : \n");
    if(scanf("%s",a.name)!=1){
        printf("Erreur dans la saisie du nom!n");
        exit(1);
    }
    corrigeNom(&a);

    // Affichage du nom corrigé
    printf("Nom corrigé : %s\n", a.name);

    printf("Veuillez saisir l'espece de l'animal : 0 pour chien\n 1 pour chat\n 2 pour hamster\n 3 pour autruche\n");
    if (scanf("%d",&a.species)!= 1 || a.species < 0 || a.species > 3) {
        printf("Erreur de la saisie de l'espece! \n");
        exit(1);
    }

    printf("Veuillez saisir le poid de l'animal: \n");
    if (scanf("%f", &a.weight)!=1 || a.weight < 0 || a.weight > 150){
        printf("Erreur dans la saisie du poids ! \n");
        exit(1);
    }

    printf("Veuillez saisir l'année de naissance de l'animal: \n");
    if (scanf("%d", &a.year_of_birth)!= 1 || a.year_of_birth<1980 || a.year_of_birth>2025){
        printf("Erreur dans la saisie de l'année de naissance de l'animal!\n");
        exit(1);
    }

    printf("Veuillez saisir une description sur l'animal (facultatif) : \n");
        while (getchar() != '\n');
        if (fgets(a.description, TAILLE, stdin) == NULL || a.description[0] == '\n') {
            strcpy(a.description, "Aucune description");
        }else {
            a.description[strcspn(a.description, "\n")] = '\0'; // Supprimer le saut de ligne
        }

    fprintf(f1, "%s %d %d %f %s ;\n", a.name, a.species, a.year_of_birth, a.weight, a.description);
    return a;
}





