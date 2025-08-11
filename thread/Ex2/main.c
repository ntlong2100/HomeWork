#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>


long long counter = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *threadFunc1 (void *arg){
	pthread_mutex_lock(&mutex);
	for(int i = 0; i < 1000000; i++){
		//printf("thread id: %lld, counter: %ld\n", pthread_self(), (counter++));
		counter++;
	}
	pthread_mutex_unlock(&mutex);
	return NULL;
}

void *threadFunc2 (void *arg){
	pthread_mutex_lock(&mutex);
	for(int i = 0; i < 1000000; i++){
		//printf("thread id: %ld, counter: %lld\n", pthread_self(), (counter++));
		counter++;
	}
	pthread_mutex_unlock(&mutex);
	return NULL;
}

void *threadFunc3 (void *arg){
	pthread_mutex_lock(&mutex);
	for(int i = 0; i < 1000000; i++){
		//printf("thread id: %ld, counter: %lld\n", pthread_self(), (counter++));
		counter++;
	}
	pthread_mutex_unlock(&mutex);
	return NULL;
}

int main(){

	pthread_t t1, t2, t3;
	if(pthread_create(&t1, NULL, threadFunc1, NULL) != 0){
		perror("pthread_create t1");
		exit(1);
	}
	
	if(pthread_create(&t2, NULL, threadFunc2, NULL) != 0){
		perror("pthread_create t2");
		exit(1);
	}
	
	if(pthread_create(&t3, NULL, threadFunc3, NULL) != 0){
		perror("pthread_create t3");
		exit(1);
	}
	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);
	
	printf("counter = %lld\n", counter);

	return 0;
}
