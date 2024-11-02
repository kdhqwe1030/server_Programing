#include <sys/types.h>
#include <sys/times.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, fd;
    struct tms buf;
    clock_t t1, t2;
    double  user_time, system_time;
    long clk_tck = sysconf(_SC_CLK_TCK);
    char *data = "a\n";
   
    printf("Clock tick: %ld\n", clk_tck); 
    
    t1 = times(&buf);
    
    for (i = 0; i < 100000; i++) {
        fd = open("input.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);  
        write(fd, data, 2);  
        close(fd);  
    }

   
    t2 = times(&buf);
    
    user_time = (double)buf.tms_utime / clk_tck;
    system_time = (double)buf.tms_stime / clk_tck;

    
    
    printf("User time: %.3f sec\n", user_time);
    printf("System time: %.3f sec\n", system_time);

    return 0;
}

