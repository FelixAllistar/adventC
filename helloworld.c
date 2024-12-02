#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array;
    int size;

    // Ask the user for the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Allocate memory for the array
    array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Initialize and print the array
    for (int i = 0; i < size; i++) {
        array[i] = i + 1;
        printf("%d ", array[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(array);

    return 0;
}

