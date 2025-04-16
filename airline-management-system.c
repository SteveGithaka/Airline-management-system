#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>


typedef struct{
	char name[50];
	int flight_num;
}pd;


void reservationA(void);
void reservationB(void);
void viewdetails(void);
void printticket(char name[],int,float);
void specificflight(int);
float charge(int);
void login();
int main()


{
	
	system("cls");
	system("COLOR 0B");
	printf("\t\t**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
	printf("\t\t-------------------------------------------------\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|       ----------------------------------      |\n");
	printf("\t\t|        WELCOME TO KENYA AIRWAYS               |\n");
	printf("\t\t|          The Pride of Africa                  |\n");
	printf("\t\t|       ----------------------------------      |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t-------------------------------------------------\n");
	printf("\t\t**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n\n");


	printf(" \n Press any key to continue:");
	getch();
    system("cls");
	login();
	int menu_choice,choice_return;
	start:
	system("cls");
	printf("\n\t=====================================\n");
	printf("  \t     KENYA AIRWAYS       \n");
	printf("\n\t=====================================");
	printf("\n\n\t1>> Reserve A Ticket To Travel with us ");
	printf("\n\t3>> View All Available Flights");
	printf("\n\t------------------------");
	printf("\n\t4>> Exit");
	printf("\n\n\tEnter your choice from above (1-4)->>\t-->");
	scanf("%d",&menu_choice);
}