#include "refuge.h"

void scan(char* mode, void* input){ //vérifie que les retours du scan soient bien positifs
    int a=scanf(mode, input);
    while(getchar()!='\n'){};
    if(a<=0){
    	printf("Erreur scanf, entrer une valeur correcte.\n");
        scan(mode,input); // Relance la saisie en cas d’erreur
    }
}

int  corrigeNom(char mot[]){ //corrige les prénoms saisis par les utilisateurs
    // Vérification si le nom est vide
    if (mot[0] == '\0') {
        printf("Erreur sur le prénom!\n");
	    return 1;
    }

    //Vérifie  si les caractères saisis sont bien des lettres
    for (int i = 0; mot[i] != '\0'; i++) {
        if ((mot[i] < 'a' || mot[i] > 'z') && (mot[i] < 'A' || mot[i] > 'Z')) {
                printf("Erreur : Le nom contient un caractere non alphabetique : '%c'\n", mot[i]);
	  	  return 1;
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
    return 0; // Nom valide et corrigé
}


void ajouter_Animal(Animal* tab, int taille, int* pnb_animaux){ //ajoute un animal au tableau et au fichier
    int nb_animaux=*pnb_animaux;

    //Vérification des paramètres
    if (tab == NULL || pnb_animaux == NULL || taille<=0 || nb_animaux<0 || nb_animaux>taille){
        printf("allocation échoué ou taille/nombre animaux incohérente\n");
        exit(1);
    }

    // Si le refuge est plein
    if (nb_animaux==50){
        printf ("Le refuge ne prend plus d'animaux.\n");
        afficherMenu(tab, TAILLE, *pnb_animaux);
    }
    else{
	// Variables temporaires pour stocker les infos saisies
        char temporaire_nom[100];
        char temporaire_descriptif[100];
        int choix_descriptif;
        int tmp=-1;
	// Génération automatique de l'identifiant
        tab[nb_animaux].num_identification=tab[nb_animaux-1].num_identification+1;

        // Saisie des informations de l'animal
	//----Nom----
        printf("Veuillez saisir le nom de l'animal : \n");
        scan("%98s",temporaire_nom);
        
        int test = corrigeNom(temporaire_nom);
        while (test == 1){
		scan("%98s",temporaire_nom);

		test = corrigeNom(temporaire_nom);
        }

        tab[nb_animaux].nom=NULL;
        tab[nb_animaux].nom=malloc(strlen(temporaire_nom)*(sizeof(char)+1));
        if(tab[nb_animaux].nom==NULL){
            printf("Allocation réalisée pour le prénom de l'animal échouée\n");
            exit(1);
        }
        tab[nb_animaux].nom=temporaire_nom;

	    
	//----Espèce----
        printf("Veuillez saisir l'espece de l'animal :\n 0 pour chien\n 1 pour chat\n 2 pour hamster\n 3 pour autruche\n");
	scan("%d",&tmp);
	while(tmp < 0 || tmp > 3){
		printf("Erreur de la saisie de l'espece! \n");
		scan("%d",&tmp);
	}
	    
	//Variable intermédiaire
        tab[nb_animaux].espece=tmp;
	    
	//----Poids----
        printf("Veuillez saisir le poids de l'animal: \n");
	scan("%f", &tab[nb_animaux].poids);
	while(tab[nb_animaux].poids <= 0 || tab[nb_animaux].poids > 150){
		printf("Erreur de la saisie du poids! \n");
		scan("%f", &tab[nb_animaux].poids);
	}

	//----Année de naissance----
        printf("Veuillez saisir l'année de naissance de l'animal: \n");
	scan("%d", &tab[nb_animaux].annee_de_naissance);
	while(tab[nb_animaux].annee_de_naissance<1980 || tab[nb_animaux].annee_de_naissance>2025){
		printf("Erreur de la saisie de l'annee de naissance! \n");
		scan("%d", &tab[nb_animaux].annee_de_naissance);
	}

	//----Description----
        printf("Voulez-vous ajouter une description sur l'animal:\n tapez 1 pour oui sinon tapez 2\n");
	scan("%d",&choix_descriptif);
	while(choix_descriptif<1 || choix_descriptif>2){
		printf("Erreur de la saisie du choix pour ajouter un descriptif à l'animal!! \n");
		scan("%d",&choix_descriptif);
	}
        tab[nb_animaux].description=NULL;
        if (choix_descriptif==1){
            printf("Veuillez saisir une description sur l'animal :\n ");
            scan("%98[^\n]",temporaire_descriptif);
            tab[nb_animaux].description=malloc(strlen(temporaire_descriptif)*sizeof(char)+1);
            if(tab[nb_animaux].description==NULL){
                printf("Allocation réalisée pour le prénom de l'animal échouée\n");
                exit(1);
            }
            tab[nb_animaux].description=temporaire_descriptif;
        }
        else{
            tab[nb_animaux].description=NULL;
        }

	//Gestion du fichier
        FILE* fichier=NULL;
        fichier=fopen("Animaux/liste_animaux.txt","a+");
        if (fichier==NULL ){
            printf("Ouverture du fichier impossible\n");
            exit(1);
        }

	//Ecriture du nouvel animal dans le fichier
        fprintf(fichier,"%d %s %d %d %f",tab[nb_animaux].num_identification,tab[nb_animaux].nom,tab[nb_animaux].espece,tab[nb_animaux].annee_de_naissance,tab[nb_animaux].poids);
        if (tab[nb_animaux].description != NULL){
            fprintf(fichier," %s;\n",tab[nb_animaux].description);
        }
        else{
            fprintf(fichier,";\n");
        }
        rewind(fichier);
        fclose(fichier);
        *pnb_animaux=stockage_animaux(tab,taille); //Mise a jour du nombre d'animaux
	printf("L'animal %s a bien ete ajoute au refuge.\n", tab[nb_animaux].nom);
	afficherMenu(tab, TAILLE, *pnb_animaux);
    }
    
    
}
