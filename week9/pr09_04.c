#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        printf("--> Child Process\n");   
        execlp("sleep","sleep","5",NULL);
        exit(0);
    }

   else{
       printf("--> Parent process \n");
       
       int status;
       while(1){
            pid_t result = waitpid(pid, &status, WNOHANG);
            printf("Parent still wait\n");
            if(result==pid) break;
            else sleep(1);
       }
   printf("Child Exit Status : %d\n",status);
   
   }    

   return 0;
}
