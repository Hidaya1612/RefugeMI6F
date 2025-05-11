#include "refuge.h"

//Stockage des données animaux dans un tableau et compte le nb d'animaux
int stockage_animaux(Animal* tab, int taille){

    //Gestion du fichier
    FILE* fichier=NULL;
    fichier=fopen("Animaux/liste_animaux.txt","r+");
    if (fichier==NULL ){
        printf("Ouverture du fichier impossible\n");
        exit(1);
    }

    // vérification des paramètres
    if (tab==NULL || taille<0){
        printf("Allocation du tableau échouée ou erreur sur la taille\n");
        exit(1);
    }

    // variables locales
    int caractereActuel = 0;
    int nb_animaux=0;
    int compteur=0;
    int tmp=-1;
    int i=0;
    char test;

    while (caractereActuel != EOF){

        fseek(fichier,2,SEEK_CUR);
        caractereActuel=fgetc(fichier);
        fseek(fichier,-3,SEEK_CUR);
        // Si on arrive à la fin du fichier on arrete la boucle
        if(caractereActuel==EOF){
            break;
        }

        //récupération des données du fichier
        //son id
        if(fscanf(fichier,"%d ",&tab[i].num_identification)!=1 || tab[i].num_identification<0){
            printf("Mauvaise valeur de numero identification dans le fichier\n");
            exit(1);
        }

        // alloue dynamiquement l'espace nécessaire pour stocker son nom
        while(fgetc(fichier)!=' '){ // compte le nb de lettres
            compteur++;
        }
        tab[i].nom=NULL;
        tab[i].nom=malloc((compteur+1)*sizeof(char));
        if(tab[i].nom==NULL){
            printf("Allocation échouée\n");
            exit(1);
        }
        fseek(fichier,-(compteur+1),SEEK_CUR); //curseur replacé devant la première lettre du nom
        compteur=0;

        // Son nom, son espèce, son année de naissance, son poids
        if(fscanf(fichier,"%s %d %d %f ",tab[i].nom,&tmp,&tab[i].annee_de_naissance,&tab[i].poids)!=4 || tmp<0 || tmp>3 || tab[i].annee_de_naissance<1980 || tab[i].annee_de_naissance>2025 || tab[i].poids<0 || tab[i].poids>150){
            printf("Mauvaise valeur sur une info animal dans le fichier");
            exit(1);
        }
        // Variable intermédiaire pour stocker l'espèce
        tab[i].espece=tmp;
        fseek(fichier,-1,SEEK_CUR); // curseur replacé devant le premier caractère de la description
        // Alloue dynamiquement l'espace nécessaire pour stocker sa description
        test=fgetc(fichier);
        while(test !='\n' && test != EOF){ // compte le nb de lettres
            test=fgetc(fichier);// compte le nb de caractères dans la description
            if(test=='\n' || test == EOF){
                break;
            }
            compteur++;
        }
        tab[i].description=NULL;
        tab[i].description=malloc((compteur+1)*sizeof(char));
        if(tab[i].description==NULL){
            printf("Allocation échouée\n");
            exit(1);
        }
        fseek(fichier,-(compteur+1),SEEK_CUR);// Curseur replacé devant le premier caractère de la description

        // sa description
        fgets(tab[i].description,compteur+1,fichier);
        printf("%s\n", tab[i].description);
        compteur=0;

        fseek(fichier,1,SEEK_CUR);
        nb_animaux++;// Incrémentation du nb d'animaux
        i++;

    }

    // id de tous les autres animaux mis à 0
    for (int i=nb_animaux;i<taille;i++){
        tab[i].num_identification=0;
    }

    rewind(fichier);
    fclose(fichier);
    return nb_animaux;
}
