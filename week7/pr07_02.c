#include <sys/types.h>
#include <sys/times.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    long sum = 0;
    int i;
    struct tms buf;
    clock_t t1, t2;
    double user_time, system_time, real_time;
    long clk_tck = sysconf(_SC_CLK_TCK);

    
        
    t1 = times(&buf);

    for (i = 1; i <= 1000000; i++) {
        sum += i;
        printf("%ld\n", sum);    }

    
    sleep(1);

    t2 = times(&buf);

    
    user_time = (double)buf.tms_utime / clk_tck;
    system_time = (double)buf.tms_stime / clk_tck;
    real_time = (double)(t2 - t1) / clk_tck;

    printf("Clock tick: %ld\n", clk_tck); 
    printf("Real time: %.3f sec\n", real_time);
    printf("User time: %.3f sec\n", user_time);
    printf("System time: %.3f sec\n", system_time);

    return 0;
}

