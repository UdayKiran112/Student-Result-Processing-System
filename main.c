#include "student.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "r");

    if (input == NULL)
    {
        fprintf(stderr, "Input file error\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");

    if (output == NULL)
    {
        fprintf(stderr, "Output file error\n");
        fclose(input);
        return 1;
    }

    return 0;
}