#include "parser.h"

int main(int argc, char *argv[])
{

    if (argc != 4)
    {
        fprintf(stderr, "Usage: %s <count_no_of_students> <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    int studentCount = atoi(argv[1]); // Number of students N

    FILE *input = fopen(argv[2], "r");
    if (input == NULL)
    {
        fprintf(stderr, "Input file error\n");
        return 1;
    }

    FILE *output = fopen(argv[3], "w");

    if (output == NULL)
    {
        fprintf(stderr, "Output file error\n");
        fclose(input);
        return 1;
    }

    parse_input(studentCount, input, output);

    fclose(input);
    fclose(output);

    return 0;
}