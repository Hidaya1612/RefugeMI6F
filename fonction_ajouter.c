void ajouter_Animal(Animal* tab, int taille, int* nb_animaux){
    
    if (tab == NULL || nb_animaux == NULL || taille<=0 || *nb_animaux<0 || *nb_animaux>taille){
        printf("allocation échoué ou taille/nombre animaux incohérente\n");
        exit(1);
    }
    
    if (*nb_animaux==50){
        printf ("Le refuge ne prend plus d'animaux.\n");
    }
    else{
        char temporaire[100];
        int choix_descriptif;
        int tmp=-1;
        tab[*nb_animaux].identification_number=tab[*nb_animaux-1].identification_number+1;
        
        // Saisie des informations de l'animal
        
        printf("Veuillez saisir le nom de l'animal : \n");
        if(scanf("%s",temporaire)!=1){
            printf("Erreur dans la saisie du nom!n");
            exit(1);
        }
        tab[*nb_animaux].name=NULL;
        tab[*nb_animaux].name=malloc(strlen(temporaire)*sizeof(char)+1);
        if(tab[*nb_animaux].name==NULL){
            printf("Allocation réalisée pour le prénom de l'animal échouée\n");
            exit(1);
        }
        tab[*nb_animaux].name=temporaire;
        corrigeNom(tab[*nb_animaux]);
        //printf("%s\n",tab[*nb_animaux].name);
        
        printf("Veuillez saisir l'espece de l'animal :\n 0 pour chien\n 1 pour chat\n 2 pour hamster\n 3 pour autruche\n");
        if (scanf("%d",&tmp)!= 1 || tmp < 0 || tmp > 3) {
            printf("Erreur de la saisie de l'espece! \n");
            exit(1);
        }
        tab[*nb_animaux].species=tmp;
        //printf("%d\n",tab[*nb_animaux].species);
        
        printf("Veuillez saisir le poids de l'animal: \n");
        if (scanf("%f", &tab[*nb_animaux].weight)!=1 || tab[*nb_animaux].weight < 0 || tab[*nb_animaux].weight > 150){
            printf("Erreur dans la saisie du poids ! \n");
            exit(1);
        }
        //printf("%f",tab[*nb_animaux].weight);
    
        printf("Veuillez saisir l'année de naissance de l'animal: \n");
        if (scanf("%d", &tab[*nb_animaux].year_of_birth)!= 1 || tab[*nb_animaux].year_of_birth<1980 || tab[*nb_animaux].year_of_birth>2025) {
            printf("Erreur dans la saisie de l'année de naissance de l'animal!\n");
            exit(1);
        }
        //printf("%d",tab[*nb_animaux].year_of_birth);
        
        printf("Voulez-vous ajouter une description sur l'animal:\n tapez 1 pour oui sinon tapez 2\n");
        if (scanf("%d",&choix_descriptif)!=1 || choix_descriptif<1 || choix_descriptif>2){
            printf("Mauvaise saisie par rapport au choix de vouloir ajouter un descriptif à l'animal!\n");
            exit(1);
        }
        tab[*nb_animaux].description=NULL;
        if (choix_descriptif==1){
            printf("Veuillez saisir une description sur l'animal :\n ");
            if(scanf("%[^\n]s",temporaire)!=1 ){
                printf("Erreur dans la saisie de la description!\n");
                exit(1);
            }
            tab[*nb_animaux].description=malloc(strlen(temporaire)*sizeof(char)+1);
            if(tab[*nb_animaux].description==NULL){
                printf("Allocation réalisée pour le prénom de l'animal échouée\n");
                exit(1);
            }
            tab[*nb_animaux].description=temporaire;
            //printf("%s",tab[*nb_animaux].description);
        }
        else{
            tab[*nb_animaux].description=malloc(1);
            tab[*nb_animaux].description[0]='\0';
        }
        
        FILE* fichier=NULL;
        fichier=fopen("liste_animaux.txt","a+");
        if (fichier==NULL ){
            printf("Ouverture du fichier impossible\n");
            exit(1);
        }
        
        fprintf(fichier,"%d %s %d %d %f",tab[*nb_animaux].identification_number,tab[*nb_animaux].name,tab[*nb_animaux].species,tab[*nb_animaux].year_of_birth,tab[*nb_animaux].weight);
        if (strlen(tab[*nb_animaux].description)!=0){
            fprintf(fichier," %s;\n",tab[*nb_animaux].description);
        }
        else{
            fprintf(fichier,";\n");
        }
        rewind(fichier);
        fclose(fichier);
        (*nb_animaux)++;
        
        
    }
}
