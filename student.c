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
int checkMarks(float minorMarks[], float majorMarks[])
{
    for (int i = 0; i < SUBS_COUNT; i++)
    {
        if (minorMarks[i] < 0.0 || minorMarks[i] > 40.0)
        {
            fprintf(stderr, "Invalid Minor Marks: %.2f\n", minorMarks[i]);
            return 1;
        }

        if (majorMarks[i] < 0.0 || majorMarks[i] > 60.0)
        {
            fprintf(stderr, "Invalid Major Marks: %.2f\n", majorMarks[i]);
            return -1;
        }
    }

    for (int i = 0; i < SUBS_COUNT; i++)
    {
        if (minorMarks[i] + majorMarks[i] > 100.0)
        {
            fprintf(stderr, "Invalid Total Marks: %.2f\n", minorMarks[i] + majorMarks[i]);
            return 2;
        }
    }

    return 0;
}