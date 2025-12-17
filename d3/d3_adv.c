#include <stdio.h>
#include <stdlib.h>

long long unsigned int evalDigits(int digits[]){
    long long unsigned int result = 0;
    long long unsigned int mult = 1;
    for(int idx = 0; idx < 12; idx++){
        result += mult * digits[11 - idx];
        mult *= 10;
    }
    return result;
}

long long unsigned int process_line(char *line, int lineLength)
{
    int digits[lineLength];
    int numDigits = lineLength;
    int pickedDigits[12];
    for (int idx = 0; idx < lineLength; idx++)
    {
        digits[idx] = line[idx] - '0';
    }
    int lastPicked = -1; //where was the last element picked?
    for (int remainingDigits = 12; remainingDigits > 0; remainingDigits--)
    {
        //check valid places for earliest occurence of largest number
        int max = -1;
        int startIdx = lastPicked + 1;
        int endIdx = lineLength - remainingDigits;
        for(int idx = startIdx; idx <= endIdx; idx ++){
            if(digits[idx] > max){
                lastPicked = idx;
                max = digits[idx];
            }
            if(max == 9){
                break; //doesn't get better than a 9
            }
        }
        pickedDigits[12 - remainingDigits] = max;
    }
    
    return evalDigits(pickedDigits);

}

long long unsigned int process_file(char fileName[])
{
    FILE *fptr = fopen(fileName, "r");
    long long unsigned int result = 0;
    char *line = NULL;
    size_t bufsize = 0;
    while (!feof(fptr))
    {
        int lineLength = getline(&line, &bufsize, fptr) - 1;
        if (lineLength <= 1){
            fclose(fptr);
            return result;
        }
        unsigned long long int lineResult = process_line(line, lineLength);
        result += lineResult;
    }
}

long long unsigned int main()
{
    char input[] = "puzzle_input.txt";
    long long unsigned int sampleResult = 3121910778619; // change
    long long unsigned int result = process_file("sample_input.txt");

    if (result == sampleResult)
    {
        printf("Correctly processed sample inputs, proceeding with puzzle inputs\n");
        result = process_file("puzzle_input.txt");
        printf("Puzzle result: %llu\n", result);
    }
    else
    {
        printf("Wrong result on sample inputs (got %llu, should be %llu), Skipping puzzle inputs.\n", result, sampleResult);
    }
    return 0;
}
