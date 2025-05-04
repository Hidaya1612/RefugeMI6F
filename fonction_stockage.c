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
            
        if(fscanf(fichier,"%d ",&tab[i].identification_number)!=1 || tab[i].identification_number<0){
            printf("Mauvaise valeur de numero identification dans le fichier\n");
            exit(1);
        }
        //printf("%d ",tab[i].identification_number);
        
        while(fgetc(fichier)!=' '){
            compteur++;
        }        
        tab[i].name=NULL;
        tab[i].name=malloc(compteur*sizeof(char)+1);
        if(tab[i].name==NULL){
            printf("Allocation échouée\n");
            exit(1);
        }
        fseek(fichier,-(compteur+1),SEEK_CUR);
        compteur=0;
        
        if(fscanf(fichier,"%s %d %d %f ",tab[i].name,&tmp,&tab[i].year_of_birth,&tab[i].weight)!=4 || tmp<0 || tmp>3 || tab[i].year_of_birth<1980 || tab[i].year_of_birth>2025 || tab[i].weight<0 || tab[i].weight>150){
            printf("Mauvaise valeur sur une info animal dans le fichier");
            exit(1);
        }
        tab[i].species=tmp;
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
        //printf("%s\n",tab[i].description);
        compteur=0;
        
        fseek(fichier,1,SEEK_CUR);
        nb_animaux++;
        i++;
        
    }
    
    for (int i=nb_animaux;i<taille;i++){
        tab[i].identification_number=0;
        //printf("%d",tab[i].identification_number);
    }
        
    rewind(fichier);
    fclose(fichier);
    return nb_animaux;
}
    
