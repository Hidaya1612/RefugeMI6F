#include"refuge.h"

Animal* rechercheparNom(char* nomRecherche, Animal animaux[], int* nb_animaux) { //fonction qui recherche un animal à partir de son nom
    if (animaux==NULL || nomRecherche==NULL || nb_animaux==NULL || *nb_animaux<=0) {
        return NULL;
    }

    int cmp=0;
    for (int i = 0; i<*nb_animaux; i++) {
        if (strcmp(animaux[i].nom, nomRecherche) == 0) {
            cmp++;
        }
    }
    if (cmp==0) {
        *nb_animaux=0;
        return NULL;
    }

    Animal* tab1=malloc(cmp*sizeof(Animal));
    if (tab1 == NULL) {
        exit(1);
    }
    int j=0;
    for (int i = 0; i <*nb_animaux; i++) {
        if (strcmp(animaux[i].nom, nomRecherche) == 0) {
            tab1[j]=animaux[i];
            j++;
        }
    }
    *nb_animaux = cmp;
    return tab1;
}


Animal* rechercheparEspece(Espece s, Animal animaux[], int* nb_animaux) { //fonction qui recherche un animal à partir de son espèce
    if (animaux==NULL || nb_animaux==NULL) {
        exit(0);
    }

    int cmp=0;
    for (int i = 0; i < *nb_animaux; i++) {
        if (animaux[i].espece == s) {
            cmp++;
        }
    }
    if (cmp==0) {
        *nb_animaux=0;
        return NULL;
    }
    Animal* tab2=malloc(cmp*sizeof(Animal));
    if (tab2 == NULL) {
        exit(1);
    }
    int j=0;
    for (int i = 0; i < *nb_animaux; i++) {
        if (animaux[i].espece == s) {
            tab2[j]=animaux[i];
            j++;
        }
    }
    *nb_animaux=cmp;
    return tab2;

}

Animal* rechercheparAge(int ageType, Animal animaux[], int* nb_animaux) { ////fonction qui recherche un animal à partir de son âge
    if (animaux==NULL || nb_animaux==NULL) {
        exit(0);
    }
    int cmp = 0;
    for (int i = 0; i < *nb_animaux; i++) {
        int age = 2025 - animaux[i].annee_de_naissance;
        if ((ageType == 1 && age < 2) || (ageType==2 && (age>=2 && age<=10))|| (ageType == 3 && age > 10)) {
            cmp++;
        }
    }
    if (cmp == 0) {
        *nb_animaux = 0;
        return NULL;
    }

    Animal* tab3 = malloc(cmp * sizeof(Animal));
    if (tab3 == NULL) {
        exit(1);
    }

    int j = 0;
    for (int i = 0; i < *nb_animaux; i++) {
        int age = 2025 - animaux[i].annee_de_naissance;
        if ((ageType == 1 && age < 2) || (ageType==2 && (age>=2 && age<=10))|| (ageType == 2 && age > 10)) {
            tab3[j] = animaux[i];
            j++;
        }
    }
    *nb_animaux = cmp;
    return tab3;
}

void afficheAnimaux(Animal animal[], int nb_animaux) { //affiche toutes les informations de l'animal
    for (int i = 0; i < nb_animaux; i++) {
        printf("Nom: %s, ID: %d, Espece: %d, Annee de naissance: %d, Poids: %f, Description: %s\n", animal[i].nom, animal[i].num_identification, animal[i].espece, animal[i].annee_de_naissance, animal[i].poids, animal[i].description);
    }
}


void rechercherAnimaux(Animal tab[], int nb_animaux) { //procédure qui recherche l'animal et l'affiche par rapport au critère choisi
    if (tab == NULL) {
        tab=malloc(TAILLE*sizeof(Animal));
        nb_animaux=stockage_animaux(tab,TAILLE);
        printf("nb_animaux avant recherche: %d\n", nb_animaux);
        fflush(stdout);
    }


	int ageType=0;
    char nom[100];
    int espece=0;
    int choix=0;

    printf("A partir de quel critere voulez vous rechercher l'animal:\n");
    printf("1. Nom\n");
    printf("2. Espece\n");
    printf("3. Type d'age\n");
  scan("%d",&choix);
   while( choix<1 || choix>3){
       printf("Mauvaise saisie du choix\n");
       printf("Veuillez ressaisir votre choix.\n");
        scan("%d",&choix);
    }

        switch (choix) {
            case 1:

                printf("Entrez le nom : ");
                scan("%s",&nom);
                corrigeNom(nom);
                tab=rechercheparNom(nom,tab, &nb_animaux);
                afficheAnimaux(tab, nb_animaux);
            break;
            case 2:
                printf("Entrez l'espece (0: DOG, 1: CAT, 2: HAMSTER, 3: OSTRICH) : ");
                scan("%d", &espece);
                while(espece<0 || espece>3){
                	printf("Mauvaise saisie du numero d'espece.\n");
                    printf("Veuillez ressaisir le numero de l'espece de l'animal.\n");
                	scan("%d", &espece);
                }
                tab=rechercheparEspece(espece,tab, &nb_animaux);
                afficheAnimaux(tab, nb_animaux);

                break;
            case 3:
                printf("Entrez le type d'age (1: Jeune <2 ans, 2: Age moyen (entre 2ans et 10 ans), 3: Senior >10 ans) : ");
                scan("%d", &ageType);
                while(ageType != 1 && ageType != 2){
                	printf("mauvaise saisie du choix.\n");
                    printf("Veuillez ressaisir votre choix.\n");
                	scan("%d", &ageType);
                }
                tab=rechercheparAge(ageType, tab, &nb_animaux);
                afficheAnimaux(tab, nb_animaux);
                break;

            default:
                printf("Choix invalide.\n");
        }
    if (nb_animaux==0) {
        printf("Aucun animal ne correspond a votre recherche\n");
    }
    else {
        int continuer=0;
        printf("voulez vous rechercher a partir d'un autre critere\n");
        printf("appuyez sur 1 si oui, 0 sinon\n");
        scan("%d",&continuer);
        while(continuer != 1 && continuer !=0){
                	printf("mauvaise saisie du choix.\n");
                	scan("%d",&continuer);
                }


        if (continuer == 1) {
            rechercherAnimaux(tab, nb_animaux);
        }

    }

}
