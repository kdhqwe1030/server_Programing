#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>


int main(){
  pid_t pid;

  if(pid=fork()){
    system("ls");
  }else{
    system("pwd");
  }
  printf("End of fork\n");
    return 0;
}
