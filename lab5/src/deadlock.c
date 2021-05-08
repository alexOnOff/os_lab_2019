#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


pthread_mutex_t mut1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mut2 = PTHREAD_MUTEX_INITIALIZER;

void fun1() 
{

	pthread_mutex_lock(&mut1);

	printf("Testing for deadlock. Deadlock is working\n");
	sleep(1);
	pthread_mutex_lock(&mut2);
	printf("Deadlock didn't work\n");
	pthread_mutex_unlock(&mut2);
	pthread_mutex_unlock(&mut1);
}

void fun2() 
{
	pthread_mutex_lock(&mut2);
	printf("Testing for deadlock. Deadlock is working\n");
	sleep(1);
	pthread_mutex_lock(&mut1);
	printf("Deadlock didn't work\n");
	pthread_mutex_unlock(&mut1);
	pthread_mutex_unlock(&mut2);
}

int main() {
pthread_t thread1, thread2;

if (pthread_create(&thread1, NULL, (void *)fun1, NULL) != 0) 
{
	perror("pthread_create");
	exit(1);
}

if (pthread_create(&thread2, NULL, (void *)fun2, NULL) != 0)
{
	perror("pthread_create");
	exit(1);
}

if (pthread_join(thread1, NULL) != 0) 
{
	perror("pthread_join");
	exit(1);
}

if (pthread_join(thread2, NULL) != 0) 
{
	perror("pthread_join");
	exit(1);
}

  return 0;
}