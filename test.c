#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *inputs;
    inputs = fopen("./input.txt", "r");
    
    if (inputs == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char line1[10];  // Increased size to handle larger numbers
    char line2[10];  // Increased size to handle larger numbers

    // Use fscanf to read two strings from the file
    int results = fscanf(inputs, "%s %s", line1, line2);

    // Check if two values were successfully read
    printf("Number of results: %d\n", results);
    if (results == 2) {
        printf("First number: %s\n", line1);
        printf("Second number: %s\n", line2);
    } else {
        printf("Error reading the file.\n");
    }

    fclose(inputs);  // Close the file after use
    return 0;
}

