#include <stdio.h>

int main(){
    int dial = 50;
    int zeroes = 0;
    FILE* fptr = fopen("input.txt", "r");
    char *line = NULL;
    size_t bufsize = 0;
    while (!feof(fptr)){
        getline(&line, &bufsize, fptr);
        char dirChar = 0;
        int amount = 0;
        sscanf(line, "%c%d", &dirChar, &amount);
        int dir = dirChar == 'R' ? 1 : -1;
        dial += dir * amount;
        dial = dial % 100;
        if (dial == 0){
            zeroes++;
        }
    }
    printf("Zero count: %i\n", zeroes);
}