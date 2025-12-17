#include <stdio.h>

int process_file(char fileName[])
{
    FILE *fptr = fopen(fileName, "r");
    char *line = NULL;
    int height = 3;
    size_t bufsize = 0;

    int width = getline(&line, &bufsize, fptr) + 1;
    while (getline(&line, &bufsize, fptr) > 1)
    {
        height++;
    }
    // IMPLEMENT
    fclose(fptr);
    // assemble grid
    char grid[height][width];
    for (int y = 0; y < height; y++)
    {
        grid[y][0] = '.';
        grid[y][width - 1] = '.';
    }

    for (int x = 0; x < width; x++)
    {
        grid[0][x] = '.';
        grid[height - 1][x] = '.';
    }

    // fill in with input

    FILE *fptr2 = fopen(fileName, "r");
    int rowIdx = 1;
    while (!feof(fptr2))
    {
        int lineLength = getline(&line, &bufsize, fptr2);
        if (lineLength <= 1)
        {
            break;
        }
        for (int colIdx = 1; colIdx < width - 1; colIdx++)
        {
            grid[rowIdx][colIdx] = line[colIdx - 1];
        }
        rowIdx++;
    }
    fclose(fptr2);
    // process grid
    int numRolls = 0;
    for (int row = 1; row < height - 1; row++)
    {
        for (int col = 1; col < width - 1; col++)
        {
            if (grid[row][col] == '.')
            {
                continue;
            }
            else
            {
                int numRollsAdj = 0;
                if (grid[row - 1][col - 1] == '@')
                {
                    numRollsAdj++;
                }
                if (grid[row - 1][col] == '@')
                {
                    numRollsAdj++;
                }
                if (grid[row - 1][col + 1] == '@')
                {
                    numRollsAdj++;
                }
                if (grid[row][col - 1] == '@')
                {
                    numRollsAdj++;
                }
                if (grid[row][col + 1] == '@')
                {
                    numRollsAdj++;
                }
                if (grid[row + 1][col - 1] == '@')
                {
                    numRollsAdj++;
                }
                if (grid[row + 1][col] == '@')
                {
                    numRollsAdj++;
                }
                if (grid[row + 1][col + 1] == '@')
                {
                    numRollsAdj++;
                }
                if (numRollsAdj < 4)
                {
                    numRolls++;
                }
            }
        }
    }

    return numRolls;
}

int main()
{
    char input[] = "puzzle_input.txt";
    int sampleResult = 13; // change
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
