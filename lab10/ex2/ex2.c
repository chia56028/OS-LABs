#include <semaphore.h>
#include <pthread.h>
#include <stdio.h>

sem_t fill;
sem_t empty;
sem_t mutex;

int count=0;
void producer(void);
void comsumer(void);

int main(void){
	sem_init(&fill, 0, 0);
	sem_init(&empty, 0, 5);
	sem_init(&mutex, 0, 1);
	
	pthread_t pro[10], com[10];
	int i=0;
	for(i=0; i<10; i++){
		pthread_create(&pro[i], NULL, (void*)producer, NULL);
	}
	for(i=0; i<10; i++){
		pthread_create(&com[i], NULL, (void*)comsumer, NULL);
	}

	pthread_exit(NULL);
}

void producer(void){
	sem_wait(&empty);
	sem_wait(&mutex);
	count++;
	printf("Item count:%d\n", count);
	sem_post(&mutex);
	sem_post(&fill);
	pthread_exit(NULL);
}

void comsumer(void){
	int i=0;
	sem_wait(&fill);
	sem_wait(&mutex);
	count--;
	printf("Item count:%d\n", count);
	sem_post(&mutex);
	sem_post(&empty);
	pthread_exit(NULL);
}