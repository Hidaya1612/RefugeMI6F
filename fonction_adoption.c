#include "refuge.h"

void adoption_animal(Animal* tab, int taille, int* pnb_animaux){

    //variables locales
    int id=-1;
    int nb_animaux=*pnb_animaux;

    //vérification des paramètres
    if (tab == NULL || pnb_animaux == NULL ||  taille<=0 || nb_animaux<0 || nb_animaux>taille){
        printf("allocation echouee ou taille/nombre animaux incoherente\n");
        exit(1);
    }
    
    //vérification du nb d'animaux
    if (nb_animaux==0){
        printf("Il n'est plus possible d'adopter un animal dans ce refuge.\n");
    }
    else{ // Possibilité d'adoption
        printf("Saisir le numero d'identification de l'animal que vous voulez adopter:\n");
        scan("%d",&id);
        while(id<0){
            printf("Mauvaise saisie du numéro d'identification!\n");
            scan("%d",&id);
        }
        int test=0;
        //recherche de l'animal avec cet id
        for (int i=0;i<nb_animaux;i++){
            if(tab[i].num_identification==id){
                tab[i].num_identification=0;
                free(tab[i].nom);
                 if (strlen(tab[i].description)!=0){
                     free(tab[i].description);
                 }
                test++;
            }
        }
        if (test==0){
            printf("Aucun animal dans ce refuge porte ce numéro d'identification.\n");
        }
        else{
            FILE* fichier=NULL;
            fichier=fopen("liste_animaux.txt","w+");// ouvre le fichier et efface tout le contenu
            if (fichier==NULL ){
                printf("Ouverture du fichier impossible\n");
                exit(1);
            }
            for (int i=0;i<nb_animaux;i++){
                //écrit les infos de l'animal si il existe
                if (tab[i].num_identification!=0){
                    fprintf(fichier,"%d %s %d %d %f",tab[i].num_identification,tab[i].nom,tab[i].espece,tab[i].annee_de_naissance,tab[i].poids);
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
            *pnb_animaux=stockage_animaux(tab,taille); //Mise à jour du nb d'animaux
            printf("L'animal avec le numero d'identification %d a bien ete adopte.\n", id);
        }
    }
    afficherMenu(tab, TAILLE, *pnb_animaux);
}
