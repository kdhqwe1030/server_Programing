#include <stdio.h>
int main() {
    
    char str[] = "ServerProgramming";
    *(str + 1) = 'i';
    *(str + 2) = 'l';
    printf("%s\n", str);
}
