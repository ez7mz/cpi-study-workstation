/*
    Author : MESRAR Hamza - @ez7m.z - 🦂
    💬 : mesrarhamza48@gmail.com
*/

#include <stdio.h>
#include <windows.h>

void delay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}

//_____________________COLORS ___________________________________


void red(void){
	system("color 0");
	printf("\033[0;31m");
}

void black(void){
	system("color 0");
	printf("\033[0;30m");
}

void green(void){
	system("color 0");
	printf("\033[0;32m");
}

void yellow(void){
	system("color 0");
	printf("\033[0;33m");
}

void blue(void){
	system("color 0");
	printf("\033[0;34m");
}

void purple(void){
	system("color 0");
	printf("\033[0;35m");
}

void cyan(void){
	system("color 0");
	printf("\033[0;36m");
}

void white(void){
	system("color 0");
	printf("\033[0;37m");
}

//________________________________________________________________________

void menu1(void){
	
	cyan();
	printf("\n\n\t\t\t");printf("*************************************************\n");
	printf("\t\t\t");printf("*\t\tPolynome Section\t\t\t*\n");
	printf("\t\t\t");printf("*************************************************\n\n\n");
	printf("\t\t\t\t");printf("1)- Saisir et affichage un polynome.\n");
	printf("\t\t\t\t");printf("2)- L'image d'un X par un polynome.\n");
	printf("\t\t\t\t");printf("3)- Addition de deux polynomes.\n");
	printf("\t\t\t\t");printf("4)- Multiplication de deux Polynomes.\n");
	printf("\t\t\t\t");printf("5)- Developpeur Informations.\n");
	printf("\t\t\t\t");printf("0)- Sortir.!");
	printf("\n\n\n\t\t\t\t");printf("_______Entrer votre choix : ");
	white();
}
