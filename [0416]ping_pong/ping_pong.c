#include <stdio.h>
#include <pthread.h>

void ping(void);
void pong(void);

int number = 1;
int pingpong = 1;
pthread_mutex_t mutex;

int main()
{


	pthread_t process1, process2;
	pthread_mutex_init(&mutex, NULL);
	
	pthread_create(&process1, NULL, (void*)&ping, NULL);
	pthread_create(&process2, NULL, (void*)&pong, NULL);


	pthread_join(process1, NULL);
	pthread_join(process2, NULL);	

	
}

void ping(void)
{
	int i;

	for(i=0;i<50;i++)
	{	
		pthread_mutex_lock(&mutex);

		if(pingpong == 1)
		{
			printf("%4d - %1d - ping\n", number, i);
			number++;
			pingpong--;	
		}
		else
		{
			i--;
		}
		pthread_mutex_unlock(&mutex);
	}
	pthread_exit(0);
}

void pong(void)
{
	int i;

	for(i=0;i<50;i++)
	{
		pthread_mutex_lock(&mutex);
		if(pingpong == 0)
		{
			printf("%4d - %1d - pong\n", number,i);
			number++;
			pingpong++;
		}
		else{
			i--;
		}
		pthread_mutex_unlock(&mutex);
	}
	pthread_exit(0);
}
