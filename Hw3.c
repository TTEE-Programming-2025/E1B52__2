#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define AUTHOR "simon"
#define ROWS 9
#define COLS 9
char seats[ROWS][COLS];

// personal profile
void printWelcomeScreen() {
    printf("********************************************************************\n");
    printf("*                                                                  *\n");
    printf("*                E1B52 Coding Welcome Screen                       *\n");
    printf("*                                                                  *\n");
    printf("*------------------------------------------------------------------*\n");
    printf("*      AUTHOR: %s                 *\n", AUTHOR);
    printf("*------------------------------------------------------------------*\n");
    printf("*                                                                  *\n");
    printf("*   EEEEE  1    BBBBB   55555  22222                               *\n");
    printf("*   E      1    B    B  5          2                               *\n");
    printf("*   EEEE   1    BBBBB   55555  22222                               *\n");
    printf("*   E      1    B    B      5  2                                   *\n");
    printf("*   EEEEE  1    BBBBB   55555  22222                               *\n");
    printf("*                                                                  *\n");
    printf("*------------------------------------------------------------------*\n");
    printf("*Please enter the 4-digit password to continue (Password hint: 2025)*\n");
    printf("*                                                                  *\n");
    printf("********************************************************************\n");
}

// Clear screen
void clearScreen() {
    system("cls");      
}

// Main Menu
void displayMenu() {
    printf("\n-----------------------------\n");
    printf("[Booking System]\n");
    printf("a. Available seats\n");
    printf("b. Arrange for you\n");
    printf("c. Choose by yourself\n");
    printf("d. Exit\n");
    printf("-----------------------------\n");
}

//InitializeSeats
void initializeSeats() {
    int i, j;
    for (i = 0; i < ROWS; ++i)
        for (j = 0; j < COLS; ++j)
            seats[i][j] = '*';
}

//DisplaySeats
void displaySeats() {
    int i, j;
    printf(" 123456789\n");
    for (i = ROWS - 1; i >= 0; --i) {
        printf("%d", i + 1);
        for (j = 0; j < COLS; ++j)
            printf("%c", seats[i][j]);
        printf("\n");
    }
    printf("\nPress any key to return to main menu...\n");
    getchar();  
    getchar();  
    clearScreen();
}

void arrangeForYou(int n) {
    int count = 0;
    int r,c
    srand((unsigned)time(NULL));
    while (count < n) {
        r = rand() % ROWS;
        c = rand() % COLS;
        if (seats[r][c] == '*') {
            seats[r][c] = '@';
            count++;
        }
    }
}

// Manually choose seats
void chooseByYourself(int n) {
    int row, col;
    int count = 0;
    while (count < n) {
    	printf("Enter seat location (row and column): ");
        scanf("%d %d", &row, &col);
        if (row >= 1 && row <= ROWS && col >= 1 && col <= COLS) {
            if (seats[row - 1][col - 1] == '*') {
                seats[row - 1][col - 1] = '@';
                count++;
            } else {
                printf("That seat is already booked. Please choose another one.\n");
            }
        } else {
            printf("Invalid input. Please enter a seat position between 1 and 9.\n");
        }
    }
}

int main() {
	char password[10];
    char id[10];
    char choice;
    int numSeats;
    char continueChoice;
    int attempt = 0;
    
    printWelcomeScreen();
    

    char password[10];
    printf("please enter password: ");
    scanf("%s", password);
    if (strcmp(password, "2025") != 0) {
        printf(" Incorrect password. End the program \n");
        return 0;
    }

    char id[10];
    printf("Please enter a 4-digit seat ID (must start with 2)");
    scanf("%s", id);
    if (strlen(id) != 4 || id[0] != '2') {
        printf("Format error, returning to main menu.\n");
        return 0;
    }

    initializeSeats();

    char option;
     do {
        displayMenu();
        printf("Please select a function option: ");
        scanf(" %c", &option);  

        switch (option) {
            case 'a':
                displaySeats();
                break;
            case 'b': {
                int n;
                printf(" Please enter the number of seats to book (1~4): ");
                scanf("%d", &n);
                if (n >= 1 && n <= 4)
                    arrangeForYou(n);
                else
                    printf("Invalid input! \n");
                break;
            }
            case 'c': {
                int n;
                printf("Please enter how many seats you want to choose (1~4): ");
                scanf("%d", &n);
                if (n >= 1 && n <= 4)
                    chooseByYourself(n);
                else
                    printf("Invalid input! \n");
                break;
            }
            case 'd':
                printf("The system is shutting down, goodbye¡I\n");
                break;
            default:
                printf("Invalid option, please enter again \n");
        }
    } while (option != 'd');
    
    return 0;
}

   
