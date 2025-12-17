#include <stdio.h>
#include <stdlib.h>

int main(){
    int old = 50;
    int zeroes = 0;
    FILE* fptr = fopen("input.txt", "r");
    char *line = NULL;
    size_t bufsize = 0;
    while (!feof(fptr)){
        getline(&line, &bufsize, fptr);
        char dirChar = 0;
        int amount = 0;
        int zero_crossings = 0;
        sscanf(line, "%c%d", &dirChar, &amount);
        int dir = dirChar == 'R' ? 1 : -1;
        int new = old + dir * amount;
        zero_crossings = abs(new) / 100; //total distance from 0 implies minimum amount of 0-crossings 
        if(new * old <= 0){ 
            zero_crossings += 1; // different signs mean we crossed one more time than the total suggests
        }
        if(old == 0){
            zero_crossings -= 1; // needed in case we end/start exactly on 0, otherwise this 0 is counted twice due to the first if-statement 
        }
        zeroes += zero_crossings;
        old = new % 100;

    }
    printf("Zero count: %i\n", zeroes);
}
