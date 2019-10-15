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
   
    srand((unsigned int)getpid());
   
    shmid = shmget((key_t)1234,sizeof(struct shared_use_st),0666|IPC_CREAT);
    shared_memory = shmat(shmid,(void *) 0,0);
   
    shared_stuff = (struct shared_use_st *)shared_memory;
    shared_stuff->written_by_you = 0;
   
    while(running){
        if (shared_stuff->written_by_you){
            printf("You wrote:%s",shared_stuff->some_text);
            sleep(rand()%4);
            shared_stuff->written_by_you = 0;
           
            if (strncmp(shared_stuff ->some_text,"exit\n",3) == 0){
                running =0;
            }
        }
    }    
    exit(EXIT_SUCCESS);
}
