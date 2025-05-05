#include "refuge.h"

void adoption_animal(Animal* tab, int taille, int* pnb_animaux){
    
    int id=-1;
    int nb_animaux=*pnb_animaux;
    
    if (tab == NULL || pnb_animaux == NULL ||  taille<=0 || nb_animaux<0 || nb_animaux>taille){
        printf("allocation échoué ou taille/nombre animaux incohérente\n");
        exit(1);
    }
    
    if (nb_animaux==0){
        printf("Il n'est plus possible d'adopter un animal dans ce refuge.\n");
    }
    else{
        printf("Saisir le numéro d'identification de l'animal que vous voulez adopter:\n");
        if(scanf("%d",&id)!=1 || id<0){
            printf("Mauvaise saisie du numéro d'identification!\n");
            exit(1);
        }
        int test=0;
        for (int i=0;i<nb_animaux;i++){
            if(tab[i].identification_number==id){
                tab[i].identification_number=0;
                test++;
            }
        }
        if (test==0){
            printf("Aucun animal dans ce refuge porte ce numéro d'identification.\n");
        }
        else{
            FILE* fichier=NULL;
            fichier=fopen("liste_animaux.txt","w+");
            if (fichier==NULL ){
                printf("Ouverture du fichier impossible\n");
                exit(1);
            }
            for (int i=0;i<nb_animaux;i++){
                if (tab[i].identification_number!=0){
                    fprintf(fichier,"%d %s %d %d %f",tab[i].identification_number,tab[i].name,tab[i].species,tab[i].year_of_birth,tab[i].weight);
                    if (strlen(tab[i].description)!=0){
                        fprintf(fichier," %s;\n",tab[i].description);
                    }
                    else{
                        fprintf(fichier,";\n");
                    }
                }
            }
            rewind(fichier);
            fclose(fichier);
            *pnb_animaux=stockage_animaux(tab,taille);
        }
    }
    afficherMenu();
}
