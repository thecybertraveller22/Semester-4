#include<iostream>
#include <stdio.h>
#include<pthread.h>
using namespace std;

int arr[30]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                   11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
                   21, 22, 23, 24, 25, 26, 27, 28, 29, 30};

void *sum(void *arg)
{
	cout<<"Calculating the SUM"<<endl;
	int sum=0;
	
	for(int i=0;i<30;i++)
	{
		sum+=arr[i];
	}
	//cout<<"Sum is "<<sum<<endl;
	
	pthread_exit((void*) sum);
	//return NULL;
}

void *mul(void *arg)
{
	cout<<"Performing the Multiplication"<<endl;
	int mul=1;
	
	for(int i=0;i<30;i++)
	{
		mul*=arr[i];
	}
	//cout<<"Multiplication is "<<mul<<endl;
	
	pthread_exit((void*) mul);
	//return NULL;
}



int main()
{
	cout<<"Main Function here"<<endl;
	
	pthread_t thread1,thread2;
	
	pthread_create(&thread1,NULL,sum,NULL);
	pthread_create(&thread2,NULL,mul,NULL);
	void *sum;
	void *mul;
	pthread_join(thread1,&sum);
	pthread_join(thread2,&mul);
	
	/*cout<<"Sum is = "<<((int *)sum)<<endl;
	cout<<"Multiplication is = "<<((int *)mul)<<endl;*/
	
	printf("In main thread1 returned value sum =  %ld \n", (int *) sum );
	printf("In main thread2 returned value mul =  %ld \n", (int *) mul );
	
	
	
	return 0;
}
