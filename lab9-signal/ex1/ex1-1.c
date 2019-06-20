#include <stdio.h>
#include <unistd.h>

int main(){
	pid_t new_pid;

	new_pid = fork();
	if(new_pid<0){
		printf("error\n");
		return 0;
	}else if(new_pid==0){
		printf("Child process\n");
		printf("Pid: %d\t, Parent pid: %d\n", getpid(), getppid());
		while(1){;}
	}

	wait(NULL);
	printf("Parent process\n");
	printf("Pid: %d\t, Child pid: %d\n", getpid(), new_pid);
	
	return 0;
}