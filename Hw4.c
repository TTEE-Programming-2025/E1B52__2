#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define AUTHOR "E1B 52" 
#define MAX_STUDENTS 100
#define PASSWORD 2025

typedef struct {
    char name[50];
    char id[10];
    float math;
    float physics;
    float english;
    float average;
} Student;
//personal profile
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

void enterStudentGrades(Student student[], int *count) { //Declare a function for entering student grades
	char cont;
	do{
		if(*count >= MAX_STUDENTS) {
			printf("Student data limit reached (%d entries).\n", MAX_STUDENTS);
			break;
		}
		
		printf("Enter data for student #%d:\n", *count + 1);
        printf("Name: ");
        scanf("%s", students[*count].name);//Enter all student data and store it in a structure(49-57)
        printf("Student ID (6 digits): ");
        scanf("%s", students[*count].id);
        printf("Math score (0-100): ");
        scanf("%f", &students[*count].math);
        printf("Physics score (0-100): ");
        scanf("%f", &students[*count].physics);
        printf("English score (0-100): ");
        scanf("%f", &students[*count].english);
        
        students[*count].average = (students[*count].math + students[*count].physics + students[*count].english) / 3.0;
        (*count)++;
                   
        printf("Do you want to enter another student's data? (y/n): ");
        scanf(" %c", &cont);
     } while (cont == 'y' || cont == 'Y');


	}
}
