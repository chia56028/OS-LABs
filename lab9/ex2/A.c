#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "msg_que.h"

int msqid, msqid_1;
struct oslab_msg_st msg_buffer;

void *send(){
	key_t key = 0x1234;
	msqid = msgget(key, IPC_CREAT | 0666);

	while(1){
		printf("Enter some text: ");
		fgets(msg_buffer.msg_text,sizeof(msg_buffer.msg_text), stdin);
		msg_buffer.oslab_msg_type = 20;
		// send a message
		msgsnd(msqid, (void *) &msg_buffer, sizeof(msg_buffer)-sizeof(long int), 0);

		if(!strcmp(msg_buffer.msg_text, "exit\n")){
			return 0;
		}		
	}
	pthread_exit(NULL);
}

void *recieve(){
	key_t key = 0x1234;
	msqid_1 = msgget(key, IPC_CREAT | 0666);

	while(1){
		msgrcv(msqid_1, (void *) &msg_buffer, sizeof(msg_buffer)-sizeof(long int),10, 0);
		printf("Received: %s",msg_buffer.msg_text);
		
		if(!strcmp(msg_buffer.msg_text, "exit\n")){
			return 0;
		}
		// else{
		// 	printf("%s",msg_buffer.msg_text);
		// }
	}
	pthread_exit(NULL);
}

int main(){
	pthread_t thread0,thread1;
	int rc0, rc1;
	rc0 = pthread_create(&thread0,NULL,send,(void *)1);
	rc1 = pthread_create(&thread1,NULL,recieve,(void *)2);
	rc0 = pthread_join(thread0,NULL);
	rc1 = pthread_join(thread1,NULL);
	
	return 0;
}