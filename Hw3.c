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
    for (int i = 0; i < ROWS; ++i)
        for (int j = 0; j < COLS; ++j)
            seats[i][j] = '*';
}

//DisplaySeats
void displaySeats() {
    printf(" 123456789\n");
    for (int i = ROWS - 1; i >= 0; --i) {
        printf("%d", i + 1);
        for (int j = 0; j < COLS; ++j)
            printf("%c", seats[i][j]);
        printf("\n");
    }
}

void arrangeForYou(int n) {
    int count = 0;
    srand((unsigned)time(NULL));
    while (count < n) {
        int r = rand() % ROWS;
        int c = rand() % COLS;
        if (seats[r][c] == '*') {
            seats[r][c] = '@';
            count++;
        }
    }
}

//
void chooseByYourself(int n) {
    int row, col;
    int count = 0;
    while (count < n) {
   
