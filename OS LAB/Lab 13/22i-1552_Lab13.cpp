#include <stdio.h>

#include <stdlib.h>

#include <pthread.h>

#include <signal.h>

#include <semaphore.h>

#include <unistd.h>

#include <iostream>

using namespace std;

sem_t sem;

void *eat(void *arg)
{
	long thread_id = (long)arg;
	//cout<<endl;
	cout << "Person " << thread_id << " is waiting to to be seated " << endl;
	//cout<<endl;
	sem_wait(&sem);
	//cout<<endl;
	cout << "Person " << thread_id << " is eating food" << endl;
	//cout<<endl;
	sleep(2);
	//cout<<endl;
	cout << "Person " << thread_id << " has finished eating food" << endl;
	//cout<<endl;
	sem_post(&sem);

	pthread_exit(NULL);
}

int main()
{

	pthread_t t[20];

	int count = 0;

	sem_init(&sem, 0, 10);
	
	for(int i=0;i<20;i++)
		pthread_create(&t[i],NULL,eat,(void*)(intptr_t)(i+1));
		
	for(int i=0;i<20;i++)
		pthread_join(t[i],NULL);

/*	pthread_create(&t1, NULL, cross, (void *)1);

	pthread_create(&t2, NULL, cross, (void *)2);

	pthread_create(&t3, NULL, cross, (void *)3);

	pthread_create(&t4, NULL, cross, (void *)4);

	pthread_create(&t5, NULL, cross, (void *)5);

	pthread_create(&t6, NULL, cross, (void *)6);

	pthread_create(&t7, NULL, cross, (void *)7);

	pthread_create(&t8, NULL, cross, (void *)8);

	pthread_create(&t9, NULL, cross, (void *)9);

	pthread_create(&t10, NULL, cross, (void *)10);

	pthread_create(&t11, NULL, cross, (void *)11);

	pthread_create(&t12, NULL, cross, (void *)12);

	pthread_create(&t13, NULL, cross, (void *)13);

	pthread_create(&t14, NULL, cross, (void *)14);

	pthread_create(&t15, NULL, cross, (void *)15);

	pthread_join(t1, NULL);

	pthread_join(t2, NULL);

	pthread_join(t3, NULL);

	pthread_join(t4, NULL);

	pthread_join(t5, NULL);

	pthread_join(t6, NULL);

	pthread_join(t7, NULL);

	pthread_join(t8, NULL);

	pthread_join(t9, NULL);

	pthread_join(t10, NULL);

	pthread_join(t11, NULL);

	pthread_join(t12, NULL);

	pthread_join(t13, NULL);

	pthread_join(t14, NULL);

	pthread_join(t15, NULL);*/

	return 0;
}
