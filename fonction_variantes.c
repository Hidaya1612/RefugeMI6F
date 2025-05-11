#include "refuge.h"

//temps hebdomadaire pour nettoyer les abris
void nettoyage(Animal* tab, int taille,  int nb_animaux){
  // Parametres
  int temps_nettoyage=0;
  int h=-1;
  int m=-1;

  //Vérification des paramètres
  if (tab == NULL ||  taille<=0 || nb_animaux<0 || nb_animaux>TAILLE){
    printf("Allocation echouee ou taille/nombre animaux incohérent(e)\n");
    afficherMenu(tab, TAILLE, nb_animaux);
  }
  
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
    printf("Il faudra prévoir %dh%02d de charge de travail cette semaine pour nettoyer les abris de chaque animal.\n",h,m);
  }

  // que des minutes
  else{
    m=temps_nettoyage;
    printf("Il faudra prévoir %dmin de charge de travail cette semaine pour nettoyer les abris de chaque animal.\n",m);
  }

  //appel du menu
  afficherMenu(tab, TAILLE, nb_animaux);
}

// Procédure pour trouver les âges minimum et maximum des animaux
void extremums(Animal* tab, int nb_animaux, int* pMin, int* pMax) {
    if (tab == NULL || nb_animaux <= 0 || pMin == NULL || pMax == NULL) {
        exit (35);
    }
    // Initialisation des âges minimum et maximum avec le premier animal
    int minAge = 2025 - tab[0].annee_de_naissance;
    int maxAge = minAge;


    // Parcourt le tableau pour trouver les âges minimum et maximum
    for(int i=0; i<nb_animaux; i++){
        int age = 2025 - tab[i].annee_de_naissance; // Calcul de l'âge de l'animal
        if (minAge > age){ // Mise à jour de l'âge minimum si un âge plus petit est trouvé
            minAge = age;
        }
        if (maxAge < age) { // Mise a jour age max
            maxAge = age;
        }
    }
    // Stockage des résultats dans les paramètres de sortie
    *pMin = minAge;
    *pMax = maxAge;
}

// Procédure pour calculer et afficher la répartition des âges des animaux en quartiles
void inv_age_asc(Animal* tab, int nb_animaux) {
    //Vérification des paramètres
    if (tab == NULL || nb_animaux <= 0) {
        printf("Il n'y a pas d'animaux dans le refuge\n");
        afficherMenu(tab, TAILLE, nb_animaux);
    }
    else{
      //Initialisation des paramètres
      int pMin=0;
      int pMax=0;
      extremums(tab, nb_animaux, &pMin, &pMax); // Appel de la fonction pour obtenir les âges max et min
      int moyenne = (pMax - pMin) / 4; // Calcul de l'intervalle pour chaque quartile
      int quartile1 = 0, quartile2 = 0, quartile3 = 0, quartile4 = 0;

      // Parcourt le tableau pour classer les animaux dans les quartiles
      for (int i = 0; i < nb_animaux; i++) {
          int age = 2025 - tab[i].annee_de_naissance;

          // Classification de l'animal dans le quartile correspondant
          if (age >= pMin && age <= pMin + moyenne) {
              quartile1++;
          }
          else if (age > pMin + moyenne && age <= pMin + 2 * moyenne) {
              quartile2++;
          }
          else if (age > pMin + 2 * moyenne && age <= pMin + 3 * moyenne) {
              quartile3++;
          }
          else if (age > pMin + 3 * moyenne && age <= pMax) {
              quartile4++;
          }
      }

      // Affichage des résultats
      printf("Nombre total d'animaux : %d\n", nb_animaux);
      if (quartile1 !=0) {
          printf("Moins de %d ans : %d animaux\n", pMin + moyenne, quartile1);
      }
      if (quartile2 != 0) {
          printf("Entre %d et %d ans : %d animaux\n", pMin + moyenne, pMin + 2 * moyenne, quartile2);
      }
      if (quartile3 != 0) {
          printf("Entre %d et %d ans : %d animaux\n", pMin + 2 * moyenne, pMin + 3 * moyenne, quartile3);
      }
      if (quartile4 != 0) {
          printf("Plus de %d ans : %d animaux\n", pMin + 3 * moyenne, quartile4);
      }
      afficherMenu(tab, TAILLE, nb_animaux);
    }
}

