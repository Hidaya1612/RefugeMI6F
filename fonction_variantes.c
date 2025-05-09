#include "refuge.h"

//temps hebdomadaire pour nettoyer les abris
void nettoyage(Animal* tab, int taille,  int nb_animaux){
  // Locals
  int temps_nettoyage=0;
  int h=-1;
  int m=-1;

  //Vérification des paramètres
  if (tab == NULL ||  taille<=0 || nb_animaux<0 || nb_animaux>TAILLE){
    printf("allocation échoué ou taille/nombre animaux incohérente\n");
    exit(1);
  }

  //Process
  for (int i=0; i<nb_animaux; i++){ // parcours du tableau
    if (tab[i].num_identification!=0){
      switch(tab[i].espece){
        case 0: // si chien
          temps_nettoyage+=55;
          break;
        case 3: // si autruche
          temps_nettoyage+=185;
          break;
        default: // si chat ou hamster
          temps_nettoyage+=90;
      }
    }
  }
  temps_nettoyage+=(taille-nb_animaux)*14; // si cage vide

  //Vérifier la valeur du temps de nettoyage pour l'afficher

  // que des heures
  if (temps_nettoyage%60==0){
    h=temps_nettoyage/60;
    printf("Il faudra prévoir %dh de charge de travail cette semaine pour nettoyer les abris de chaque animal.\n",h);
  }

  // heures et minutes
  else if (temps_nettoyage>60){
    h=temps_nettoyage/60;
    m=temps_nettoyage%60;
    printf("Il faudra prévoir %dh%02d de charge de tavail cette semaine pour nettoyer les abris de chaque animal.\n",h,m);
  }

  // que des minutes
  else{
    m=temps_nettoyage;
    printf("Il faudra prévoir %dmin de charge de travail cette semaine pour nettoyer les abris de chaque animal.\n",m);
  }

  //appel du menu
  afficherMenu(tab, TAILLE, nb_animaux);
}

void extremums(Animal* tab, int nb_animaux, int* pMin, int* pMax) {
    if (tab == NULL || nb_animaux <= 0 || pMin == NULL || pMax == NULL) {
        exit (35);
    }
    int minAge = 2025 - tab[0].annee_de_naissance;
    int maxAge = minAge;



    for(int i=0; i<nb_animaux; i++){
        int age = 2025 - tab[i].annee_de_naissance;
        if (minAge > age){
            minAge = age;
        }
        if (maxAge < age) {
            maxAge = age;
        }
    }
    *pMin = minAge;
    *pMax = maxAge;
}


void inv_age_asc(Animal* tab, int nb_animaux) {
    //Vérification des paramètres
    if (tab == NULL || nb_animaux <= 0) {
        printf("Erreur.\n");
        exit(2);
    }
  
    //Initialisation des champs
    int pMin=0;
    int pMax=0;
    extremums(tab, nb_animaux, &pMin, &pMax);
    int moyenne = (pMax - pMin) / 4;
    int quartile1 = 0, quartile2 = 0, quartile3 = 0, quartile4 = 0;

    for (int i = 0; i < nb_animaux; i++) {
        int age = 2025 - tab[i].annee_de_naissance;

        if (age >= pMin && age < pMin + moyenne) {
            quartile1++;
        }
        else if (age >= pMin + moyenne && age < pMin + 2 * moyenne) {
            quartile2++;
        }
        else if (age >= pMin + 2 * moyenne && age < pMin + 3 * moyenne) {
            quartile3++;
        }
        else if (age >= pMin + 3 * moyenne && age <= pMax) {
            quartile4++;
        }
    }

    printf("Nombre total d'animaux : %d\n", nb_animaux);
    printf("Quartile 1 (%d - %d ans) : %d animaux\n", pMin, pMin + moyenne, quartile1);
    printf("Quartile 2 (%d - %d ans) : %d animaux\n", pMin + moyenne, pMin + 2 * moyenne, quartile2);
    printf("Quartile 3 (%d - %d ans) : %d animaux\n", pMin + 2 * moyenne, pMin + 3 * moyenne, quartile3);
    printf("Quartile 4 (%d - %d ans) : %d animaux\n", pMin + 3 * moyenne,pMax, quartile4);
    afficherMenu(tab, TAILLE, nb_animaux);
}
