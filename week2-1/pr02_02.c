#include <stdlib.h>
#include <stdio.h>
extern int subnum(int a, int b);
int main(int argc,char* argv[]) {
    if (argc < 1) {
        printf("Usage: %s num1 num2\n", argv[0]);
        return 1;
    }
    int result=0;
    result = subnum(atoi(argv[1]),atoi(argv[2]) );
    printf("%d - %d = %d\n",atoi(argv[1]), atoi(argv[2]), result); 
}
