#include <stdio.h>
#include <time.h>
int process_file(char fileName[])
{
    FILE *fptr = fopen(fileName, "r");
    int result = 0;
    char *line = NULL;
    size_t bufsize = 0;
    getline(&line, &bufsize, fptr);
    // IMPLEMENT

    fclose(fptr);
    return result;
}

int main()
{
    clock_t start = clock();
    char input[] = "puzzle_input.txt";
    int sampleResult = 3; // change
    int result = process_file("sample_input.txt");

    if (result == sampleResult)
    {
        printf("Correctly processed sample inputs, proceeding with puzzle inputs\n");
        result = process_file("puzzle_input.txt");
        printf("Puzzle result: %i\n", result);
    }
    else
    {
        printf("Wrong result on sample inputs (got %i, should be %i), Skipping puzzle inputs.\n", result, sampleResult);
    }
    clock_t end = clock();
    printf("Time: %f seconds\n", ((float)(end-start))/CLOCKS_PER_SEC);
    return 0;
}