#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
bool hasSeqLenN(long long id, int seq_len) // 93093093, 3
{
    long long sequence;
    long long base = pow(10, seq_len); // 1000

    long long ref_seq = id % base;
    if (ref_seq < pow(10, seq_len - 1))
    {
        return false;
    }
    if ((int)ceil(log10(id)) % seq_len != 0 ){
        return false;
    }
    long long idcpy = id;
    while (id != 0)
    {
        sequence = id % base;
        if (sequence != ref_seq)
        {
            return false;
        }
        id = id / base;
    }
    return true;
}

bool isInvalid(long long id)
{
    long long oom = ceil(log10(id));

    // oom = 2 -> 2 digits
    // idea for advanced puzzle: iterate over possible sequence lengths, then "chop them off" starting from the right side and check if remaining number has correct sequence at the end.
    for (int seq_len = 1; seq_len <= oom / 2; seq_len++)
    {
        if (hasSeqLenN(id, seq_len))
        {
            return true;
        }
    }
    return false;
}

long long main()
{
    FILE *fptr = fopen("puzzle_input.txt", "r");
    char *line = NULL;
    size_t bufsize = 0;
    getline(&line, &bufsize, fptr);
    char *range = strtok(line, ",");
    long long sum = 0;
    while (range != NULL)
    {
        long long start, end;
        sscanf(range, "%lli-%lli", &start, &end);
        if (start < 0 || end < 0)
        {
            printf("Something went wrong: %lli, %lli\n", start, end);
        }
        for (long long id = start; id <= end; id++)
        {
            if (isInvalid(id))
            {
                sum += id;
            }
        }
        range = strtok(NULL, ",");
    }
    printf("Sum: %lli\n", sum);
    return 0;
}