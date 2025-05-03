#include "refuge.h"

int main(){
  
  Animal* tab_animaux=NULL;
  int nb_animaux;
  
  tab_animaux=malloc(TAILLE*sizeof(Animal));
  if (tab_animaux==NULL){
    printf("Allocation échouée\n");
    exit(1);
  }
  
  nb_animaux=stockage_animaux(tab_animaux, TAILLE);

  
  afficherMenu();
  return 0;
}
