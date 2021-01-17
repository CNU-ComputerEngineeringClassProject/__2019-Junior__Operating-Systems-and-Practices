#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

int count = 0;
int counter = 0;

sem_t semaphore;

void *add1(void *data){

	sem_wait(&semaphore);

	int tmp;
	int i = 0;

	while(i < 5){
		i++;
		count++;
		printf("add1 count= %d\n",count);
		tmp = counter;
		sleep(1);
		tmp=tmp+1;
		counter=tmp;
	}

	sem_post(&semaphore);

}

void *add2(void *data){

	sem_wait(&semaphore);	

	int tmp;
	int i = 0;

	while(i<5){
		i++;
		count++;
		printf("add2 count = %d\n",count);
		tmp = counter;
		sleep(1);
		tmp = tmp +1;
		counter = tmp;
	}
	sem_post(&semaphore);
}

void *add3(void *data){

	sem_wait(&semaphore);
	int tmp;
	int i=0;

	while(i<5){
	i++;
	count++;
	printf("add3 count = %d\n",count);
	tmp = counter;
	sleep(1);
	tmp = tmp+1;
	counter =tmp;
	}
	sem_post(&semaphore);
}

void *sub1(void *data){
 
	sem_wait(&semaphore);
	int tmp;
	int i=0;

	while(i<5){
	i++;
	count--;
	printf("sub1 count = %d\n",count);
	tmp = counter;
	sleep(1);
	tmp = tmp-1;
	counter = tmp;
	}
	sem_post(&semaphore);
}

void *sub2(void *data){

	sem_wait(&semaphore);
	int tmp;
	int i=0;
	
	while(i<5){
	i++;
	count--;
	printf("sub2 count = %d\n",count);
	tmp = counter;
	sleep(1);
	tmp = tmp-1;
	counter = tmp;
	}
	sem_post(&semaphore);
}
void *sub3(void *data){

	sem_wait(&semaphore);
	int tmp;
	int i=0;

	while(i<5){
	i++;
	count--;
	printf("sub3 count = %d\n",count);
	tmp = counter;
	sleep(1);
	tmp = tmp-1;
	counter = tmp;
	}
	sem_post(&semaphore);
}

int main(){
	int i=0;
	pthread_t pthread[6];

	sem_init(&semaphore, 0, 1);
	pthread_create(&pthread[0],NULL,add1,NULL);
	pthread_create(&pthread[1],NULL,sub1,NULL);
	pthread_create(&pthread[2],NULL,add2,NULL);
	pthread_create(&pthread[3],NULL,sub2,NULL);
	pthread_create(&pthread[4],NULL,add3,NULL);
	pthread_create(&pthread[5],NULL,sub3,NULL);

	for(i=0;i<6;i++)
		pthread_join(pthread[i],NULL);
	sem_destroy(&semaphore);
	return 0;
}
