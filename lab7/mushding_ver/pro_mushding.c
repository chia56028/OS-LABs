#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define TEXT_SZ 2048
   
struct shared_use_st{
    int written_by_you;
    char some_text[TEXT_SZ];
};

int main(){
    int running = 1;
    int shmid;
    void *shared_memory=(void *) 0;
    struct shared_use_st *shared_stuff;
   
    char buffer[BUFSIZ];
   
    shmid = shmget((key_t)1234,sizeof(struct shared_use_st),0666|IPC_CREAT);
    shared_memory = shmat(shmid,(void *) 0,0);
    shared_stuff = (struct shared_use_st *)shared_memory;
   
    while(running){
       
        printf("Enter some text: ");
        fgets(buffer,BUFSIZ,stdin);
       
        strncpy(shared_stuff->some_text,buffer,TEXT_SZ);
        shared_stuff->written_by_you =1;
       
        if (strncmp(buffer,"exit\n",3) == 0){
            running = 0;
        }
    }
   
    exit(EXIT_SUCCESS);
}