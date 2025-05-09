#include "refuge.h"

//Stockage des données animaux dans un tableau et compte le nb d'animaux
int stockage_animaux(Animal* tab, int taille){

    FILE* fichier=NULL;
    fichier=fopen("Animaux/liste_animaux.txt","r+");
    if (fichier==NULL ){
        printf("Ouverture du fichier impossible\n");
        exit(1);
    }

    if (tab==NULL || taille<0){
        printf("Allocation du tableau échouée ou erreur sur la taille\n");
        exit(1);
    }


    int caractereActuel = 0;
    int nb_animaux=0;
    int compteur=0;
    int tmp=-1;
    int i=0;

    while (caractereActuel != EOF){

        fseek(fichier,2,SEEK_CUR);
        caractereActuel=fgetc(fichier);
        fseek(fichier,-3,SEEK_CUR);
        if(caractereActuel==EOF){
            break;
        }

        if(fscanf(fichier,"%d ",&tab[i].num_identification)!=1 || tab[i].num_identification<0){
            printf("Mauvaise valeur de numero identification dans le fichier\n");
            exit(1);
        }
        //printf("%d ",tab[i].identification_number);

        while(fgetc(fichier)!=' '){
            compteur++;
        }
        tab[i].nom=NULL;
        tab[i].nom=malloc(compteur*sizeof(char)+1);
        if(tab[i].nom==NULL){
            printf("Allocation échouée\n");
            exit(1);
        }
        fseek(fichier,-(compteur+1),SEEK_CUR);
        compteur=0;

        if(fscanf(fichier,"%s %d %d %f ",tab[i].nom,&tmp,&tab[i].annee_de_naissance,&tab[i].poids)!=4 || tmp<0 || tmp>3 || tab[i].annee_de_naissance<1980 || tab[i].annee_de_naissance>2025 || tab[i].poids<0 || tab[i].poids>150){
            printf("Mauvaise valeur sur une info animal dans le fichier");
            exit(1);
        }
        tab[i].espece=tmp;
        //printf("%s %d %d %f ",tab[i].name,tmp,tab[i].year_of_birth,tab[i].weight);

        while(fgetc(fichier)!=';'){
            compteur++;
        }
        tab[i].description=NULL;
        tab[i].description=malloc(compteur*sizeof(char)+1);
        if(tab[i].description==NULL){
            printf("Allocation échouée\n");
            exit(1);
        }
        fseek(fichier,-(compteur+1),SEEK_CUR);
        fgets(tab[i].description,compteur+1,fichier);
        compteur=0;

        fseek(fichier,1,SEEK_CUR);
        nb_animaux++;
        i++;

    }

    for (int i=nb_animaux;i<taille;i++){
        tab[i].num_identification=0;
    }

    rewind(fichier);
    fclose(fichier);
    return nb_animaux;
}
