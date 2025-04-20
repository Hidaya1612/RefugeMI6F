#include "projet.c"

//weekly time to clean shelters
int day_clean(Animal* tab, int size){
  // Local
  clean_time=0;

  //Check parameters
  if (tab == NULL || size<=0){
    printf("allocation échoué ou taille incohérente\n");
    exit(1);
  }

  //Process
  for (int i=0; i<size; i++){
    if (tab[i].species==1 || tab[i].species==2){
      clean_time+=90;
    }
    else if (tab[i]==3){
      clean_time+=185;
    }
    else if (tab[i]==1){
      clean_time+=55;
    }
    else{
      clean_time+=14;
    }
  }
  //end of process
  return clean_time;
}
