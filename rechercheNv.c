#include"refuge.h"

Animal* rechercheparNom(char* nomRecherche, Animal animaux[], int* nb_animaux) {
    if (animaux==NULL || nomRecherche==NULL || nb_animaux==NULL || *nb_animaux<=0) {
        return NULL;
    }

    int count=0;
    for (int i = 0; i<*nb_animaux; i++) {
        if (strcmp(animaux[i].name, nomRecherche) == 0) {
            count++;
        }
    }
    if (count==0) {
        *nb_animaux=0;
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
    *nb_animaux = count;
    return tab1;
}


Animal* rechercheparEspece(Species s, Animal animaux[], int* nb_animaux) {
    if (animaux==NULL || nb_animaux==NULL) {
        exit(0);
    }

    int count=0;
    for (int i = 0; i < *nb_animaux; i++) {
        if (animaux[i].species == s) {
            count++;
        }
    }
    if (count==0) {
        *nb_animaux=0;
        return NULL;
    }
    Animal* tab2=malloc(count*sizeof(Animal));
    if (tab2 == NULL) {
        exit(1);
    }
    int j=0;
    for (int i = 0; i < *nb_animaux; i++) {
        if (animaux[i].species == s) {
            tab2[j]=animaux[i];
            j++;
        }
    }
    *nb_animaux=count;
    return tab2;

}

Animal* rechercheparAge(int ageType, Animal animaux[], int* nb_animaux) {
    if (animaux==NULL || nb_animaux==NULL) {
        exit(0);
    }
    int count = 0;
    for (int i = 0; i < *nb_animaux; i++) {
        int age = 2025 - animaux[i].year_of_birth;
        if ((ageType == 1 && age < 2) || (ageType == 2 && age > 10)) {
            count++;
        }
    }
    if (count == 0) {
        *nb_animaux = 0;
        return NULL;
    }

    Animal* tab3 = malloc(count * sizeof(Animal));
    if (tab3 == NULL) {
        exit(1);
    }

    int j = 0;
    for (int i = 0; i < *nb_animaux; i++) {
        int age = 2025 - animaux[i].year_of_birth;
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
        printf("Name: %s, ID: %d, Specie: %d, Birth Year: %d, Weight: %f, Description: %s\n", animal[i].name, animal[i].identification_number, animal[i].species, animal[i].year_of_birth, animal[i].weight, animal[i].description);
    }
}


Animal* rechercherAnimaux(Animal tab[], int nb_animaux) {
    if (tab == NULL) {
        tab=malloc(TAILLE*sizeof(Animal));
        nb_animaux=stockage_animaux(tab,TAILLE);
        printf("nb_animaux avant recherche: %d\n", nb_animaux);
        fflush(stdout);
    }

   	int test = 0;
	int ageType=0;
    char name[100];
    int species=0;
    int choix=0;

    printf("A partir de quel critere voulez vous rechercher l'animal:\n");
    printf("1. Nom\n");
    printf("2. Espèce\n");
    printf("3. Type d'âge\n");
    if (scan("%d",&choix)!=1 || choix<1 || choix>3){
        printf("Mauvaise saisie du choix\n");
        exit(13);
    }

        switch (choix) {
            case 1:

                printf("Entrez le nom : ");
                if (scan("%s",&name)!=1){
                    printf("Erreur dans la saisie du nom.\n");
                    exit(13);
                }
                corrigeNom(name);
                tab=rechercheparNom(name,tab, &nb_animaux);
                afficheAnimaux(tab, nb_animaux);
            break;
            case 2:
                printf("Entrez l'espèce (0: DOG, 1: CAT, 2: HAMSTER, 3: OSTRICH) : ");
                if (scan("%d",&species)!=1 || species<0 || species>3){
                    printf("Mauvaise saisie dans le numero d'espece.\n");
                    exit(13);
                }
                tab=rechercheparEspece(species,tab, &nb_animaux);
                afficheAnimaux(tab, nb_animaux);

                break;
            case 3:
                printf("Entrez le type d'âge (1: Jeune <2 ans, 2: Senior >10 ans) : ");
                if (scan("%d",&ageType)!=1 || (ageType != 1 && ageType != 2)){
                    printf("Mauvaise saisie dans le type d'age.\n");
                    exit(13);
                }
                tab=rechercheparAge(ageType, tab, &nb_animaux);
                afficheAnimaux(tab, nb_animaux);
                break;

            default:
                printf("Choix invalide.\n");
        }
    if (nb_animaux==0) {
        printf("Aucun animal ne correspond a votre recherche\n");
	afficherMenu(tab, TAILLE, nb_animaux);
    }
    else {
        int continuer=0;
        printf("voulez vous rechercher a partir d'un autre critere\n");
        printf("appuyez sur 1 si oui, 0 sinon\n");
        if (scan("%d",&continuer)!=1 ||  continuer != 1 && continuer !=0){
            printf("Mauvaise saisie du choix\n");
            exit(13);
        }

        if (continuer == 1) {
            rechercherAnimaux(tab, nb_animaux);
        }
	    else{
		afficherMenu(tab, TAILLE, nb_animaux);
	    }
    }

}
