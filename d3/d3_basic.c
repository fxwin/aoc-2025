#include <stdio.h>

int process_line(char *line, int lineLength)
{
    int tens = 0;
    int ones = 0;
    for (int i = 0; i < lineLength-1; i++)
    {
        
        if (line[i] - '0' <= tens)
        {
            continue;
        }
        else
        {
            tens = line[i] - '0';
            ones = 0;
            for (int j = i+1; j < lineLength; j++)
            {
                if (line[j] - '0' <= ones){
                    continue;
                } else {
                    ones = line[j] - '0';
                }
            }
        }

        if(tens == 9 && ones == 9){ //early stopping if maximum found
            break;
        }
    }
    return tens*10 + ones;
}

int process_file(char fileName[])
{
    FILE *fptr = fopen(fileName, "r");
    int result = 0;
    char *line = NULL;
    size_t bufsize = 0;
    while (!feof(fptr))
    {
        int lineLength = getline(&line, &bufsize, fptr)-1;
        result += process_line(line, lineLength);
    }
    fclose(fptr);
    return result;
}

int main()
{
    char input[] = "puzzle_input.txt";
    int sampleResult = 357; // change
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
    return 0;
}
