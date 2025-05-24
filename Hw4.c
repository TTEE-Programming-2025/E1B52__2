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

// Welcome screen
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

// Enter student data
void enterStudentGrades(Student student[], int *count) { 
	char cont;
	do{
		if(*count >= MAX_STUDENTS) {
			printf("Student data limit reached (%d entries).\n", MAX_STUDENTS);
			break;
		}
		
		printf("Enter data for student #%d:\n", *count + 1);
        printf("Name: ");
        scanf("%s", student[*count].name);
        printf("Student ID (6 digits): ");
        scanf("%s", student[*count].id);
        printf("Math score (0-100): ");
        scanf("%f", &student[*count].math);
        printf("Physics score (0-100): ");
        scanf("%f", &student[*count].physics);
        printf("English score (0-100): ");
        scanf("%f", &student[*count].english);
        
        student[*count].average = (student[*count].math + student[*count].physics + student[*count].english) / 3.0;
        (*count)++;
                   
        printf("Do you want to enter another student's data? (y/n): ");
        scanf(" %c", &cont);
    } while (cont == 'y' || cont == 'Y');

    printf("Student data entry complete!\n"); 
}
   //Displays the student's name and ID
	void displayStudentGrades(Student students[], int count) {
	int i;
    printf("Name\tID\t\tMath\tPhysics\tEnglish\tAverage\n");
    for (i = 0; i < count; i++) {
        printf("%s\t%s\t%.1f\t%.1f\t%.1f\t%.2f\n",
               students[i].name, students[i].id,
               students[i].math, students[i].physics, students[i].english, students[i].average);//Displays the student's score and average
    }
}

//A function to search for student information and grades
void searchStudent(Student students[], int count) {
    char keyword[50];
    int found = 0;
    int i;
    
    printf("Enter name or ID to search: ");
    scanf("%s", keyword);
    
    for (i = 0; i < count; i++) {
        if (strcmp(students[i].name, keyword) == 0 || strcmp(students[i].id, keyword) == 0) {
            printf("Student found:\n");
            printf("Name: %s, ID: %s, Math: %.1f, Physics: %.1f, English: %.1f, Average: %.2f\n",
                   students[i].name, students[i].id,
                   students[i].math, students[i].physics, students[i].english, students[i].average);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No matching student found.\n");
    }
}

//Compare students' average grades
void rankStudents(Student students[], int count) {
    Student temp;
    int i, j;
    
    for (i = 0; i < count - 1; i++) {
        for (j = i + 1; j < count; j++) {
            if (students[j].average > students[i].average ||
                (students[j].average == students[i].average &&
                 strcmp(students[j].name, students[i].name) < 0)) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    
    printf("Students ranked by average score:\n");
    displayStudentGrades(students, count);
}

// Exit confirmation
int confirmExit() {
    char choice;
    printf("Are you sure you want to exit? (y/n): ");
    scanf(" %c", &choice);
    return (choice == 'y' || choice == 'Y');
}

// Main program
int main() {
    Student students[MAX_STUDENTS];
    int studentCount = 0;
    int inputPassword;
    char option;
    
    printWelcomeScreen();

    printf("Enter password: ");
    scanf("%d", &inputPassword);
    
    if (inputPassword != PASSWORD) {
        printf("Incorrect password. Program will exit.\n");
        return 0;
    }

    // Main menu loop
    do {
        printf("\n--------- [Grade System] ---------\n");
        printf("a. Enter student grades\n");
        printf("b. Display student grades\n");
        printf("c. Search for student grades\n");
        printf("d. Grade ranking\n");
        printf("e. Exit system\n");
        printf("----------------------------------\n");
        printf("Enter your choice: ");
        scanf(" %c", &option);

        switch (option) {
            case 'a':
                enterStudentGrades(students, &studentCount);
                break;
            case 'b':
                displayStudentGrades(students, studentCount);
                break;
            case 'c':
                searchStudent(students, studentCount);
                break;
            case 'd':
                rankStudents(students, studentCount);
                break;
            case 'e':
                if (confirmExit()) {
                    printf("Exiting system. Goodbye!\n");
                    return 0;
                }
                break;
            default:
                printf("Invalid option. Try again.\n");
        }
    } while (1);

    return 0;
}
