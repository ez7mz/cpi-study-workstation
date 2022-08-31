/*
    Author : MESRAR Hamza - @ez7m.z - 🦂
    💬 : mesrarhamza48@gmail.com
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include "menu.h"
#define DegreMax 20


//_______ calculate power of a number ________________________
float puis(float n,int m){
	float p=1;
	int i;
	for(i=0;i<m;i++){
		p*=n;
	}
}
//_____________________________________________

//____________ Functions prototype and data structures declaration ____________

typedef struct {
	int degre;
	float coeff[DegreMax+1];
} pol;

void NulPoly(pol* p);
void SaisiePoly(pol *p);
void voirPoly(pol p);
void voirPoly_2(pol p,float x);
void AddPoly(pol p1, pol p2);
void MultPoly(pol p1, pol p2);
int verif(pol p);

//_______________________________ main code ________________________________________________

int main(){
	
	pol A,B;
	int choix;
	float x;
	
	
	menu1();
	scanf("%d",&choix);
	system("cls");
	switch(choix){
		case 1:
			printf("La saisie et l'affichage d'un Polynome : \n");
			printf("Le Polynome sera de type : A0*X^0 + A1*X^1 + ....... + An*X^n .!\n\n");
			SaisiePoly(&A);
			printf("\n");
			voirPoly(A);
			break;
		case 2:
			printf("Calculation des images de X : \n\n");
			SaisiePoly(&A);
			printf("\n");
			voirPoly(A);
			printf("\n\n\t\t");
			printf("entre un nomber X : ");
			scanf("%f",&x);
			voirPoly_2(A,x);
			break;
		case 3:
			printf("L'addition des Polynome : \n\n");
			SaisiePoly(&A);
			printf("\n");
			voirPoly(A);
			printf("\n\n");
			SaisiePoly(&B);
			printf("\n");
			voirPoly(B);
			printf("\n\nLa polynome Somme est : \n\t\t");
			AddPoly(A,B);
			break;
		case 4:
			printf("Le Produit des Polynome : \n\n");
			SaisiePoly(&A);
			printf("\n");
			voirPoly(A);
			printf("\n\n");
			SaisiePoly(&B);
			printf("\n");
			voirPoly(B);
			printf("\n\nLa polynome Produit est : \n\t\t");
			MultPoly(A,B);
			break;
		case 5:
			printf("\n\n\n\t\t\t\tHAMZA MESRAR\tAPI-2\tGRP 5 - 2020 - ez7mz");
			getch();
			break;
		case 0:
			printf("\n\n\t\t__________ MESRAR HAMZA vous remercie de votre visite! __________\n\n");
			getch();
			break;
		default :
			red();printf("\n\n\t\tInvalid choix!\t\ttry again...");
			delay(1000000000);
			system("cls");
			blue();
			main();
	}
	
	return 0;
}

//_______________________________________________________________________________________________________


//__________________________________________________ Program functions _____________________________________

	
//____________ Create a polynomial formula ____________
void SaisiePoly(pol *p){
	
	int i;
	
	printf("entrer le degre de polynome (max 20) : ");
	scanf("%d",&p->degre);
	if(p->degre == -1)
		printf("Le polynome est NUL!");
	for(i=0;i<p->degre+1;i++){
		printf("entrer l'coeff A%d : ",i);
		scanf("%f",&p->coeff[i]);
	}
	
}

//____________ Display a polynomial formula ___________________
void voirPoly(pol p){
	int i;
	printf("P(X) = ");
	for(i=0;i<p.degre+1;i++){
		printf("%.2f * X^%d ",p.coeff[i],i);
		if(i<p.degre)
			printf(" + ");
	}
}

//_________________ P(X) of a certain X __________________
void voirPoly_2(pol p,float x){
	
	int i;
	float s=p.coeff[0];
	
	for(i=1;i<=p.degre;i++){
		s = s + (p.coeff[i] * pow(x,i));
	}
	
	printf("P(%.2f) = %.2f",x,s);
}


//___________ sum of two polynomial formula _____________________
void AddPoly(pol p1, pol p2){
	
	pol p;
	int i;
	
	if(p1.degre > p2.degre){
		p.degre = p1.degre;
		p.coeff[p1.degre] = p1.coeff[p1.degre];
		for(i=0;i<p.degre;i++){
			p.coeff[i] = (p1.coeff[i]+p2.coeff[i]);
		}
	}else if(p1.degre == p2.degre){
		p.degre = p1.degre;
		for(i=0;i<p.degre+1;i++){
			p.coeff[i] = (p1.coeff[i]+p2.coeff[i]);
		}
	}else{
		p.degre = p2.degre;
		p.coeff[p2.degre] = p2.coeff[p2.degre];
		for(i=0;i<p.degre;i++){
			p.coeff[i] = (p1.coeff[i]+p2.coeff[i]);
		}
	}
	voirPoly(p);
}


//______________ Multiplication of two polynomial formula ______________
void MultPoly(pol p1, pol p2){
	pol p;
	int i,j,d=p1.degre+p2.degre;
	float C[d],s;
	for(i=0;i<d+1;i++){
		s=0;
		for(j=0;j<i+1;j++){
			s+=(p1.coeff[j]*p2.coeff[i-j]);
		}
		C[i] = s;
	}
	printf("P(X) = ");
	for(i=0;i<d+1;i++){
		printf("%.2f * X^%d",C[i],i);
		if(i<d)
			printf(" + ");
	}
	
}

//____________ NULL Polynome ______________
void NulPoly(pol* p){
	int i;
	p->degre = -1;
	for(i=0;i<DegreMax+1;i++){
		p->coeff[i] = 0;
	}
}

//___________________ is a polynomial formula NULL ________________
int verif(pol p){
	int i,bol=1;
	for(i=0;i<p.degre+1;i++){
		if(p.coeff[i] != 0){
			bol = 0;
		break;
		}
	}
	return bol;
}
