#include "refuge.h"

//weekly time to clean shelters
void day_clean(Animal* tab, int taille, int nb_animaux){
  // Locals
  int clean_time=0;
  int h=-1;
  int m=-1;

  //Check parameters
  if (tab == NULL ||  taille<=0 || nb_animaux<0 || nb_animaux>taille){
    printf("allocation échoué ou taille/nombre animaux incohérente\n");
    exit(1);
  }

  //Process
  for (int i=0; i<nb_animaux; i++){
    if (tab[i].species==1 || tab[i].species==2){
      clean_time+=90;
    }
    else if (tab[i].species==3){
      clean_time+=185;
    }
    else if (tab[i].species==0){
      clean_time+=55;
    }
  }
  clean_time+=(taille-nb_animaux)*14;
  
  //Check clean_time value
  if (clean_time%60==0){
    h=clean_time/60;
    printf("Il faudra prévoir %dh de charge de travail cette semaine pour nettoyer les abris de chaque animal.\n",h);
  }
  else if (clean_time>60){
    h=clean_time/60;
    m=clean_time%60;
    printf("Il faudra prévoir %dh%d de charge de tavail cette semaine pour nettoyer les abris de chaque animal.\n",h,m);
  }
  else{
    m=clean_time;
    printf("Il faudra prévoir %dmin de charge de travail cette semaine pour nettoyer les abris de chaque animal.\n",m);
  }
}

void extremums(Animal* tab, int nb_animaux, int* pMin, int* pMax) {
    if (tab == NULL || nb_animaux <= 0 || pMin == NULL || pMax == NULL) {
        exit (2);
    }
    int minAge = 2025 - tab[0].date_of_birth.year;
    int maxAge = minAge;

    if (tab[0].date_of_birth.month > 1 || (tab[0].date_of_birth.month == 1 && tab[0].date_of_birth.day > 1)) {
        minAge--;
        maxAge--;
       }

    for(int i=0; i<nb_animaux; i++){
        int age = 2025 - tab[i].date_of_birth.year;
        if (tab[i].date_of_birth.month > 1 || (tab[i].date_of_birth.month == 1 && tab[i].date_of_birth.day > 1)) {
            age--;
        }
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


void inv_age_asc(Animal* tab, int nb_animaux, int* pMin, int* pMax) {
    if (tab == NULL || nb_animaux <= 0 || pMin == NULL || pMax == NULL) {
        printf("Erreur : paramètres invalides.\n");
        exit(2);
    }
    int range = (*pMax - *pMin) / 4;
    int quartile1 = 0, quartile2 = 0, quartile3 = 0, quartile4 = 0;

    for (int i = 0; i < nb_animaux; i++) {
        int age = 2025 - tab[i].date_of_birth.year;
        if (tab[i].date_of_birth.month > 1 || (tab[i].date_of_birth.month == 1 && tab[i].date_of_birth.day > 1)) {
            age--;
        }

        if (age >= *pMin && age < *pMin + range) {
            quartile1++;
        }
        else if (age >= *pMin + range && age < *pMin + 2 * range) {
            quartile2++;
        }
        else if (age >= *pMin + 2 * range && age < *pMin + 3 * range) {
            quartile3++;
        }
        else if (age >= *pMin + 3 * range) {
            quartile4++;
        }
    }

    printf("Nombre total d'animaux : %d\n", nb_animaux);
    printf("Quartile 1 (%d - %d ans) : %d animaux\n", *pMin, *pMin + range, quartile1);
    printf("Quartile 2 (%d - %d ans) : %d animaux\n", *pMin + range, *pMin + 2 * range, quartile2);
    printf("Quartile 3 (%d - %d ans) : %d animaux\n", *pMin + 2 * range, *pMin + 3 * range, quartile3);
    printf("Quartile 4 (%d+ ans) : %d animaux\n", *pMin + 3 * range, quartile4);
}

