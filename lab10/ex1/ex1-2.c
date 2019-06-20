#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>

sem_t sem;
int count=0;
void inc(void);
void dec(void);

int main(void){
	sem_init(&sem, 0, 1);
	
	pthread_t id[4];
	pthread_create(&id[0], NULL, (void*)dec, NULL);
	pthread_create(&id[1], NULL, (void*)inc, NULL);
	pthread_create(&id[2], NULL, (void*)dec, NULL);
	pthread_create(&id[3], NULL, (void*)inc, NULL);

	int i=0;
	for(i=0; i<4; i++){

		pthread_join(id[i], NULL);
	}
	printf("\noutput is %d\n", count);
	pthread_exit(NULL);
}

void inc(void){
	int i=0;
	sem_wait(&sem);
	for(i=0; i<25000000; i++){
		count++;
	}
	sem_post(&sem);
	pthread_exit(NULL);
}

void dec(void){
	int i=0;
	sem_wait(&sem);
	for(i=0; i<25000000; i++){
		count--;
	}
	sem_post(&sem);
	pthread_exit(NULL);
}