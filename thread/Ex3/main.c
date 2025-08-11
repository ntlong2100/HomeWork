#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>


int data = 0;
bool data_ready = false;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void *threadProducer(void *arg){

	
	for(int i = 0 ; i < 10; i++){
		printf("producer %d\n", i);
		pthread_mutex_lock(&mutex);
		
		data = rand();
		data_ready = true;
		
		pthread_cond_signal(&cond);
		
		pthread_mutex_unlock(&mutex);
		usleep(100);
	}
	return NULL;
}

void *threadConsumer(void *arg){
	for(int i = 0 ; i < 10; i++){
		printf("consumer %d\n", i);
		pthread_mutex_lock(&mutex);
		
		while(!data_ready){
			printf("waiting data ready!!!\n");
			pthread_cond_wait(&cond, &mutex);
		}
		
		printf("data = %d\n", data);
		data_ready = false;
		
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}

int main(){

	pthread_t pro, con;
	
	if(pthread_create(&pro, NULL, threadProducer, NULL) != 0){
		perror("pthread_create producer");
		exit(1);
	}
	
	if(pthread_create(&con, NULL, threadConsumer, NULL) != 0){
		perror("pthread_create consumer");
		exit(1);
	}
	
	pthread_join(pro, NULL);
	pthread_join(con, NULL);
	
	return 0;
}
