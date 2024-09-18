#include <stdio.h>
#include <stdlib.h>

extern int addnums(int *nums, int n);


int main(int argc,char *argv[]){
    int n=atoi(argv[1]);
    int m=atoi(argv[2]);
    
    int *nums=(int *)malloc(sizeof(int)*n);
    int *ptr=nums;

    for (int i = 0; i < n; i++) {
        nums[i] = i + 1;
    }
    printf("%d",addnums(nums,n));

    free(nums);

nums = (int *)malloc(sizeof(int) * m);
    

    for (int i = 0; i < m; i++) {
        nums[i] = n + i + 1; 
    }

    printf(" %d\n",addnums(nums,m));

    free(nums);
    return 0;
}
