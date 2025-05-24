#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define AUTHOR "E1B 52" 
#define MAX_STUDENTS 10
#define PASSWORD 2025

typedef struct {
    char name[50];
    char id[10];
    float math;
    float physics;
    float english;
    float average;
} Student;

