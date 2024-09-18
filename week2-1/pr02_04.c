#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    int n;
    char *user = getenv("USER");
    if(argc==1)
        printf("Available Options:\n[p Welcome to Linux Server P    rogramming!]\n[n Nice to meet you, %s]\n[h Help!]\n", optarg);
    

    while ((n = getopt(argc, argv, "pnh")) != -1) {
        switch (n) {
                     
                case 'n':
                if (optind < argc && argv[optind][0] != '-') {
                    printf("Nice to meet you, %s!\n", argv[optind]);
                } else {
                    printf("./pr02_04.out: option requires an argument -- 'n'\n");
                }
                break;
                
            case 'h':
                printf("Available Options:\n[p Welcome to Linux Server Programming!]\n[n Nice to meet you, ???]\n[h Help!]\n");
                break;

            case 'p':
                printf("Welcome to Linux Server Programming!\n");
                break;

            default:
                printf("Available Options:\n[p Welcome to Linux Server Programming!]\n[n Nice to meet you, ???]\n[h Help!]\n");
                break;
        }

    }

    return 0;
}

