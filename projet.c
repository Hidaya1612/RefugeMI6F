#include "refuge.h"

int main(){
  
  Animal* tab=NULL;
  FILE* f1=NULL;
  FILE* f2=NULL;

  tab=malloc(TAILLE*sizeof(Animal));
  if (tab==NULL){
    printf("Allocation échouée\n");
    exit(1);
  }

  f1=fopen("liste_num_identification.txt","r+");
  f2=fopen("liste_animaux.txt","r+");
  if (f1==NULL || f2==NULL){
    printf("Ouverture des fichiers impossible\n");
    exit(1);
  }

  
  afficherMenu();
  return 0;
}
