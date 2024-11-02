#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {  
        char *args[] = {"/bin/date", NULL};
        execve("/bin/date", args, NULL);
        exit(0);  
    }

   else{
   int status;
   while(1){
        pid_t result = waitpid(pid, &status, WNOHANG);
        if(result==pid){
        break;
        
        }
        else sleep(1);
   
   }
   printf("Child Exit Status : %d\n",status);
   
   }



   return 0;
}
