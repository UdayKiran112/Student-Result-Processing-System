#include "student.h"

// Function to check validity of student ID
// returns 0 if valid, -1 if invalid(not alphanumeric), 1 if duplicate
int checkID(char id[], Student students[], int count)
{
    // Alphanumeric check
    for (int i = 0; id[i] != '\0'; i++)
    {
        if (!isalnum(id[i]))
        {
            fprintf(stderr, "Invalid ID: %s\n", id);
            return -1;
        }
    }

    // Duplicate ID check
    for (int i = 0; i < count; i++)
    {
        if (strcmp(students[i].id, id) == 0)
        {
            fprintf(stderr, "Duplicate ID found: %s\n", id);
            return 1;
        }
    }

    return 0;
}

// Function to check validity of student Name
// returns 0 if valid, 1 if invalid
int checkName(char name[])
{
    for (int i = 0; name[i] != '\0'; i++)
    {
        if (!isalpha(name[i]) && !isspace(name[i]))
        {
            fprintf(stderr, "Invalid Name: %s\n", name);
            return 1;
        }
    }

    return 0;
}

// Function to check validity of Marks
// returns 0 if valid, 1 if minor marks invalid, -1 if major marks invalid, 2 if total marks invalid
int checkMarks(float minorMarks, float majorMarks)
{
    if (minorMarks < 0.0 || minorMarks > 40.0)
    {
        fprintf(stderr, "Invalid Minor Marks: %.2f\n", minorMarks);
        return 1;
    }
    else if (majorMarks < 0.0 || majorMarks > 60.0)
    {
        fprintf(stderr, "Invalid Major Marks: %.2f\n", majorMarks);
        return -1;
    }

    return 0;
}

// Function to calculate grade based on percentage
Grade calculateGrade(float percentage)
{
    if (percentage >= 90.0)
    {
        return O;
    }
    else if (percentage >= 85.0 && percentage < 90.0)
    {
        return A_PLUS;
    }
    else if (percentage >= 75.0 && percentage < 85.0)
    {
        return A;
    }
    else if (percentage >= 65.0 && percentage < 75.0)
    {
        return B_PLUS;
    }
    else if (percentage >= 60.0 && percentage < 65.0)
    {
        return B;
    }
    else if (percentage >= 55.0 && percentage < 60.0)
    {
        return C;
    }
    else if (percentage >= 50.0 && percentage < 55.0)
    {
        return D;
    }
    else
    {
        return F;
    }
}

// Function to convert Grade enum to string
char *gradeToString(Grade grade)
{
    switch (grade)
    {
    case O:
        return "O";
    case A_PLUS:
        return "A+";
    case A:
        return "A";
    case B_PLUS:
        return "B+";
    case B:
        return "B";
    case C:
        return "C";
    case D:
        return "D";
    case F:
        return "F";
    default:
        return "Unknown";
    }
}