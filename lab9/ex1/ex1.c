#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int count = 0;

void *PrintHello (void *arg){
	printf("This is Thread %d\n",(int)arg);
	printf("Thread ID: %lu\n", pthread_self());
	// printf("Argument: %d\n", (int)arg);
	int i=0;
	for(i=0; i<25000000; i++) count++;
	pthread_exit(NULL);
}

int main(){
	pthread_t thread0,thread1,thread2,thread3;
	int rc0, rc1, rc2, rc3, t=100;
	rc0 = pthread_create(&thread0,NULL,PrintHello,(void *)1);
	rc1 = pthread_create(&thread1,NULL,PrintHello,(void *)2);
	rc2 = pthread_create(&thread2,NULL,PrintHello,(void *)3);
	rc3 = pthread_create(&thread3,NULL,PrintHello,(void *)4);
	if(rc0){
		printf("Error; %d\n", rc0);
		exit(-1);
	}
	if(rc1){
		printf("Error; %d\n", rc1);
		exit(-1);
	}
	if(rc2){
		printf("Error; %d\n", rc2);
		exit(-1);
	}
	if(rc3){
		printf("Error; %d\n", rc3);
		exit(-1);
	}
	rc0 = pthread_join(thread0,NULL);
	rc1 = pthread_join(thread1,NULL);
	rc2 = pthread_join(thread2,NULL);
	rc3 = pthread_join(thread3,NULL);
	if(rc0){
		printf("Error0; %d\n", rc0);
		exit(-1);
	}
	if(rc1){
		printf("Error1; %d\n", rc1);
		exit(-1);
	}
	if(rc2){
		printf("Error2; %d\n", rc2);
		exit(-1);
	}
	if(rc3){
		printf("Error3; %d\n", rc3);
		exit(-1);
	}
	printf("count: %d\n", count);
	return 0;
}