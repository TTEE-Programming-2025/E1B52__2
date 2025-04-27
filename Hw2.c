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
    printf("*                     E1B52 µ{¶°≥]≠p±Mƒ›µe≠±ù¢                     *\n");
    printf("*                                                                  *\n");
    printf("*------------------------------------------------------------------*\n");
    printf("*      ß@™Ã: %s                 *\n", AUTHOR);
    printf("*------------------------------------------------------------------*\n");
    printf("*                                                                  *\n");
    printf("*   EEEEE  1    BBBBB   55555  22222                               *\n");
    printf("*   E      1    B    B  5          2                               *\n");
    printf("*   EEEE   1    BBBBB   55555  22222                               *\n");
    printf("*   E      1    B    B      5  2                                   *\n");
    printf("*   EEEEE  1    BBBBB   55555  22222                               *\n");
    printf("*                                                                  *\n");
    printf("*------------------------------------------------------------------*\n");
    printf("*      Ω–øÈ§J4¶Ïº∆±KΩX•Hƒ~ƒÚ (±KΩX¥£•‹°G2025)                      *\n");
    printf("*                                                                  *\n");
    printf("********************************************************************\n");
}


void printMenu() {
    clearScreen();
    printf("------------------------------\n");
    printf("| a. µe•X™Ω®§§T®§ßŒ            |\n");
    printf("| b. ≈„•‹≠º™k™Ì                 |\n");
    printf("| c. µ≤ßÙ                       |\n");
    printf("------------------------------\n");
    printf("Ω–øÔæ‹ (a/b/c): ");
}


void drawTriangle() {
    char ch;
    printf("Ω–øÈ§J§@≠”¶r§∏ (a~n): ");
    scanf(" %c", &ch);
    flushInput();

    if (ch < 'a' || ch > 'n') {
        printf("\nøÈ§Jø˘ª~°I•≤∂∑¨O a~n ™∫¶r§∏°C\n");
        waitForEnter("\n´ˆEnter¡‰™¶^•DøÔ≥Ê...\n");  
        return;
    }

    clearScreen();
    printf("™Ω®§§T®§ßŒ°G\n");
    printf("--------------------------------\n");
    for (char i = 'a'; i <= ch; i++) {
        for (char j = 'a'; j <= i; j++) {
            printf("%c ", i);
        }
        printf("\n");
    }
    printf("--------------------------------\n");
    waitForEnter("\n´ˆEnter¡‰™¶^•DøÔ≥Ê...\n"); 
}


void printMultiplicationTable() {
    int n;
    printf("Ω–øÈ§J§@≠”æ„º∆ (1~9): ");
    scanf("%d", &n);
    flushInput();

    if (n < 1 || n > 9) {
        printf("\nøÈ§Jø˘ª~°I•≤∂∑¨O 1 ®Ï 9 §ß∂°°C\n");
        waitForEnter("\n´ˆEnter¡‰™¶^•DøÔ≥Ê...\n"); 
        return;
    }

    clearScreen();
    printf("%d x %d ™∫≠º™k™Ì°G\n", n, n);
    printf("--------------------------------\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%2d ", i * j);
        }
        printf("\n");
    }
    printf("--------------------------------\n");
    waitForEnter("\n´ˆEnter¡‰™¶^•DøÔ≥Ê...\n"); 
}

int main() {
    char inputPassword[10];
    int attempt = 0;
    int correct = 0;


    while (attempt < 3) {
        clearScreen();
        printWelcomeScreen();
        printf("\nΩ–øÈ§J±KΩX°G");
        scanf("%9s", inputPassword);  
        flushInput();

        if (strcmp(inputPassword, PASSWORD) == 0) {
            correct = 1;
            break;
        } else {
            printf("\n±KΩXø˘ª~°IΩ–¶A∏’§@¶∏°C\n");
            attempt++;
            waitForEnter("\n´ˆEnter¡‰™¶^•DøÔ≥Ê...\n"); 
        }
    }

    if (!correct) {
        printf("\n≥sƒÚ§T¶∏øÈ§Jø˘ª~°Aµ{¶°µ≤ßÙ°C\n");
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
                printf("ΩT©w≠nµ≤ßÙ∂‹°H(y/n): ");
                scanf(" %c", &confirm);
                flushInput();
                confirm = tolower(confirm);
                if (confirm == 'y') {
                    printf("\nµ{¶°µ≤ßÙ°A¡¬¡¬®œ•Œ°I\n");
                    return 0;
                }
                break;
            }
            default:
            	printf("\nøÔ∂µø˘ª~°AΩ–≠´∑søÈ§J°C\n"); 
                waitForEnter("\n´ˆEnter¡‰™¶^•DøÔ≥Ê...\n"); 
                break;
        }
    }

    return 0;
}
§ﬂ±o:≥o¶∏™∫ß@∑~≈˝ß⁄æ«≤ﬂ®Ïbreak©Mif-elseµ•µ•™∫µ{¶°ªy®•¿≥•Œ
¶˝¶b≥o¶∏™∫√∫•ÊπLµ{§§°A¶]¨∞ß⁄™∫macπq∏£¨µMß‰¥M§£®Ï¿…Æ◊°A©“
•H®œ•Œwindows®t≤Œ∂i¶Ê¿Ùπ“™∫¶w∏À°A∞›√D¶≥≥Q∂∂ßQ∏—®M°Aß∆±Ê§U
¶∏Ø‡ßÛ∂∂∫Z°C 
