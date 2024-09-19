#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int *ptr = calloc(1, sizeof(int));
    *ptr = 100;
    
    *ptr = 110;
    printf("%d\n", *ptr);
    free(ptr);
}
