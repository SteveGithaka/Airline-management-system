#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

// Define constants for user management
#define MAX_USERS 100
#define MAX_USERNAME_LENGTH 30
#define MAX_PASSWORD_LENGTH 30

// Structure for passenger details
typedef struct{
    char name[50];
    int flight_num;
} pd;

// Structure for user accounts
typedef struct {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    bool isActive;
} User;

// Global variables for user management
User users[MAX_USERS];
int userCount = 0;

// Function prototypes
void reservationA(void);
void reservationB(void);
void viewdetails(void);
void printticket(char name[], int, float);
void specificflight(int);
float charge(int);
void login();
bool registerUser();
int loginUser();
bool changePassword(int userIndex);
void initUsers();
void displayUserMenu();

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
    
    // Initialize users array
    initUsers();
    
    int authChoice;
    int userIndex = -1;
    
    do {
        system("cls");
        printf("\n----------------------------------------------------------------------\n");
        printf("\t                 KENYA AIRWAYS");
        printf("\n----------------------------------------------------------------------\n\n");
        
        printf("1. Register New Account\n");
        printf("2. Login to Existing Account\n");
        printf("3. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &authChoice);
        
        switch(authChoice) {
            case 1:
                registerUser();
                break;
                
            case 2:
                userIndex = loginUser();
                if(userIndex >= 0) {
                    // Successfully logged in, show main menu
                    displayUserMenu();
                }
                break;
                
            case 3:
                printf("\nThank you for choosing Kenya Airways. Goodbye!\n");
                return 0;
                
            default:
                printf("\nInvalid choice! Press any key to try again...");
                getch();
        }
    } while(authChoice != 3);
    
    return 0;
}
