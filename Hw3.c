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
    printf("   \\ ");
    for (j = 1; j <= COLS; ++j)
        printf("%2d", j);
    printf("\n");
    for (i = ROWS - 1; i >= 0; --i) {
        printf("%2d ", i + 1);
        for (j = 0; j < COLS; ++j)
            printf("%c", seats[i][j]);
        printf("\n");
    }
    printf("\n");
    waitForUser();
}
void waitForUser() {
    printf("Press Enter to return to main menu...");
    while (getchar() != '\n'); 
    getchar(); 
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
    displaySeats();
    char confirm;
    printf("Do you accept the arrangement? (y/n): ");
    scanf(" %c", &confirm);
    if (confirm == 'y' || confirm == 'Y') {
        for (r = 0; r < ROWS; ++r)
            for (c = 0; c < COLS; ++c)
                if (seats[r][c] == '@')
                    seats[r][c] = '*';
    } else {
        for (r = 0; r < ROWS; ++r)
            for (c = 0; c < COLS; ++c)
                if (seats[r][c] == '@')
                    seats[r][c] = '-';
    }
    clearScreen();
}

void chooseByYourself(int n) {
    int row, col, count = 0;
    char input[10];
    int i, j;  
    while (count < n) {
        printf("Enter seat location (row and column): ");
        scanf("%s", input);
        if (sscanf(input, "%d-%d", &row, &col) == 2 && row >= 1 && row <= ROWS && col >= 1 && col <= COLS) {
            if (seats[row - 1][col - 1] == '-') {
                seats[row - 1][col - 1] = '@';
                count++;
            } else {
                printf("That seat is already booked. Please choose another one.\n");
            }
        } else {
            printf("Invalid input. Please try again\n");
        }
    }
    displaySeats();
    for (i = 0; i < ROWS; ++i)
        for (j = 0; j < COLS; ++j)
            if (seats[i][j] == '@')
                seats[i][j] = '*';
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
        while (getchar() != '\n');
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
    while (getchar() != '\n');
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
                while (getchar() != '\n');
                if (numSeats >= 1 && numSeats <= 4){
                    arrangeForYou(numSeats);
                }else{
                    printf("Invalid input! \n");
            }
                break;
            }
            case 'c': {
                printf("Please enter how many seats you want to choose (1~4): ");
                scanf("%d", &numSeats);
                while (getchar() != '\n');
                if (numSeats >= 1 && numSeats <= 4){
                    chooseByYourself(numSeats);
                }else{
                    printf("Invalid input! \n");
                }
                break;
            }
            case 'd':
                do {
                    printf("Continue? (y/n): ");
                    scanf(" %c", &continueChoice);
                    while (getchar() != '\n');
                    if (continueChoice == 'n' || continueChoice == 'N') {
                        printf("System shutting down. Goodbye!\n");
                        return 0;
                    } else if (continueChoice == 'y' || continueChoice == 'Y') {
                        break;
                    } else {
                        printf("Invalid input. Please enter 'y' or 'n'.\n");
                    }
                } while (1);
                break;
            default:
                printf("Invalid menu choice.\n");
        }
    } while (1);

    return 0;
}


   
