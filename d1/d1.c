#include <stdio.h>

int main()
{
    int dial = 50;
    int zero_count = 0;
    FILE *fptr = fopen("puzzle_input.txt", "r");
    char *line = NULL;
    size_t bufsize = 0;

    while (!feof(fptr))
    {
        getline(&line, &bufsize, fptr);
        int dir = -1; // left
        if (line[0] == 'R')
        {
            dir = 1; // right
        }
        int hundreds = line[1] - '0';
        int tens = line[2] - '0';
        int ones = line[3] - '0';
        if (tens < 0)
        {
            ones = hundreds;
            tens = 0;
            hundreds = 0;
        }
        if (ones < 0){
            ones = tens;
            tens = hundreds;
            hundreds = 0;
        }


        int value = hundreds * 100 + tens * 10 + ones;
        dial += dir * (tens * 10 + ones);
        dial = dial % 100;
        if (dial == 0)
        {
            zero_count++;
        }
        printf("%s\n", line);
    }
    printf("Zero count: %i\n", zero_count);
    return 0;
    // mod 100
}