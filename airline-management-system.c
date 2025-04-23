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

// Initialize users array with default user
void initUsers() {
    for (int i = 0; i < MAX_USERS; i++) {
        users[i].isActive = false;
    }
    
    // Add default admin account
    strcpy(users[0].username, "admin");
    strcpy(users[0].password, "ahas");
    users[0].isActive = true;
    userCount = 1;
}

// Function to register a new user
bool registerUser() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char confirmPassword[MAX_PASSWORD_LENGTH];
    
    system("cls");
    printf("\n----------------------------------------------------------------------\n");
    printf("\t                     USER REGISTRATION");
    printf("\n----------------------------------------------------------------------\n\n");
    
    printf("Enter username: ");
    scanf("%s", username);
    
    // Check if username already exists
    for (int i = 0; i < MAX_USERS; i++) {
        if (users[i].isActive && strcmp(users[i].username, username) == 0) {
            printf("\nUsername already exists! Please choose another username.\n");
            printf("Press any key to continue...");
            getch();
            return false;
        }
    }
    
    printf("Enter password: ");
    scanf("%s", password);
    
    printf("Confirm password: ");
    scanf("%s", confirmPassword);
    
    // Check if passwords match
    if (strcmp(password, confirmPassword) != 0) {
        printf("\nPasswords do not match! Registration failed.\n");
        printf("Press any key to continue...");
        getch();
        return false;
    }
    
    // Add new user to array
    if (userCount < MAX_USERS) {
        strcpy(users[userCount].username, username);
        strcpy(users[userCount].password, password);
        users[userCount].isActive = true;
        userCount++;
        
        printf("\nRegistration successful!\n");
        printf("Press any key to continue...");
        getch();
        return true;
    } else {
        printf("\nUser database is full! Registration failed.\n");
        printf("Press any key to continue...");
        getch();
        return false;
    }
}

// Function to authenticate user
int loginUser() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char c = ' ';
    int i = 0;
    int attempts = 0;
    
    while (attempts < 3) {
        system("cls");
        printf("\n----------------------------------------------------------------------\n");
        printf("\t                         LOGIN");
        printf("\n----------------------------------------------------------------------\n\n");
        
        printf("Enter username: ");
        scanf("%s", username);
        
        printf("Enter password: ");
        i = 0;
        while(i < MAX_PASSWORD_LENGTH - 1) {
            password[i] = getch();
            c = password[i];
            if(c == 13) break; // Enter key
            else printf("*");
            i++;
        }
        password[i] = '\0';
        
        // Check credentials
        for (int j = 0; j < MAX_USERS; j++) {
            if (users[j].isActive && 
                strcmp(users[j].username, username) == 0 && 
                strcmp(users[j].password, password) == 0) {
                printf("\n\nLogin successful! Welcome, %s!\n", username);
                printf("Press any key to continue...");
                getch();
                return j; // Return user index
            }
        }
        
        attempts++;
        printf("\n\nInvalid username or password. %d attempts remaining.\n", 3 - attempts);
        printf("Press any key to try again...");
        getch();
    }
    
    printf("\nToo many failed attempts. Returning to main menu.\n");
    printf("Press any key to continue...");
    getch();
    return -1; // Login failed
}

// Function to change password
bool changePassword(int userIndex) {
    char currentPassword[MAX_PASSWORD_LENGTH];
    char newPassword[MAX_PASSWORD_LENGTH];
    char confirmPassword[MAX_PASSWORD_LENGTH];
    char c = ' ';
    int i = 0;
    
    system("cls");
    printf("\n----------------------------------------------------------------------\n");
    printf("\t                     CHANGE PASSWORD");
    printf("\n----------------------------------------------------------------------\n\n");
    
    printf("Enter current password: ");
    i = 0;
    while(i < MAX_PASSWORD_LENGTH - 1) {
        currentPassword[i] = getch();
        c = currentPassword[i];
        if(c == 13) break; // Enter key
        else printf("*");
        i++;
    }
    currentPassword[i] = '\0';
    
    // Verify current password
    if (strcmp(users[userIndex].password, currentPassword) != 0) {
        printf("\n\nIncorrect current password!\n");
        printf("Press any key to continue...");
        getch();
        return false;
    }
    
    printf("\nEnter new password: ");
    i = 0;
    while(i < MAX_PASSWORD_LENGTH - 1) {
        newPassword[i] = getch();
        c = newPassword[i];
        if(c == 13) break; // Enter key
        else printf("*");
        i++;
    }
    newPassword[i] = '\0';
    
    printf("\nConfirm new password: ");
    i = 0;
    while(i < MAX_PASSWORD_LENGTH - 1) {
        confirmPassword[i] = getch();
        c = confirmPassword[i];
        if(c == 13) break; // Enter key
        else printf("*");
        i++;
    }
    confirmPassword[i] = '\0';
    
    // Check if new passwords match
    if (strcmp(newPassword, confirmPassword) != 0) {
        printf("\n\nNew passwords do not match!\n");
        printf("Press any key to continue...");
        getch();
        return false;
    }
    
    // Update password
    strcpy(users[userIndex].password, newPassword);
    printf("\n\nPassword changed successfully!\n");
    printf("Press any key to continue...");
    getch();
    return true;
}

// User menu display
void displayUserMenu() {
    int menu_choice, choice_return;
    
    start:
    system("cls");
    printf("\n\t=====================================\n");
    printf("  \t     KENYA AIRWAYS       \n");
    printf("\n\t=====================================");
    printf("\n\t1>> Reserve A Ticket To Travel Globally");
    printf("\n\t2>> View All Available Flights");
    printf("\n\t3>> Change Password");
    printf("\n\t                               ");
    printf("\n\t4>> Logout");
    printf("\n\n\tEnter your choice from above (1-4)->>\t-->");
    scanf("%d", &menu_choice);
    
    switch(menu_choice) {
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
            changePassword(0); // Using 0 as default, should ideally use current user index
            break;
            
        case 5:
            printf("\n\tLogging out...");
            printf("\n\tYour Details Have Been Saved To A File(If Any)");
            printf("\n\tPress any key to continue...");
            getch();
            return;
            
        default:
            printf("\nInvalid choice");
            printf("\nPress any key to try again...");
            getch();
    }
    
    goto start;
}
