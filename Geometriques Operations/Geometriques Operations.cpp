/*
    Author : MESRAR Hamza - @ez7m.z - 🦂
    💬 : mesrarhamza48@gmail.com
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <windows.h>
#include "menu.h"   // a header file contains colors and menu function
#define Max_Pts 100

//____________ Function prototypes and data structures declaration ____________

struct point {char Nom ; float x ; float y ;} ;
typedef struct point spt ;

struct vecteur {float x ; float y ;} ;
typedef struct vecteur svect ;		
														
struct Distance {char Nom ; float dis ;} T1,tab;
typedef struct Distance sdis ;
								

spt O ={'O',0,0}; // initialize O the origin point



spt saisie(void);
void afficher(spt P);
float distance(spt p1, spt p2);
void Deplacer(spt* p, float dx, float dy);

svect ss(void);
void aff(svect v);
float ProdScal(svect v1, svect v2);

int Colineaires (spt p1, spt p2, spt p3);
void AffichEquatCartesienne (spt p1, spt p2);
int triangleRrectangle(spt p1, spt p2, spt p3);
int triangleIsocele(spt p1, spt p2, spt p3);
float SurfaceGEF(spt Z, spt Q, float r);

void tableau_dis(sdis T1[]);
void tri_pts(sdis tab[]);
void sous_prog(void);

//_______________________________ main code ________________________________________________

int main(){
	
	spt ptr,ptr1,ptr2;
	svect e1,e2;
	int choix,freq;
	float dxx,dyy;
	
	menu2();
	scanf("%d",&choix);
	system("cls");
	
	switch(choix){
		case 1:
			printf("Saisir et affichage d'un point : \n");
			ptr = saisie();
			printf("\n");
			afficher(ptr);
			break;
		case 2:
			printf("Saisie et affichage d'un vecteur : \n");
			e1 = ss();
			printf("\n");
			aff(e1);
			break;
		case 3:
			printf("Calculation des Distance entre deux points : \n");
			ptr1 = saisie();
			afficher(ptr1);
			printf("\n\n");
			ptr2 = saisie();
			afficher(ptr2);
			printf("\n\n");
			printf("La distance Entre %c et %c est : %.2f",ptr1.Nom,ptr2.Nom,distance(ptr1,ptr2));
			break;
		case 4:
			printf("Deplacement des point : \n");
			printf("Entrer Les cordonner de point : \n");
			ptr = saisie();
			printf("\n");
			afficher(ptr);
			printf("\n");
			printf("\tentrer la valeur que vous allez deplacez Dans l'axe Ox : ");
			scanf("%f",&dxx);
			printf("\tentrer la valeur que vous allez deplacez Dans l'axe Oy : ");
			scanf("%f",&dyy);
			printf("\n\n\t");
			Deplacer(&ptr,dxx,dyy);
			break;
		case 5:
			printf("Calculation de produit scalaire des vecteur : \n");
			printf("Entrer Les cordonner du 1er Vecteur : \n");
			e1 = ss();
			printf("\n");
			aff(e1);
			printf("\nEntrer Les cordonner du 1eme Vecteur : \n");
			e2 = ss();
			printf("\n");
			aff(e2);
			printf("\n\t");
			printf("Le produit scalair de deux vecteur est : %.2f",ProdScal(e1, e2));
			break;
		case 6:
			printf("Entrer Les cordonner du 1er point : \n");
			ptr = saisie();
			printf("\n");
			afficher(ptr);
			printf("\n");
			printf("Entrer Les cordonner du 2eme point : \n");
			ptr1 = saisie();
			printf("\n");
			afficher(ptr1);
			printf("\n");
			printf("Entrer Les cordonner du 3eme point : \n");
			ptr2 = saisie();
			printf("\n");
			afficher(ptr2);
			printf("\n");
			freq = Colineaires(ptr,ptr1,ptr2);
			if(freq == 1){
				printf("Les Trois points est colineaires!");
			}else if(freq == 0){
				printf("Les Trois points n'est pas colineaires!");
			}
			break;
		case 7:
			printf("Entrer Les cordonner du 1er point : \n");
			ptr1 = saisie();
			printf("\n");
			afficher(ptr1);
			printf("\n");
			printf("Entrer Les cordonner du 2eme point : \n");
			ptr2 = saisie();
			printf("\n");
			afficher(ptr2);
			printf("\n");
			AffichEquatCartesienne (ptr1, ptr2);
			break;
		case 8:
			printf("Entrer Les cordonner du 1er point : \n");
			ptr = saisie();
			printf("\n");
			afficher(ptr);
			printf("\n");
			printf("Entrer Les cordonner du 2eme point : \n");
			ptr1 = saisie();
			printf("\n");
			afficher(ptr1);
			printf("\n");
			printf("Entrer Les cordonner du 3eme point : \n");
			ptr2 = saisie();
			printf("\n");
			afficher(ptr2);
			printf("\n");
			freq = triangleRrectangle(ptr,ptr1,ptr2);
			if(freq == 1){
				printf("Le Triangle est Rectangle!");
			}else if(freq == 0){
				printf("Le Triangle n'est pas Rectangle!");
			}
			break;
		case 9:
			printf("Entrer Les cordonner du 1er point : \n");
			ptr = saisie();
			printf("\n");
			afficher(ptr);
			printf("\n");
			printf("Entrer Les cordonner du 2eme point : \n");
			ptr1 = saisie();
			printf("\n");
			afficher(ptr1);
			printf("\n");
			printf("Entrer Les cordonner du 3eme point : \n");
			ptr2 = saisie();
			printf("\n");
			afficher(ptr2);
			printf("\n");
			freq = triangleIsocele(ptr,ptr1,ptr2);
			if(freq == 1){
				printf("Le Triangle est Isocele!");
			}else if(freq == 0){
				printf("Le Triangle n'est pas isocele!");
			}
			break;
		case 10:
			printf("Votre demande sera transfere sur quel'que instant!\n\n");
			delay(1000000000);
			system("cls");
			green();printf("votre demande est maintenant disponible!\n\t\tApuyez any touch pour continue!");
			getch();
			system("cls");
			sous_prog();
			break;
		case 11:
			printf("\n\n\n\t\t\t\tHAMZA MESRAR\tAPI-2\tGRP 5 - 2020 - ez7mz");
			getch();
			break;
		case 0:
			printf("\n\n\t\t__________ ez7mz vous remercie de votre visite! __________\n\n");
			getch();
			break;
		default :
			red();printf("\n\n\t\tInvalid choix!\t\ttry again...");
			delay(100000000);
			system("cls");
			cyan();
			main();
	}
	
	return 0;
}

//_______________________________________________________________________________________________________


//__________________________________________________ Program functions _____________________________________

//____________ Create a point ____________

spt saisie(void){
	spt P;
	
	printf("Donnez le nom de point : ");
	scanf("%1s",&P.Nom);
	//scanf ("%*[^\n]");
	printf("Donnez X : ");
	scanf("%f",&P.x);
	printf("Donnez Y : ");
	scanf("%f",&P.y);
	printf("\n");
	
	return P;
}

//____________ Display a point ___________________

void afficher(spt P){
	printf("Le point %c = ( %.2f , %.2f )\n",P.Nom,P.x,P.y);
}

//_________________ Calculate the distance between two points __________________

float distance(spt p1, spt p2){
	return (sqrt(pow((p1.x-p2.x),2)+pow((p1.y-p2.y),2)));
}

//_________________ Move a point from a place to another  __________________

void Deplacer(spt* p, float dx, float dy){
	p->x+=dx;
	p->y+=dy;
	printf("Les nouveau cordonners de %c sont : ( %.2f , %.2f )",p->Nom,p->x,p->y);
}

//____________ Create a vector ____________

svect ss(void){
	svect V;
	
	printf("Donnez X : ");
	scanf("%f",&V.x);
	printf("Donnez Y : ");
	scanf("%f",&V.y);
	
	return V;
}

//____________ Display a vector ___________________

void aff(svect v){
	printf("Les cordonner de vecteur sont : ( %.2f , %.2f )\n",v.x,v.y); //Juste un printf avec la variable de structure svect
}

//___________ Scalar product of two vector __________________

float ProdScal(svect v1, svect v2){
	
	return ((v1.x*v2.x) + (v1.y*v2.y));
}
//____________ is 3 point Colinear ________________

int Colineaires (spt p1, spt p2, spt p3){
	
	svect u1,u2;
	int bol=0;
	
	u1.x = p2.x-p1.x;
	u1.y = p2.y-p1.y;
	u2.x = p3.x-p1.x;
	u2.y = p3.y-p1.y;
	
	if((u1.x*u2.y) == (u1.y*u2.x))			
		bol = 1;
	
	return bol;
	
}

//____________ display the Cartesian equation of a straight line ___________________

void AffichEquatCartesienne (spt p1, spt p2){
	float a,b;
	a = (p2.y-p1.y)/(p2.x-p1.x);
	b = p1.y - (a*p1.x);
	
	printf("L'equation cartesienne de la droite (%c%c) est : Y = %.2f*X + %.2f",p1.Nom,p2.Nom,a,b);
}

//____________ is a rectangle traingle ________________

int triangleRrectangle(spt p1, spt p2, spt p3){
	int bol=0;
	float a,b,c;
	a = distance(p1,p2);
	b = distance(p2,p3);
	c = distance(p1,p3);
	if( pow(b,2) <= (pow(a,2)+pow(c,2)+0.1) && pow(b,2) >= (pow(a,2)+pow(c,2)-0.1) ){
		bol=1;
	}else if(pow(c,2) == (pow(a,2)+pow(b,2))){
		bol=1;
	}else if(pow(a,2) == (pow(b,2)+pow(c,2))){
		bol=1;
	}
	
	return bol;	
}

//____________ is a isosceles traingle ________________

int triangleIsocele(spt p1, spt p2, spt p3){
	int bol=0;
	float P2P1,P2P3;
	P2P1 = distance(p2,p1);
	P2P3 = distance(p2,p3);
	
	if(P2P1 == P2P3)
		bol=1;
	
	return bol;
}


//___________ Calculate the surface of GEF triangle  __________________

float SurfaceGEF (spt Z, spt Q, float r){
	float S;
	spt F;
	F.Nom = 'F';
	F.x = Q.x;
	F.y = Z.y;
	
	S = (distance(F,Q)*(2*sqrt(2)*r)) / 2;
	
	return S;
}
//_______________ function to store distances between points and the origin on an array _______________________________

void tableau_dis(sdis T1[]){
	
	spt T[Max_Pts+1];
	int i=0,j;
	
	
	for(i=0;i<Max_Pts;i++){
		
		printf("Entrer les cordonner de point %d : \n",i+1);
		printf("Entrer Le nom : ");
		scanf("%1s",&T[i].Nom);
		printf("Entrer X : ");
		scanf("%f",&T[i].x);
		printf("Entrer Y : ");
		scanf("%f",&T[i].y);
	}
	
	i=0;
	for(i=0;i<Max_Pts;i++){
		T1[i].dis = distance(T[i],O);
		T1[i].Nom = T[i].Nom;
	}
	i=0;
	printf("L'order initiale du points : \n\n");
	printf("Nom     distance\n");
	printf("==========================\n");						
	for(i=0;i<Max_Pts;i++){											
		printf("%c\t%.2f\n",T1[i].Nom,T1[i].dis);
	}
}

//___________ function that sorts this array according to the distance of the points from the origin O __________________________________________

void tri_pts(sdis tab[]){
	
	int i, j, index;
	float tmp;
	char tmp1;
	
	for (i=0; i < (Max_Pts-1); i++){
		index = i;								
		for (j=i + 1; j < Max_Pts; j++){		 
			if (tab[index].dis > tab[j].dis)			
			index = j;
		if (index != i){
			tmp = tab[i].dis;
			tmp1 = tab[i].Nom;
			tab[i].dis = tab[index].dis;
			tab[i].Nom = tab[index].Nom;
			tab[index].dis = tmp;
			tab[index].Nom = tmp1;
		}
	}
	}
	printf("\n\n");
	printf("L'order du points par distance au l'origine O du repere :\n");
	for (i=0; i < Max_Pts; i++)
		printf("%c\t%.2f\n", tab[i].Nom,tab[i].dis);
	
}

//__________________ subprogram main function ___________________________

void sous_prog(void){
	
	sdis M[Max_Pts+1];
	spt Z1,Q1;
	float rayon,surface;
	int chx;
	
	again :
	menu3();
	scanf("%d",&chx);
	switch(chx){
		case 1:
			system("cls");
			printf("Calculation Du surface de Triangle GEF : \n\t");
			printf("Entrer Les cordonner du point Z : \n");
			Z1 = saisie();
			printf("\n");
			printf("Entrer Les cordonner du point Q : \n");
			Q1 = saisie();
			printf("\n");
			printf("Entrer Le Rayon R : ");
			scanf("%f",&rayon);
			printf("\n");
			surface = SurfaceGEF (Z1, Q1, rayon);
			printf("\n\t\tLa surface du triangle GEF est : S = %.2f",surface);
			break;
		case 2:
			system("cls");
			tableau_dis(M);
			tri_pts(M);
			break;
		case 3:
			system("cls");
			printf("\t\t--------------________________-------------\n\n");
			break;
		case 0:
			system("cls");
			printf("\n\n\t\t__________ MESRAR HAMZA vous remercie de votre visite! __________\n\n");
			getch();
			break;
		default :
			red();printf("\n\n\t\tInvalid choix!\t\ttry again...");
			delay(100000000);
			system("cls");
			cyan();
			goto again;
	}
	
	
}	
