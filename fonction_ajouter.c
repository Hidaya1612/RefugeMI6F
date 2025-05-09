#include "refuge.h"

int scan(char* mode, void* input){
    int a=scanf(mode, input);
    while(getchar()!='\n'){};
    if(a<=0){
        scan(mode,input);
    }
    return a;
}

void  corrigeNom(char mot[]){
    // Vérification si le nom est vide
    if (mot[0] == '\0') {
        printf("Erreur sur le prénom!\n");
	    exit(1);
    }
    
    for (int i = 0; mot[i] != '\0'; i++) {
        if ((mot[i] < 'a' || mot[i] > 'z') && (mot[i] < 'A' || mot[i] > 'Z')) {
                printf("Erreur : Le nom contient un caractère non alphabétique : '%c'\n", mot[i]);
                exit(1);
        }
    }

    // Correction de la première lettre
    if (mot[0] >= 'a' && mot[0] <= 'z') { // La première est minuscule
        mot[0] -= 32;
    }

    // Les autres lettres
    int i = 1;
    while (mot[i] != '\0') {
        if (mot[i] >= 'A' && mot[i] <= 'Z') { // Si majuscule
            mot[i] += 32; // Convertir en minuscule
        }
        i++;
    }
}


void ajouter_Animal(Animal* tab, int taille, int* pnb_animaux){
    
    int nb_animaux=*pnb_animaux;
    
    if (tab == NULL || pnb_animaux == NULL || taille<=0 || nb_animaux<0 || nb_animaux>taille){
        printf("allocation échoué ou taille/nombre animaux incohérente\n");
        exit(1);
    }
    
    if (nb_animaux==50){
        printf ("Le refuge ne prend plus d'animaux.\n");
    }
    else{
        char temporaire_nom[100];
        char temporaire_descriptif[100];
        int choix_descriptif;
        int tmp=-1;
        tab[nb_animaux].identification_number=tab[nb_animaux-1].identification_number+1;
        
        // Saisie des informations de l'animal
        
        printf("Veuillez saisir le nom de l'animal : \n");
        if(scan("%s",temporaire_nom)!=1){
            printf("Erreur dans la saisie du nom!n");
            exit(1);
        }
        tab[nb_animaux].name=NULL;
        tab[nb_animaux].name=malloc(strlen(temporaire_nom)*(sizeof(char)+1));
        if(tab[nb_animaux].name==NULL){
            printf("Allocation réalisée pour le prénom de l'animal échouée\n");
            exit(1);
        }
        tab[nb_animaux].name=temporaire_nom;
        corrigeNom(tab[nb_animaux].name);
        //printf("%s\n",tab[nb_animaux].name);
        
        printf("Veuillez saisir l'espece de l'animal :\n 0 pour chien\n 1 pour chat\n 2 pour hamster\n 3 pour autruche\n");
        if (scan("%d",&tmp)!= 1 || tmp < 0 || tmp > 3) {
            printf("Erreur de la saisie de l'espece! \n");
            exit(1);
        }
        tab[nb_animaux].species=tmp;
        //printf("%d\n",tab[nb_animaux].species);
        
        printf("Veuillez saisir le poids de l'animal: \n");
        if (scan("%f", &tab[nb_animaux].weight)!=1 || tab[nb_animaux].weight < 0 || tab[nb_animaux].weight > 150){
            printf("Erreur dans la saisie du poids ! \n");
            exit(1);
        }
        //printf("%f",tab[nb_animaux].weight);
    
        printf("Veuillez saisir l'année de naissance de l'animal: \n");
        if (scan("%d", &tab[nb_animaux].year_of_birth)!= 1 || tab[nb_animaux].year_of_birth<1980 || tab[nb_animaux].year_of_birth>2025) {
            printf("Erreur dans la saisie de l'année de naissance de l'animal!\n");
            exit(1);
        }
        //printf("%d",tab[nb_animaux].year_of_birth);
        
        printf("Voulez-vous ajouter une description sur l'animal:\n tapez 1 pour oui sinon tapez 2\n");
        if (scan("%d",&choix_descriptif)!=1 || choix_descriptif<1 || choix_descriptif>2){
            printf("Mauvaise saisie par rapport au choix de vouloir ajouter un descriptif à l'animal!\n");
            exit(1);
        }
        tab[nb_animaux].description=NULL;
        if (choix_descriptif==1){
            printf("Veuillez saisir une description sur l'animal :\n ");
            if(scan("%[^\n]",temporaire_descriptif)!=1 ){
                printf("Erreur dans la saisie de la description!\n");
                exit(1);
            }
            tab[nb_animaux].description=malloc(strlen(temporaire_descriptif)*sizeof(char)+1);
            if(tab[nb_animaux].description==NULL){
                printf("Allocation réalisée pour le prénom de l'animal échouée\n");
                exit(1);
            }
            tab[nb_animaux].description=temporaire_descriptif;
            //printf("%s",tab[nb_animaux].description);
        }
        else{
            tab[nb_animaux].description=malloc(1);
            tab[nb_animaux].description[0]='\0';
        }
        
        FILE* fichier=NULL;
        fichier=fopen("animaux/liste_animaux.txt","a+");
        if (fichier==NULL ){
            printf("Ouverture du fichier impossible\n");
            exit(1);
        }
        
        fprintf(fichier,"%d %s %d %d %f",tab[nb_animaux].identification_number,tab[nb_animaux].name,tab[nb_animaux].species,tab[nb_animaux].year_of_birth,tab[nb_animaux].weight);
        if (strlen(tab[nb_animaux].description)!=0){
            fprintf(fichier," %s;\n",tab[nb_animaux].description);
        }
        else{
            fprintf(fichier,";\n");
        }
        rewind(fichier);
        fclose(fichier);
        (*pnb_animaux)++;
          
    }
    afficherMenu(tab, TAILLE, nb_animaux);
}
