#include <stdio.h>
int main() {
    int dial = 50;
    int zero_count = 0;
    // const char *inputs[] = {"L68", "L30", "R48", "L5", "R60", "L55", "L1", "L99", "R14", "L82"};
    FILE * fptr = fopen("input.txt", "r");
    char *buffer = NULL;
    size_t bufsize = 32;
    size_t characters;

    characters = getline(&buffer, &bufsize, fptr);
    printf("%s", buffer);
    characters = getline(&buffer, &bufsize, fptr);
    printf("%s", buffer);
    characters = getline(&buffer, &bufsize, fptr);
    printf("%s", buffer);
    characters = getline(&buffer, &bufsize, fptr);
    printf("%c", buffer[0]);
    
    return 0;
    
}

// L5
// L37
// L32
// R5
// L36
// L29
// R13
// R17
// L19
// L34
// R2