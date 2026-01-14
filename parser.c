#include "parser.h"

// read data from input file and write to output file
void parse_input(int count, FILE *input, FILE *output)
{
    Student students[count];

    int n = 0;

    char line[256];

    while (n < count && fgets(line, sizeof(line), input) != NULL)
    {
        if (strlen(line) <= 1)
        {
            continue; // skip empty lines
        }

        line[strcspn(line, "\n")] = 0; // Remove newline character

        int idCheck = checkID(line, students, n);

        if (idCheck == -1)
        {
            // Prompt user for correct ID
            fprintf(stderr, "Please enter a valid alphanumeric ID: ");
            fgets(line, sizeof(line), stdin);
            line[strcspn(line, "\n")] = 0; // Remove newline character
            checkID(line, students, n);
        }
        else if (idCheck == 1)
        {
            // Prompt user for unique ID
            fprintf(stderr, "Please enter a unique ID: ");
            fgets(line, sizeof(line), stdin);
            line[strcspn(line, "\n")] = 0; // Remove newline character
            checkID(line, students, n);
        }

        strcpy(students[n].id, line);

        fgets(line, sizeof(line), input);
        line[strcspn(line, "\n")] = 0; // Remove newline character

        int nameCheck = checkName(line);

        if (nameCheck == 1)
        {
            // Prompt user for correct Name
            fprintf(stderr, "Please enter a valid Name (alphabets and spaces only): ");
            fgets(line, sizeof(line), stdin);
            line[strcspn(line, "\n")] = 0; // Remove newline character
            checkName(line);
        }

        strcpy(students[n].name, line);

        for (int i = 0; i < SUBS_COUNT; i++)
        {
            fscanf(input, "%f %f", &students[n].minorScores[i], &students[n].majorScores[i]);

            int marksCheck = checkMarks(students[n].minorScores[i], students[n].majorScores[i]);

            if (marksCheck == 1)
            {
                // Prompt user for correct Minor Marks
                fprintf(stderr, "Please enter a valid Minor Marks for Subject %d: ", i + 1);
                scanf("%f", &students[n].minorScores[i]);
                checkMarks(students[n].minorScores[i], students[n].majorScores[i]);
            }
            else if (marksCheck == -1)
            {
                // Prompt user for correct Major Marks
                fprintf(stderr, "Please enter a valid Major Marks for Subject %d: ", i + 1);
                scanf("%f", &students[n].majorScores[i]);
                checkMarks(students[n].minorScores[i], students[n].majorScores[i]);
            }

            students[n].totalScores[i] = students[n].minorScores[i] + students[n].majorScores[i];
        }

        n++;
    }

    // Calculate total marks, percentage and grade for each student
    for (int i = 0; i < n; i++)
    {
        students[i].totalMarks = calculateTotalMarks(students[i].totalScores);
        students[i].totalPercentage = calculatePercentage(students[i].totalMarks);
        students[i].grade = calculateGrade(students[i].totalPercentage);
    }

    // Test print all data
    for (int i = 0; i < n; i++)
    {
        fprintf(output, "ID: %s\n", students[i].id);
        fprintf(output, "Name: %s\n", students[i].name);
        for (int j = 0; j < SUBS_COUNT; j++)
        {
            fprintf(output, "Subject %d: Minor Marks: %.2f, Major Marks: %.2f, Total Marks: %.2f\n",
                    j + 1,
                    students[i].minorScores[j],
                    students[i].majorScores[j],
                    students[i].totalScores[j]);
        }
        fprintf(output, "Total Marks: %.2f\n", students[i].totalMarks);
        fprintf(output, "Percentage: %.2f\n", students[i].totalPercentage);
        fprintf(output, "Grade: %s\n", gradeToString(students[i].grade));
        fprintf(output, "CGPA: %.2f\n", calculateCGPA(students[i]));
        fprintf(output, "\n");
    }

    // Calculate and print class average percentage
    float classAverage = calculateClassAveragePercentage(students, n);
    fprintf(output, "Class Average Percentage: %.2f\n", classAverage);

    float maxPercentage = findMaxPercentage(students, n);
    fprintf(output, "Highest Percentage in Class: %.2f\n", maxPercentage);

    float minPercentage = findMinPercentage(students, n);
    fprintf(output, "Lowest Percentage in Class: %.2f\n", minPercentage);

    
    
}
