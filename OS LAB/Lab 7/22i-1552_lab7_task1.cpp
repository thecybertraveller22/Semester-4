#include<iostream>
#include <stdio.h>
#include<pthread.h>
using namespace std;

void *say_hello(void *arg)
{
	
	cout<<"Hello from thread with id : "<<pthread_self()<<endl;
	return NULL;
}


int main()
{
	cout<<"Main Function here"<<endl;
	
	cout<<"Enter the number of threads you want to create : ";
	int n;
	cin>>n;
	
	
	pthread_t thread[n];
	
	for(int i=0;i<n;i++)
	{
		pthread_create (&thread[i],NULL,say_hello, NULL);
	}
	
	for(int i=0;i<n;i++)
	{
		pthread_join(thread[i],NULL);
	}
	
	
	return 0;
}
