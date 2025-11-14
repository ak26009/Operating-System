#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include<string.h>

pid_t id;
  
int main(){

  int fd[2];
  int fd1[2];
  
  pipe(fd);
  pipe(fd1);
  id = fork();
  
  char msg[] = "hi i am atharva\n";
  char buff[100];
  char msg2[] = "hi i am sai\n";
  char buff2[100];
  
  
  if(id >0){
  
    close(fd[0]);
    write(fd[1],msg,sizeof(msg));
    close(fd[1]);
    printf("SENDing msg to child:\n");
    sleep(3);
    close(fd1[1]);
    read(fd1[0],buff2,sizeof(buff2));
    close(fd1[0]);
    printf("received from child:%s\n",buff2);
  }
  else{
    
      close(fd[1]);
      read(fd[0],buff,sizeof(buff));
      close(fd[0]);
      printf("received:%s\n",buff);
      close(fd1[0]);
      
      write(fd1[1],msg2,sizeof(msg2));
      close(fd1[1]);
      printf("msg send\n");
  }
  return 0;
}
