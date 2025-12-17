#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

bool isValid(long id){
    long oom = ceil(log10(id));
    if(oom % 2 != 0){
        return false;
    }
    // oom = 2 -> 2 digits
    oom /= 2;
    long tmp = pow(10, oom);
    long right = id % tmp;
    long left = id / tmp;
    return right == left;

}

long main() {
    FILE *fptr = fopen("puzzle_input.txt", "r");
    char* line = NULL;
    size_t bufsize = 0;
    getline(&line, &bufsize, fptr);
    char *range = strtok(line, ",");
    long sum = 0;
    while(range != NULL){
        long start, end;
        sscanf(range, "%li-%li", &start, &end);
        if(start < 0 || end < 0){ 
            printf("Something went wrong: %li, %li\n", start, end);
        }
        for(long id=start; id <= end; id++){
            if(isValid(id)){
                sum += id;
            }
        }
        range = strtok(NULL, ",");
    }
    printf("Sum: %li\n", sum);
    return 0;
}