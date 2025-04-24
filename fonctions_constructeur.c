#include "refuge.h"

Date constructeur(){
	Date d;
	int test=0;
	d.day=0;
	d.month=0;
	d.year=0;
	printf("saisir le jour");
	do{
		test=scanf("%d",&d.day);
		while(getchar()!='\n'){};
	}while(test<=0 || d.day<1 || d.day>31 );
	test=0;
	printf("saisir le mois");
	do{
		test=scanf("%d",&d.month);
		while(getchar()!='\n'){};
	}while(test<=0 || d.month<1 || d.month>12 );
	test=0;
	printf("saisir une année");
	do{
		test=scanf("%d",&d.day);
		while(getchar()!='\n'){};
	}while(test<=0 || d.year==0 );
	return d;
	
}

Animal constructeur(){
	Animal a;
	FILE* f1=NULL;
	f1=fopen("listeNum.txt", "a+");
	if (f1 == NULL){
		printf("Ouverture du fichier impossible\n");
		exit(1);
	}

	FILE* f2=NULL;
	f2=fopen(a.identification_number, "w");
	if (f2 == NULL){
		printf("Ouverture du fichier impossible\n");
		exit(1);
	}
	
}

void afficherMenu(){
	
}




