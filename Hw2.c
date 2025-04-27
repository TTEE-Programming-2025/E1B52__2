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
    printf("*                     E1B52 �{���]�p�M�ݵe����                     *\n");
    printf("*                                                                  *\n");
    printf("*------------------------------------------------------------------*\n");
    printf("*      �@��: %s                 *\n", AUTHOR);
    printf("*------------------------------------------------------------------*\n");
    printf("*                                                                  *\n");
    printf("*   EEEEE  1    BBBBB   55555  22222                               *\n");
    printf("*   E      1    B    B  5          2                               *\n");
    printf("*   EEEE   1    BBBBB   55555  22222                               *\n");
    printf("*   E      1    B    B      5  2                                   *\n");
    printf("*   EEEEE  1    BBBBB   55555  22222                               *\n");
    printf("*                                                                  *\n");
    printf("*------------------------------------------------------------------*\n");
    printf("*      �п�J4��ƱK�X�H�~�� (�K�X���ܡG2025)                      *\n");
    printf("*                                                                  *\n");
    printf("********************************************************************\n");
}


void printMenu() {
    clearScreen();
    printf("------------------------------\n");
    printf("| a. �e�X�����T����            |\n");
    printf("| b. ��ܭ��k��                 |\n");
    printf("| c. ����                       |\n");
    printf("------------------------------\n");
    printf("�п�� (a/b/c): ");
}


void drawTriangle() {
    char ch;
    printf("�п�J�@�Ӧr�� (a~n): ");
    scanf(" %c", &ch);
    flushInput();

    if (ch < 'a' || ch > 'n') {
        printf("\n��J���~�I�����O a~n ���r���C\n");
        waitForEnter("\n��Enter���^�D���...\n");  
        return;
    }

    clearScreen();
    printf("�����T���ΡG\n");
    printf("--------------------------------\n");
    for (char i = 'a'; i <= ch; i++) {
        for (char j = 'a'; j <= i; j++) {
            printf("%c ", i);
        }
        printf("\n");
    }
    printf("--------------------------------\n");
    waitForEnter("\n��Enter���^�D���...\n"); 
}


void printMultiplicationTable() {
    int n;
    printf("�п�J�@�Ӿ�� (1~9): ");
    scanf("%d", &n);
    flushInput();

    if (n < 1 || n > 9) {
        printf("\n��J���~�I�����O 1 �� 9 �����C\n");
        waitForEnter("\n��Enter���^�D���...\n"); 
        return;
    }

    clearScreen();
    printf("%d x %d �����k��G\n", n, n);
    printf("--------------------------------\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%2d ", i * j);
        }
        printf("\n");
    }
    printf("--------------------------------\n");
    waitForEnter("\n��Enter���^�D���...\n"); 
}

int main() {
    char inputPassword[10];
    int attempt = 0;
    int correct = 0;


    while (attempt < 3) {
        clearScreen();
        printWelcomeScreen();
        printf("\n�п�J�K�X�G");
        scanf("%9s", inputPassword);  
        flushInput();

        if (strcmp(inputPassword, PASSWORD) == 0) {
            correct = 1;
            break;
        } else {
            printf("\n�K�X���~�I�ЦA�դ@���C\n");
            attempt++;
            waitForEnter("\n��Enter���^�D���...\n"); 
        }
    }

    if (!correct) {
        printf("\n�s��T����J���~�A�{�������C\n");
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
                printf("�T�w�n�����ܡH(y/n): ");
                scanf(" %c", &confirm);
                flushInput();
                confirm = tolower(confirm);
                if (confirm == 'y') {
                    printf("\n�{�������A���¨ϥΡI\n");
                    return 0;
                }
                break;
            }
            default:
            	printf("\n�ﶵ���~�A�Э��s��J�C\n"); 
                waitForEnter("\n��Enter���^�D���...\n"); 
                break;
        }
    }

    return 0;
}
�߱o:�o�����@�~���ھǲߨ�break�Mif-else�������{���y������
���b�o����ú��L�{���A�]���ڪ�mac�q����M��M�����ɮסA��
�H�ϥ�windows�t�ζi�����Ҫ��w�ˡA���D���Q���Q�ѨM�A�Ʊ�U
����󶶺Z�C 
