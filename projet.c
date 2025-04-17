#include <stdio.h>

// Enumeration species
typedef enum {
  DOG, CAT, HAMSTER, OSTRICH
} Species;

// Structure date
typedef struct {
  int day;
  int month;
  int year;
} Date;

// Structure animal
typedef struct {
  int identification_number;
  char* name;
  Species species;
  Date date_of_birth;
  int weight;
  char* description;
} Animal;


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

	FILE* f2=NULL;
	f2=fopen(a.identification_number, "w");
}






