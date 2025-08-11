#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>


void * threadFunc1(void *arg){

	printf("Thread with ID = %ld is running\n", pthread_self());
	return NULL;
}

void * threadFunc2(void *arg){

	printf("Thread with ID = %ld is running\n", pthread_self());
	{{pthread_exit(NULL);}}
	return NULL; //not call
}


int main(){

	pthread_t t1, t2;
	
	int r1, r2;
	
	if(pthread_create(&t1, NULL, threadFunc1, NULL) != 0){
		perror("pthread_create t1\n");
        	exit(EXIT_FAILURE);
	}
	if(pthread_create(&t2, NULL, threadFunc2, NULL) != 0){
		perror("pthread_create t2\n");
        	exit(EXIT_FAILURE);
	}
	
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	
	printf("main thread end!!!\n");
	return 0;
}

