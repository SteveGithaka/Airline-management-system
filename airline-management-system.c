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

	switch(menu_choice)
	{
		case 1:
			
			reservationA();
			break;
			
		case 2:
			
			reservationB();
			break;

        case 3: 
        
			viewdetails();
			printf("\n\nPress any key to go to Main Menu..");
			getch();
			break;
			
		case 4:
			
			printf("\n\tYour Details Have Been Saved To A File(If Any)");
			return(0);
			
		default:
			
			printf("\nInvalid choice");
	}
	
	goto start;
	return(0);
	
}

void viewdetails(void)
{
	
	system("cls");
printf("--------------------------------------------------------------------------------------------------------------------------------------------------------");
	printf("\nFlight.No\t Name\t\t\t\t Destinations          |\t\t\t Charges \t\t Date     \t\t  Duration\n");
	printf("--------------------------------------------------------------------------------------------------------------------------------------------------------");
	printf("\n1001\t\t Flight 01\t\t\t Kenya To Tanzania     |\t\t\tKsh 30000  \t\t 01 Apr 2025\t\t 2hrs ");
	printf("\n1002\t\t Flight 02\t\t\t Kenya To Uganda       |\t\t\tKsh 40000  \t\t 02 Apr 2025\t\t 2hrs ");
	printf("\n1003\t\t Flight 03\t\t\t Kenya To Botswana     |\t\t\tKsh 50000  \t\t 03 Apr 2025\t\t 4hrs ");
	  printf("\n1004\t\t Flight 04\t\t\t Kenya To Algeria      |\t\t\tKsh 60000  \t\t 04 Apr 2025\t\t 5hrs ");
	printf("\n1005\t\t Flight 05\t\t\t Kenya To Angola       |\t\t\tKsh 70000  \t\t 05 Apr 2025\t\t 6hrs ");
	printf("\n1006\t\t Flight 06\t\t\t Kenya To Egypt        |\t\t\tKsh 80000  \t\t 06 Apr 2025\t\t 6hrs ");
	   printf("\n1007\t\t Flight 07\t\t\t Kenya To Malawi       |\t\t\tKsh 90000  \t\t 04 Apr 2025\t\t 7hrs ");
	  printf("\n1008\t\t Flight 08\t\t\t Kenya To South Sudan  |\t\t\tKsh 100000 \t\t 08 Apr 2025\t\t 8hrs "); 
	  printf("\n1009\t\t Flight 09\t\t\t Kenya To Nigeria      |\t\t\tKsh 110000 \t\t 04 Apr 2025\t\t 9hrs");
	 printf("\n1010\t\t Flight 10\t\t\t Kenya To South Africa |\t\t\tKsh 120000 \t\t 02 Apr 2025\t\t 10hrs");


}



void reservationA(void)
{

char confirm;
int i=0;
float charges;

pd passdetails;
FILE *fp1;
fp1=fopen("Kenya.txt","a");
system("cls");

printf("\nEnter Your Name :> ");
fflush(stdin);
gets(passdetails.name);

printf("\n\n>>Press Enter To View Available flights >> ");
getch();
system("cls");
viewdetails();

printf("\n\nEnter flight number :> ");
start1:
scanf("%d",&passdetails.flight_num);

if(passdetails.flight_num>=1001 && passdetails.flight_num<=1010)
{
charges=charge(passdetails.flight_num);
printticket(passdetails.name,passdetails.flight_num,charges);
}

else
{

printf("\nInvalid Flight Number!");
printf("\n Enter again --> ");
goto start1;

}

printf("\n\nConfirm Ticket ('y' for yes/'n' for no) :>");
start:
scanf(" %c",&confirm);

if(confirm == 'y')
{
fprintf(fp1,"%s\t\t%d\t\t%.2f\n",&passdetails.name,passdetails.flight_num,charges);
printf("\n****************************************");
printf("\n RESERVATION DONE.......HAPPY JOURNEY :)");
printf("\n****************************************\n");
printf("\nPress any key to go back to Main menu");
}

else
{
if(confirm=='n')
{
	printf("\nSorry to see you go :( ");
	printf("\nReservation cancelled...");
	printf("\nPress any key to go back to  Main menu!");
}

else
{
	printf("\nInvalid choice entered! Enter again -----> ");
	goto start;
}

}
fclose(fp1);
getch();


}


void reservationB(void)
{
	
	char confirm;
	int i=0;
	float charges;
	pd passdetails;
	FILE *fp2;
	fp2=fopen("World.txt","a");
	system("cls");

	printf("\nEnter Your Name:> ");
	fflush(stdin);
	gets(passdetails.name);
	printf("\n\n>>Press Enter To View Available Flights ->> ");
	getch();
	system("cls");
	viewdetails();
	printf("\n\nEnter flight number:> ");
	start1:
	scanf("%d",&passdetails.flight_num);
	
	if(passdetails.flight_num>=1001 && passdetails.flight_num<=1010)
	{
		charges=charge(passdetails.flight_num);
		printticket(passdetails.name,passdetails.flight_num,charges);
	}
	
	else
	{
		printf("\nInvalid Flight Number!");
		printf(" Enter again --> ");
		goto start1;
	}
	
	printf("\n\nConfirm Ticket (y/n):>");
	start:
	scanf(" %c",&confirm);
	
	if(confirm == 'y')
	{
		
		fprintf(fp2,"%s\t\t%d\t\t%.2f\n",&passdetails.name,passdetails.flight_num,charges);
		printf("\n*********************************************");
		printf("\n RESERVATION SUCCESSFUL......HAPPY JOURNEY :)");
		printf("\n*********************************************");
		printf("\n\nPress any key to go back to Main menu");
		
	}
	
	else
	{
		
		if(confirm=='n')
		{
			printf("\n\nSorry To See You Go :(");
			printf("\nReservation Not Done!");
			printf("\n\nPress any key to go back to  Main menu!");
		}
		
		else
		{
			printf("\nInvalid choice entered! \nEnter again-----> ");
			goto start;
		}
		
	}
	
	
	fclose(fp2);
	getch();
	
}

float charge(int flight_num)
{

	if (flight_num==1001)
	{
		return(30000);
	}
	
	if (flight_num==1002)
	{
		return(40000);
	}
	
	if (flight_num==1003)
	{
		return(50000);
	}
	
	if (flight_num==1004)
	{
		return(60000);
	}
	
	if (flight_num==1005)
	{
		return(70000);
	}
	
	if (flight_num==1006)
	{
		return(80000);
	}
	
	if (flight_num==1007)
	{
		return(90000);
	}
	
	if (flight_num==1008)
	{
		return(10000);
	}
	
	if (flight_num==1009)
	{
		return(110000);
	}
	
	if (flight_num==1010)
	{
		return(120000);
	}
	
}

void printticket(char name[],int flight_num,float charges)
{
	
	
	system("cls");
	printf("\n----------------------------------------------------------------------\n");
	printf("\t                         TICKET");
	printf("\n----------------------------------------------------------------------\n\n");
	printf("Name\t\t\t\t\t:     %s",name);
	printf("\nFlight Number\t\t\t\t:     %d",flight_num);
	specificflight(flight_num);
	printf("\nCharges\t\t\t\t\t:     %.2f",charges);
	
	
}
