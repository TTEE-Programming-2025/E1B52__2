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
    printf("\n----------[Booking System]----------\n");
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
            seats[i][j] = '-';
            
    srand((unsigned)time(NULL));
    int count = 0;
    while (count < 10) {
        int r = rand() % ROWS;
        int c = rand() % COLS;
        if (seats[r][c] == '-') {
            seats[r][c] = '*';
            count++;
        }
    }
}

//DisplaySeats
void displaySeats() {
    int i, j;
  printf(" \\");
    for (j = 1; j <= COLS; ++j)
        printf("%d", j);
    printf("\n");
    for (i = ROWS - 1; i >= 0; --i) {
        printf("%d", i + 1);
        for (j = 0; j < COLS; ++j)
            printf("%c", seats[i][j]);
        printf("\n");
    }
    printf("\nPress any key to return to main menu...\n");
    getchar(); getchar();  
    clearScreen();
}

void arrangeForYou(int numSeats) {
    int count = 0;
    int r, c, i;
    srand((unsigned)time(NULL));
    int found = 0;

   for (r = 0; r < ROWS && !found; ++r) {
        for (c = 0; c <= COLS - numSeats; ++c) {
            int available = 1;
            for (i = 0; i < numSeats; ++i) {
                if (seats[r][c + i] != '-') {
                    available = 0;
                    break;
                }
            }
            if (available) {
                for (i = 0; i < numSeats; ++i)
                    seats[r][c + i] = '@';
                found = 1;
                break;
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
    

    while (attempt < 3) {
        printf("Please enter password: ");
        scanf("%s", password);
        if (strcmp(password, "2025") == 0) {
            break;
        } else {
            printf("Incorrect password. Try again.\n");
            attempt++;
        }
    }

    if (attempt == 3) {
        printf("Too many incorrect attempts. Program exiting.\n");
        return 0;
    }

    // Seat ID validation
    printf("Please enter a 4-digit seat ID (must start with 2): ");
    scanf("%s", id);
    if (strlen(id) != 4 || id[0] != '2') {
        printf("Format error, returning to main menu.\n");
        return 0;
    }
    
    initializeSeats();

    do {
        displayMenu();
        printf("Please select a function option: ");
        scanf(" %c", &choice);  

        switch (choice) {
            case 'a':
                displaySeats();
                break;
            case 'b': {
                printf(" Please enter the number of seats to book (1~4): ");
                scanf("%d", &numSeats);
                if (numSeats >= 1 && numSeats <= 4){
                    arrangeForYou(numSeats);
                    displaySeats();
                }else{
                    printf("Invalid input! \n");
            }
                break;
            }
            case 'c': {
                printf("Please enter how many seats you want to choose (1~4): ");
                scanf("%d", &numSeats);
                if (numSeats >= 1 && numSeats <= 4){
                    chooseByYourself(numSeats);
                    displaySeats();
                }else{
                    printf("Invalid input! \n");
                }
                break;
            }
            case 'd':
                printf("The system is shutting down, goodbye¡I\n");
                return 0;
            default:
                printf("Invalid menu choice.\n");
        }
        
        // Ask if the user wants to continue
        do {
            printf("Continue (y/n)? ");
            scanf(" %c", &continueChoice);
            if (continueChoice != 'y' && continueChoice != 'Y' && continueChoice != 'n' && continueChoice != 'N') {
                printf("Invalid input. Please enter 'y' or 'n'.\n");
            }
        } while (continueChoice != 'y' && continueChoice != 'Y' && continueChoice != 'n' && continueChoice != 'N');

    } while (continueChoice == 'y' || continueChoice == 'Y');

    return 0;
}

   
