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
