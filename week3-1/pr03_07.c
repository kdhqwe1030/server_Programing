#include <stdio.h>
#include <stdlib.h>
int main() {
    int size = 5;
    int *array = calloc(size, sizeof(int));
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 10;
    }

    while (*array) {
        printf("%d\n", *array++);
    }

    printf("The first value: %d\n", *(array - size));
    free((array - size));
}
