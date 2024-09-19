#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void help() { printf("./pr03_04.out [option] int m int n\n"); }
int gcd(int m, int n) { 
    while (n != 0) {
        int temp = n;
        n = m % n;
        m = temp;
    }
    return m;
}
int lcm(int m, int n) { 
    return (m * n) / gcd(m, n);
}

int main(int argc, char *argv[]) {
    int n,m;
    extern char *optarg;
    extern int optind;
    if (argc != 1) {
        while ((n = getopt(argc, argv, "g:n:t:p:")) != -1) {
            switch (n) {
                case 'g':
                    m = atoi(argv[optind - 1]);
                    n = atoi(argv[optind]);
	 	            printf("%d\n",gcd(m,n));
                    break;
                 case 'n':
                     m = atoi(argv[optind - 1]);                       
                     n = atoi(argv[optind]);
                     printf("%d\n",lcm(m,n));
                     break;
                case 't':
                    m = atoi(argv[optind - 1]);
                    n = atoi(argv[optind]);
                    printf("%d\n",m*n);
                    break;
                case 'p':
                    m = atoi(argv[optind - 1]);
                    n = atoi(argv[optind]);
        	 	    printf("%d\n",m+n);
                    break;         
                default:
                    help();
                    break;
            }
        }
    }
}


