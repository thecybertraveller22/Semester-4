#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
using namespace std;

pthread_mutex_t mutex1;
pthread_t thread1, thread2, thread3, thread4;
int balance = 0;

void *withdraw(void *tid)
{
    long thread_id = (long)tid; 
    for (int i = 0; i < 10; i++)
    {
        pthread_mutex_lock(&mutex1);
        int readbalance = balance;
        
        while (readbalance < 10)
        {
            pthread_mutex_unlock(&mutex1);
            sleep(1);
            pthread_mutex_lock(&mutex1);
            readbalance=balance;
        }
        
        printf("At time %d, the balance for withdrawal thread %ld is %d\n", i, thread_id, balance); 
        readbalance -= 10;
        sleep(1);
        balance = readbalance;
        printf("At time %d, the balance after withdrawal thread %ld is %d\n", i, thread_id, balance); 
        pthread_mutex_unlock(&mutex1);
        sleep(1);
    }
    pthread_exit(NULL);
}

void *deposit(void *tid)
{
    long thread_id = (long)tid; 
    for (int i = 0; i < 10; i++)
    {
        pthread_mutex_lock(&mutex1);
        int readbalance = balance;
        printf("At time %d, the balance before depositing thread %ld is %d\n", i, thread_id, balance); 
        readbalance += 11;
        sleep(1); 
        balance = readbalance;
        printf("At time %d, the balance after depositing thread %ld is %d\n", i, thread_id, balance); 
        pthread_mutex_unlock(&mutex1);
        sleep(1); 
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_mutex_init(&mutex1, NULL);


    pthread_create(&thread1, NULL, withdraw, (void *)1);
    pthread_create(&thread2, NULL, deposit, (void *)2);
    pthread_create(&thread3, NULL, deposit, (void *)3);
    pthread_create(&thread4, NULL, withdraw, (void *)4);

    
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);

    pthread_mutex_destroy(&mutex1);
    pthread_exit(NULL);

    return 0;
}
