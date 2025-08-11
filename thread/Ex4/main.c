#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>


pthread_rwlock_t rw = PTHREAD_RWLOCK_INITIALIZER;
int data = 0;

void* ReaderFunc(void* arg){
	
	pthread_rwlock_rdlock(&rw);
	printf("Reader thread (id = %ld): %d\n", pthread_self(), data);
	sleep(3);
	pthread_rwlock_unlock(&rw);
	return NULL;
}

void *WriterFunc(void *arg){
	pthread_rwlock_wrlock(&rw);
	data++;
	printf("Writer thread (id = %ld): %d\n", pthread_self(), data);
	pthread_rwlock_unlock(&rw);
	return NULL;
}

int main(){

	pthread_t rd1, rd2, rd3, rd4, rd5, wr1, wr2;
	
	if(pthread_create(&rd1, NULL, ReaderFunc, NULL) != 0){
		perror("pthread_create rd1");
		exit(1);
	}
	if(pthread_create(&rd2, NULL, ReaderFunc, NULL) != 0){
		perror("pthread_create rd2");
		exit(1);
	}
	if(pthread_create(&rd3, NULL, ReaderFunc, NULL) != 0){
		perror("pthread_create rd3");
		exit(1);
	}
	if(pthread_create(&rd4, NULL, ReaderFunc, NULL) != 0){
		perror("pthread_create rd4");
		exit(1);
	}
	if(pthread_create(&rd5, NULL, ReaderFunc, NULL) != 0){
		perror("pthread_create rd5");
		exit(1);
	}
	
	if(pthread_create(&wr1, NULL, WriterFunc, NULL) != 0){
		perror("pthread_create wr1");
		exit(1);
	}
	if(pthread_create(&wr2, NULL, WriterFunc, NULL) != 0){
		perror("pthread_create wr2");
		exit(1);
	}
	
	pthread_join(rd1, NULL);
	pthread_join(rd2, NULL);
	pthread_join(rd3, NULL);
	pthread_join(rd4, NULL);
	pthread_join(rd5, NULL);
	
	pthread_join(wr1, NULL);
	pthread_join(wr2, NULL);

	return 0;
}
