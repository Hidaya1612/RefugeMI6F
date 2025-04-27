#include "refuge.h"

int main(){
  
  Animal* tab_animaux=NULL;
  FILE* f1=NULL;
  FILE* f2=NULL;
  int nb_animaux;

  tab_animaux=malloc(TAILLE*sizeof(Animal));
  if (tab_animaux==NULL){
    printf("Allocation échouée\n");
    exit(1);
  }

  f1=fopen("liste_num_identification.txt","r+");
  f2=fopen("liste_animaux.txt","r+");
  if (f1==NULL || f2==NULL){
    printf("Ouverture des fichiers impossible\n");
    exit(1);
  }
  nb_animaux=compter_animaux(f2);
  stockage_animaux(f1, f2, tab_animaux, TAILLE, nb_animaux);

  
  afficherMenu();
  return 0;
}
