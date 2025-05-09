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
    
    //Impossible d'adopter
    if (nb_animaux==0){
        printf("Il n'est plus possible d'adopter un animal dans ce refuge.\n");
        afficherMenu(tab, TAILLE, *pnb_animaux);
    }

    // Possibilité d'adoption
    else{ 
        
        // Saisie du numéro d'identification
        printf("Saisir le numero d'identification de l'animal que vous voulez adopter:\n");
        scan("%d",&id);
        while(id<0){
            printf("Mauvaise saisie du numéro d'identification!\n");
            scan("%d",&id);
        }

        //recherche de l'animal avec cet id
        int test=0;
        for (int i=0;i<nb_animaux;i++){
            if(tab[i].num_identification==id){
                tab[i].num_identification=0; // son id prend la valeur 0
                free(tab[i].nom);
                 if (strlen(tab[i].description)!=0){
                     free(tab[i].description);
                 }
                test++;
            }
        }

        //vérification de la valeur de test
        
        // l'animal n'existe pas
        if (test==0){
            printf("Aucun animal dans ce refuge porte ce numéro d'identification.\n");
        }
        //l'animal existe 
        else{

            //Gestion des fichiers
            FILE* fichier=NULL;
            fichier=fopen("Animaux/liste_animaux.txt","w+");// ouvre le fichier et efface tout le contenu
            if (fichier==NULL ){
                printf("Ouverture du fichier impossible\n");
                exit(1);
            }

            //écrit les infos des animaux sauf ceux de l'animal à supprimer (id à 0)
            for (int i=0;i<nb_animaux;i++){
                if (tab[i].num_identification!=0){
                    fprintf(fichier,"%d %s %d %d %f",tab[i].num_identification,tab[i].nom,tab[i].espece,tab[i].annee_de_naissance,tab[i].poids);
                    //vérifie si la description existe
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

            //Mise à jour du nb d'animaux
            *pnb_animaux=stockage_animaux(tab,taille); 
            printf("L'animal avec le numero d'identification %d a bien ete adopte.\n", id);

            //Appel du menu
            afficherMenu(tab, TAILLE, *pnb_animaux);
        }
    }
    
}
