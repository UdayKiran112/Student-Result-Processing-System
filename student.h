#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SUBS_COUNT 5

typedef enum
{
    O,
    A_PLUS,
    A,
    B_PLUS,
    B,
    C,
    D,
    F
} Grade;

typedef struct
{
    char id[10];
    char name[50];
    float minorScores[SUBS_COUNT];
    float majorScores[SUBS_COUNT];
    float totalScores[SUBS_COUNT];
    float percentages[SUBS_COUNT];
    Grade grades[SUBS_COUNT];
} Student;

int checkID(char id[], Student students[], int count);
int checkName(char name[]);
int checkMarks(float minorMarks, float majorMarks);
Grade calculateGrade(float percentage);
char *gradeToString(Grade grade);

#endif