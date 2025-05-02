#define MAX_ANIMAUX=50

Animal trouverAnimaux(Animal tab[]){
	int nb_animaux=0;
	
	FILE* fichier=fopen(liste_animaux.txt, "r");
	if(fichier==NULL){
		exit(1);
	}
	while(nb_animaux<MAX_ANIMAUX){
		fscanf
		fgets
	}
	
	
}



Animal* rechercheparNom(char* nomRecherche, Animal animaux[], int* nb_animaux) {
    int found = 0;
    int count=0;
    for (int i = 0; i<*nb_animaux; i++) {
        if (strcmp(animaux[i].name, nomRecherche) == 0) {
            found = 1;
            count++;
        }
    }
    if (found!=1) {
        return NULL;
    }

    Animal* tab1=malloc(count*sizeof(Animal));
    if (tab1 == NULL) {
        exit(1);
    }
    int j=0;
    for (int i = 0; i <*nb_animaux; i++) {
        if (strcmp(animaux[i].name, nomRecherche) == 0) {
            tab1[j]=animaux[i];
            j++;
        }
    }
    *nb_animaux=count;
    return tab1;
}


Animal* rechercheparEspece(Species s, Animal animaux[], int* nb_animaux) {
    int found=0;
    int count=0;
    for (int i = 0; i < *nb_animaux; i++) {
        if (animaux[i].species == s) {
            found = 1;
            count++;
        }
    }
    if (found!=1) {
        return NULL;
    }
    Animal* tab2=malloc(count*sizeof(Animal));
    if (tab2 == NULL) {
        exit(1);
    }
    int j=0;
    for (int i = 0; i < count; i++) {
        if (animaux[i].species == s) {
            tab2[j]=animaux[i];
            j++;
        }
    }
    *nb_animaux=count;
    return tab2;

}

Animal* rechercheparAge(int ageType, Animal animaux[], int* nb_animaux) {
    int count = 0;
    for (int i = 0; i < *nb_animaux; i++) {
        int age = 2025 - animaux[i].date_of_birth.year;
        if (animaux[i].date_of_birth.month > 1 || (animaux[i].date_of_birth.month == 1 && animaux[i].date_of_birth.day > 1)) {
            age--;
           }
        if ((ageType == 1 && age < 2) || (ageType == 2 && age > 10)) {
            count++;
        }
    }
    if (count == 0) {
        return NULL;
    }

    Animal* tab3 = malloc(count * sizeof(Animal));
    if (tab3 == NULL) {
        exit(1);
    }

    int j = 0;
    for (int i = 0; i < *nb_animaux; i++) {
        int age = 2025 - animaux[i].date_of_birth.year;
        if (animaux[i].date_of_birth.month > 1 || (animaux[i].date_of_birth.month == 1 && animaux[i].date_of_birth.day > 1)) {
            age--;
           }
        if ((ageType == 1 && age < 2) || (ageType == 2 && age > 10)) {
            tab3[j] = animaux[i];
            j++;
        }
    }
    *nb_animaux = count;
    return tab3;
}

void afficheAnimaux(Animal animal[], int nb_animaux) {
    for (int i = 0; i < nb_animaux; i++) {
        printf("Name: %s, ID: %d, Specie: %d, Birth Year: %d, Weight: %d, Description: %s\n", animal[i].name, animal[i].identification_number, animal[i].species, animal[i].date_of_birth.year, animal[i].weight, animal[i].description);
    }
}


Animal* rechercherAnimaux(Animal tab[], int* nb_animaux) {
	tab[50];
	for(int i=0;i<50;i++){
		tab[i]=
	}
	trouverAnimaux(tab);

    int test = 0;
    int ageType=0;
    char name[100];
    int species=0;
    int choix=0;

    printf("A partir de quel critere voulez vous rechercher l'animal:\n");
    printf("1. Nom\n");
    printf("2. Espèce\n");
    printf("3. Type d'âge\n");
    do {
        test = scanf("%d", &choix);
        while (getchar() != '\n') {};
    } while (test <= 0 || choix < 1 || choix > 3);

        switch (choix) {
            case 1:
                printf("Entrez le nom : ");
                do {
                    test = scanf("%s", &name);
                    while (getchar() != '\n') {};
                } while (test <= 0);
                rechercheparNom(name,a, *nb_animaux);
                afficheAnimaux(a, *nb_animaux);
            break;
            case 2:
                printf("Entrez l'espèce (0: DOG, 1: CAT, 2: HAMSTER, 3: OSTRICH) : ");
                do {
                    test = scanf("%d", &species);
                    while (getchar() != '\n') {};
                } while (test <= 0 || species < 0 || species > 3);
                rechercheparEspece(species,a, *nb_animaux);
                afficheAnimaux(a, *nb_animaux);
                break;
            case 3:
                printf("Entrez le type d'âge (1: Jeune <2 ans, 2: Senior >10 ans) : ");
                do {
                    test = scanf("%d", &ageType);
                    while (getchar() != '\n') {};
                } while (test <= 0 || (ageType != 1 && ageType != 2));
                rechercheparAge(ageType, a, *nb_animaux);
                afficheAnimaux(a, *nb_animaux);
                break;

            default:
                printf("Choix invalide.\n");
        }
    printf("voulez vous rechercher a partir d'un autre critere");
    printf("appuyez sur 1 si oui, 0 sinon");
    if (choix == 1) {
        rechercherAnimaux(a, *nb_animaux);
    }
}

