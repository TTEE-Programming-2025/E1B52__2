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
    	printf("請輸入座位位置 (row col)：");
        scanf("%d %d", &row, &col);
        if (row >= 1 && row <= ROWS && col >= 1 && col <= COLS) {
            if (seats[row - 1][col - 1] == '*') {
                seats[row - 1][col - 1] = '@';
                count++;
            } else {
                printf("該座位已被預定，請重新選擇。\n");
            }
        } else {
            printf("輸入無效，請重新輸入1~9的座位位置。\n");
        }
    }
}

int main() {
    printWelcomeScreen();

    char password[10];
    printf("請輸入密碼：");
    scanf("%s", password);
    if (strcmp(password, "2025") != 0) {
        printf("密碼錯誤，程式結束！\n");
        return 0;
    }

    char id[10];
    printf("請輸入4碼的座號（必須以2開頭）：");
    scanf("%s", id);
    if (strlen(id) != 4 || id[0] != '2') {
        printf("格式錯誤，返回主選單。\n");
        return 0;
    }

    initializeSeats();

    char option;
     do {
        displayMenu();
        printf("請選擇功能選項：");
        scanf(" %c", &option);  

        switch (option) {
            case 'a':
                displaySeats();
                break;
            case 'b': {
                int n;
                printf("請輸入欲選幾位座位 (1~4)：");
                scanf("%d", &n);
                if (n >= 1 && n <= 4)
                    arrangeForYou(n);
                else
                    printf("輸入錯誤！\n");
                break;
            }
            case 'c': {
                int n;
                printf("請輸入想選幾位座位 (1~4)：");
                scanf("%d", &n);
                if (n >= 1 && n <= 4)
                    chooseByYourself(n);
                else
                    printf("輸入錯誤！\n");
                break;
            }
            case 'd':
                printf("系統結束，再見！\n");
                break;
            default:
                printf("選項錯誤，請重新輸入。\n");
        }
    } while (option != 'd');
    
    return 0;
}

   
