#include"refuge.h"

Animal* rechercheparNom(char* nomRecherche, Animal animaux[], int* nb_animaux) { // Recherche un animal à partir de son nom
    if (nomRecherche==NULL || nb_animaux==NULL || *nb_animaux<=0) {
        return NULL;
    }

    int cmp=0; // Compteur pour le nombre d'animaux trouvés
    for (int i = 0; i<*nb_animaux; i++) { // Parcourt le tableau d'animaux pour comparer les noms
        if (strcmp(animaux[i].nom, nomRecherche) == 0) {
            cmp++;
        }
    }
    if (cmp==0) { // Si aucun animal n'est trouvé avec le nom recherché
        *nb_animaux=0;
        return NULL;
    }
    // Alloue dynamiquement un tableau pour stocker les animaux trouvés
    Animal* tab1=malloc(cmp*sizeof(Animal));
    if (tab1 == NULL) {
        exit(1);
    }
    int j=0;
    for (int i = 0; i <*nb_animaux; i++) { // Remplit le tableau avec les animaux correspondants
        if (strcmp(animaux[i].nom, nomRecherche) == 0) {
            tab1[j]=animaux[i];
            j++;
        }
    }
    *nb_animaux = cmp; // Met à jour le nombre d'animaux trouvés
    return tab1;
}


Animal* rechercheparEspece(Espece s, Animal animaux[], int* nb_animaux) { // Recherche un animal à partir de son espèce
    if (nb_animaux==NULL) {
        exit(0);
    }

    int cmp=0;
    for (int i = 0; i < *nb_animaux; i++) { // Parcourt le tableau pour comparer les espèces
        if (animaux[i].espece == s) {
            cmp++;
        }
    }
    if (cmp==0) {
        *nb_animaux=0;
        return NULL;
    }
    // Alloue dynamiquement un tableau pour stocker les animaux trouvés
    Animal* tab2=malloc(cmp*sizeof(Animal));
    if (tab2 == NULL) {
        exit(1);
    }
    int j=0;
    for (int i = 0; i < *nb_animaux; i++) { // Remplit le tableau avec les animaux correspondants
        if (animaux[i].espece == s) {
            tab2[j]=animaux[i];
            j++;
        }
    }
    *nb_animaux=cmp; // Met à jour le nombre d'animaux trouvés
    return tab2;

}

Animal* rechercheparAge(int ageType, Animal animaux[], int* nb_animaux) { // Recherche un animal à partir de son âge
    if (nb_animaux==NULL) {
        exit(0);
    }
    int cmp = 0;
    for (int i = 0; i < *nb_animaux; i++) {
        int age = 2025 - animaux[i].annee_de_naissance;  // Calcule l'âge de l'animal
        if ((ageType == 1 && age < 2) || (ageType==2 && (age>=2 && age<=10))|| (ageType == 3 && age > 10)) {
            cmp++;
        }
    }
    if (cmp == 0) {
        *nb_animaux = 0;
        return NULL;
    }
    // Alloue dynamiquement un tableau pour stocker les animaux trouvés
    Animal* tab3 = malloc(cmp * sizeof(Animal));
    if (tab3 == NULL) {
        exit(1);
    }

    int j = 0;
    for (int i = 0; i < *nb_animaux; i++) { // Remplit le tableau avec les animaux correspondants
        int age = 2025 - animaux[i].annee_de_naissance;
        if ((ageType == 1 && age < 2) || (ageType==2 && (age>=2 && age<=10))|| (ageType == 3 && age > 10)) {
            tab3[j] = animaux[i];
            j++;
        }
    }
    *nb_animaux = cmp;
    return tab3;
}

void afficheAnimaux(Animal animal[], int nb_animaux) { //affiche toutes les informations de l'animal
	 if (nb_animaux==0) {
            printf("Il n'y a pas d'animaux dans le refuge.\n");
        }
	for (int i = 0; i < nb_animaux; i++) {
        switch (animal[i].espece) {
            case 0:
            printf("Nom: %s, ID: %d, Espece: Chien, Annee de naissance: %d, Poids: %.2f, Description: %s\n", animal[i].nom, animal[i].num_identification, animal[i].annee_de_naissance, animal[i].poids, animal[i].description);
            break;
            case 1:
            printf("Nom: %s, ID: %d, Espece: Chat, Annee de naissance: %d, Poids: %.2f, Description: %s\n", animal[i].nom, animal[i].num_identification, animal[i].annee_de_naissance, animal[i].poids, animal[i].description);
            break;
            case 2:
            printf("Nom: %s, ID: %d, Espece: Hamster, Annee de naissance: %d, Poids: %.3f, Description: %s\n", animal[i].nom, animal[i].num_identification, animal[i].annee_de_naissance, animal[i].poids, animal[i].description);
            break;
            case 3:
            printf("Nom: %s, ID: %d, Espece: Autruche, Annee de naissance: %d, Poids: %.2f, Description: %s\n", animal[i].nom, animal[i].num_identification, animal[i].annee_de_naissance, animal[i].poids, animal[i].description);
            break;
            default:
                printf("Espece incorrecte\n");
        }
    }
}


void rechercherAnimaux(Animal tab[], int nb_animaux) { //procédure qui recherche l'animal et l'affiche par rapport au critère choisi

	int ageType=0;
	char nom[100];
	int espece=0;
	int choix=0;
    // Demande à l'utilisateur de choisir un critère
	printf("A partir de quel critere voulez vous rechercher l'animal:\n");
	printf("1. Nom\n");
	printf("2. Espece\n");
	printf("3. Type d'age\n");
	scan("%d",&choix);
	while( choix<1 || choix>3){
       printf("Mauvaise saisie du choix.\nVeuillez ressaisir votre choix:\n");
        scan("%d",&choix);
    }
    // Effectue la recherche en fonction du critère choisi
        switch (choix) {
            case 1:

                printf("Entrez le nom : ");
                scan("%98s",&nom); // Limite la saisie à 98 caractères pour éviter le débordement
                corrigeNom(nom); // Corrige le format du nom si nécessaire
                tab=rechercheparNom(nom,tab, &nb_animaux);
            break;
            case 2:
                printf("Entrez le numero de l'espece desiree:\n0: CHIEN\n1: CHAT\n2: HAMSTER\n3: AUTRUCHE\n");
                scan("%d", &espece);
                while(espece<0 || espece>3){
                	printf("Mauvaise saisie du numero d'espece.\nVeuillez ressaisir le numero de l'espece de l'animal:\n");
                	scan("%d", &espece);
                }
                tab=rechercheparEspece(espece,tab, &nb_animaux);
                break;
            case 3:
                printf("Entrez le type d'age:\n1: Jeune <2 ans\n2: Age moyen (entre 2ans et 10 ans)\n3: Senior >10 ans\n ");
                scan("%d", &ageType);
                while(ageType <1 || ageType>3){
                	printf("Mauvaise saisie du choix.\n");
                    printf("Veuillez ressaisir votre choix:\n");
                	scan("%d", &ageType);
                }
                tab=rechercheparAge(ageType, tab, &nb_animaux);
                break;

            default:
                printf("Choix invalide.\n");
        }
    // Si aucun animal n'est trouvé, affiche un message
    if (nb_animaux==0) {
        printf("Aucun animal ne correspond a votre recherche.\n");
    }
    else {
	afficheAnimaux(tab, nb_animaux);
        int continuer=0;
        printf("Voulez-vous approfondir votre recherche a partir d'un autre critere.\n");
        printf("Appuyez sur 1 si oui, 0 sinon:\n");
        scan("%d",&continuer);
        while(continuer != 1 && continuer !=0){
                	printf("Mauvaise saisie du choix.\nVeuillez saisir une valeur correcte:\n ");
                	scan("%d",&continuer);
                }

        // Relance la recherche si l'utilisateur le souhaite
        if (continuer == 1) {
            rechercherAnimaux(tab, nb_animaux);
        }

    }

}
