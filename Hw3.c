#include <stdio.h>
#include <stdlib.h> 
#define PASSWORD "2025"
#define AUTHOR "E1B52-YourName"


void clearScreen() {
    system("cls||clear");
}


void flushInput() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
