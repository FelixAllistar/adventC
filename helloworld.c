#include <stdio.h>

void main() {
    int input;
    int temp = 0;

    while ((input = getchar()) != EOF) {
        printf("Processing character: '%c'\n", input); // Debugging output
        if (input == ' ') {
            if (!temp) {
                temp = 1;
                putchar(input); // Output the first space
            }
        } else {
            temp = 0;
            putchar(input); // Output non-space characters
        }
    }
}


