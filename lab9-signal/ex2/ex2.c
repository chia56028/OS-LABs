#include <stdio.h>
#include <unistd.h>
#include <signal.h>

struct sigaction newact;

void catch_int(int sig_num){
	signal(SIGINT, catch_int);
	printf("How are you\n");
}
void catch_int_2(int sig_num){
	signal(SIGINT, catch_int_2);
	printf("I am fine\n");
}

void catch_alarm_2(){
	sigaction(SIGINT, &newact, NULL);
}

void catch_alarm(){
	signal(SIGINT, catch_int_2);
	signal(SIGALRM, catch_alarm_2);
	alarm(3);
}

int main(int argc, char const *argv[])
{
	sigaction(SIGINT, NULL, &newact);

	signal(SIGINT, catch_int);
	signal(SIGALRM, catch_alarm);

	alarm(3);

	for(;;)
		pause();

	return 0;
}