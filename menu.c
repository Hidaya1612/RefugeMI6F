void afficherMenu(){
    int choix;

        printf("\n*******MENU PRINCIPAL*******\n");
        printf("1. Rechercher un animal\n");
        printf("2. Ajouter un animal qui vous a été confié\n");
        printf("3. Adopter un animal\n");
        printf("4. Inventaire du refuge (par âge)\n");
        printf("5. Gestion du nettoyage hebdomadaire\n");
        printf("6. Quitter\n");

        printf("Votre choix : ");
        if(scanf("%d", &choix)!=1 || choix < 0 || choix > 6){
            printf("Erreur dans votre choix!\n);
        }
        while(scanf("%d", &choix)!=1 || choix < 0 || choix > 6){
            printf("Ressaisir votre choix:\n");    
        }

        switch (choix) {
            case 1:
                ajouterAnimal();
            break;
            case 2:
                rechercherAnimaux(tab, nb_animaux);
            break;
            case 3:
                 adoption_animal();
            break;
            case 4: {
                inv_age_asc(tab, nb_animaux);
            break;
            }
            case 5:
                day_clean(refuge, nombre_animaux);
            break;
            case 6:
                printf("Au revoir !\n");
            break;

}
