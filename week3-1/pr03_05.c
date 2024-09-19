#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int count_vowel(char *str) {
    int result = 0;
    char ch;

    
    for (int i = 0; str[i] != '\0'; i++) {
        ch = tolower(str[i]);  
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            result++;
        }
    }
    return result;
}
int main() {
    int n;
    int result=0;
    printf(">> ");
    scanf("%d", &n);

    char **strings = calloc(n, sizeof(char *));
    for (int i = 0; i < n; ++i) {
        strings[i] = calloc(20, sizeof(char));
        scanf("%s", strings[i]);
    }

    for (int i = 0; i < n; ++i) {
        result += count_vowel(strings[i]); 
    }
    printf(">> %d\n",result);
    for (int i = 0; i < n; ++i) {
        free(strings[i]);
    }
    free(strings);
}
