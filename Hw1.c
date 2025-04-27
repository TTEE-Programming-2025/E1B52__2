#include <stdio.h>
#include <stdlib.h>

void displayScreen() {
    printf("==============================\n");
    printf("=        Welcome!           =\n");
    printf("=     Personal Design       =\n");
    printf("=      Your Artwork         =\n");
    printf("==============================\n");
    printf("Press Enter to continue...");
    getchar();
}

int checkPassword() {
    int password;
    printf("\nEnter 4-digit password: ");
    scanf("%d", &password);
    
    if (password == 2024) {
        printf("\nWelcome! Access granted.\n");
        return 1;
    } else {
        printf("\nIncorrect password! Exiting...\n");
        return 0;
    }
}

void displayMenu() {
    system("clear");
    printf("-----------------------------\n");
    printf("|  'A'...'Z'  : Uppercase   |\n");
    printf("|  'a'...'z'  : Lowercase   |\n");
    printf("|  '0'...'9'  : Digit       |\n");
    printf("|  Otherwise  : Your name   |\n");
    printf("-----------------------------\n");
}

void characterChecker() {
    char input;
    printf("\nEnter a character: ");
    scanf(" %c", &input);
    
    if (input >= 'A' && input <= 'Z') {
        printf("Uppercase\n");
    } else if (input >= 'a' && input <= 'z') {
        printf("Lowercase\n");
    } else if (input >= '0' && input <= '9') {
        printf("Digit\n");
    } else {
        printf("Your Class and Name\n");
    }
    printf("Press any key to exit...");
    getchar();
    getchar();
}

int main() {
    displayScreen();
    
    if (!checkPassword()) {
        return 0;
    }
    
    displayMenu();
    characterChecker();
    return 0;
}

