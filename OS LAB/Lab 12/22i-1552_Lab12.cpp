#include <stdio.h>

#include <stdlib.h>

#include <pthread.h>

#include <signal.h>

#include <semaphore.h>

#include <unistd.h>

#include <iostream>

using namespace std;

sem_t sem;

void *cross(void *arg)

{

	long thread_id = (long)arg;

	cout << "Car " << thread_id << " is waiting to get on the bridge" << endl;

	cout << endl;

	cout << endl;

	sem_wait(&sem);

	cout << "Car " << thread_id << " is crossing the bridge" << endl;

	sleep(3);

	cout << "Car " << thread_id << " has crossed the bridge" << endl;

	sem_post(&sem);

	cout << endl;

	cout << endl;

	pthread_exit(NULL);
}

int main()

{

	pthread_t t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15;

	int count = 0;

	sem_init(&sem, 0, 3);

	pthread_create(&t1, NULL, cross, (void *)1);

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

	pthread_join(t15, NULL);

	return 0;
}
