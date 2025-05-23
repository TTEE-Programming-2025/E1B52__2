#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define PASSWORD "2025"
#define AUTHOR "E1B52-YourName"


void clearScreen() {
    system("cls||clear");
}


void flushInput() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void waitForEnter(const char *message) {
    printf("%s", message);
    flushInput();
    getchar();
}

void printWelcomeScreen() {
    printf("********************************************************************\n");
    printf("*                                                                  *\n");
    printf("*                     E1B52 程式設計專屬畫面��                     *\n");
    printf("*                                                                  *\n");
    printf("*------------------------------------------------------------------*\n");
    printf("*      作者: %s                 *\n", AUTHOR);
    printf("*------------------------------------------------------------------*\n");
    printf("*                                                                  *\n");
    printf("*   EEEEE  1    BBBBB   55555  22222                               *\n");
    printf("*   E      1    B    B  5          2                               *\n");
    printf("*   EEEE   1    BBBBB   55555  22222                               *\n");
    printf("*   E      1    B    B      5  2                                   *\n");
    printf("*   EEEEE  1    BBBBB   55555  22222                               *\n");
    printf("*                                                                  *\n");
    printf("*------------------------------------------------------------------*\n");
    printf("*      請輸入4位數密碼以繼續 (密碼提示：2025)                      *\n");
    printf("*                                                                  *\n");
    printf("********************************************************************\n");
}


void printMenu() {
    clearScreen();
    printf("------------------------------\n");
    printf("| a. 畫出直角三角形            |\n");
    printf("| b. 顯示乘法表                 |\n");
    printf("| c. 結束                       |\n");
    printf("------------------------------\n");
    printf("請選擇 (a/b/c): ");
}


void drawTriangle() {
    char ch;
    printf("請輸入一個字元 (a~n): ");
    scanf(" %c", &ch);
    flushInput();

    if (ch < 'a' || ch > 'n') {
        printf("\n輸入錯誤！必須是 a~n 的字元。\n");
        waitForEnter("\n按Enter鍵返回主選單...\n");  
        return;
    }

    clearScreen();
    printf("直角三角形：\n");
    printf("--------------------------------\n");
    for (char i = 'a'; i <= ch; i++) {
        for (char j = 'a'; j <= i; j++) {
            printf("%c ", i);
        }
        printf("\n");
    }
    printf("--------------------------------\n");
    waitForEnter("\n按Enter鍵返回主選單...\n"); 
}


void printMultiplicationTable() {
    int n;
    printf("請輸入一個整數 (1~9): ");
    scanf("%d", &n);
    flushInput();

    if (n < 1 || n > 9) {
        printf("\n輸入錯誤！必須是 1 到 9 之間。\n");
        waitForEnter("\n按Enter鍵返回主選單...\n"); 
        return;
    }

    clearScreen();
    printf("%d x %d 的乘法表：\n", n, n);
    printf("--------------------------------\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%2d ", i * j);
        }
        printf("\n");
    }
    printf("--------------------------------\n");
    waitForEnter("\n按Enter鍵返回主選單...\n"); 
}

int main() {
    char inputPassword[10];
    int attempt = 0;
    int correct = 0;


    while (attempt < 3) {
        clearScreen();
        printWelcomeScreen();
        printf("\n請輸入密碼：");
        scanf("%9s", inputPassword);  
        flushInput();

        if (strcmp(inputPassword, PASSWORD) == 0) {
            correct = 1;
            break;
        } else {
            printf("\n密碼錯誤！請再試一次。\n");
            attempt++;
            waitForEnter("\n按Enter鍵返回主選單...\n"); 
        }
    }

    if (!correct) {
        printf("\n連續三次輸入錯誤，程式結束。\n");
        return 0;
    }


    char choice;
    while (1) {
        printMenu();
        scanf(" %c", &choice);
        flushInput();
        choice = tolower(choice);

        switch (choice) {
            case 'a':
                drawTriangle();
                break;
            case 'b':
                printMultiplicationTable();
                break;
            case 'c': {
                char confirm;
                printf("確定要結束嗎？(y/n): ");
                scanf(" %c", &confirm);
                flushInput();
                confirm = tolower(confirm);
                if (confirm == 'y') {
                    printf("\n程式結束，謝謝使用！\n");
                    return 0;
                }
                break;
            }
            default:
            	printf("\n選項錯誤，請重新輸入。\n"); 
                waitForEnter("\n按Enter鍵返回主選單...\n"); 
                break;
        }
    }

    return 0;
}
心得:這次的作業讓我學習到break和if-else等等的程式語言應用
但在這次的繳交過程中，因為我的mac電腦突然找尋不到檔案，所
以使用windows系統進行環境的安裝，問題有被順利解決，希望下
次能更順暢。 
