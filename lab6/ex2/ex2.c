#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(){
	//create B
	if (fork() == 0){
		//create C
		if(fork() == 0){
			printf("I am child process C. \n");
			printf("PID: %d\tParent PID:%d\n", getpid(), getppid());
			return 0;
		}
		wait(NULL);
		printf("I am child process B. \n");
		printf("PID: %d\tParent PID:%d\n", getpid(), getppid());
		return 0;
	}
	wait(NULL);
	//create D
	if (fork() == 0){
		printf("I am child process D. \n");
		printf("PID: %d\tParent PID:%d\n", getpid(), getppid());
		return 0;
	}
	wait(NULL);
	//create E
	if(fork() == 0){
		printf("I am child process E. \n");
		printf("PID: %d\tParent PID:%d\n", getpid(), getppid());
		return 0;
	}
	wait(NULL);
	//create A
	printf("I am parent process A. \n");
	printf("PID:%d\tParent PID:%d\n", getpid(), getppid());
	return 0;
}
