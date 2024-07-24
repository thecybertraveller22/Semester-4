#include<iostream>
#include <stdio.h>
#include<pthread.h>
using namespace std;

int arr[20]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                   11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

void *sum(void *arg)
{
	cout<<endl;
	cout<<"Calculating the SUM"<<endl;
	int sum=0;
	
	for(int i=0;i<20;i++)
	{
		sum+=arr[i];
	}
	cout<<"Sum is "<<sum<<endl;
	cout<<endl;
	//pthread_exit((void*) sum);
	pthread_exit(NULL);
}

void *mul(void *arg)
{
	cout<<endl;
	cout<<"Performing the Multiplication"<<endl;
	long long int mul=arr[0];
	
	for(int i=0;i<20;i++)
	{
		mul*=arr[i];
	}
	cout<<"Multiplication is "<<mul<<endl;
	cout<<endl;
	//pthread_exit((void*) mul);
	pthread_exit(NULL);
}

void *search(void *arg)
{
	cout<<endl;
	int x=*(int*)arg;
	cout<<"Searching for "<<x<<" in the array"<<endl;
	bool found=false;
	for(int i=0;i<20;i++)
	{
		if(arr[i]==x)
		{
			found=true;
			break;
		}
			
	}
	if(found==true)
		cout<<"Number found in the array"<<endl;
	else
		cout<<"Number not found in the array"<<endl;
	cout<<endl;
	pthread_exit(NULL);
}



int main()
{
	cout<<"Main Function here"<<endl;
	cout<<endl;
	cout<<"Enter a number to search for in the array ";
	cout<<endl;
	int num;
	cin>>num;
	
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	
	pthread_t thread1,thread2,thread3;
	
	pthread_create(&thread1,&attr,sum,NULL);
	pthread_create(&thread2,&attr,mul,NULL);
	pthread_create(&thread3,&attr,search,(void*)&num);
	
	
	/*pthread_detach(thread1);
	pthread_detach(thread2);*/
	
	pthread_attr_destroy(&attr);
	
	/*int joinret,joinret2;
	joinret=pthread_join(thread1,NULL);
	
	if(joinret==0)
		cout<<"Join success"<<endl;
	else
		cout<<"Join failed"<<endl;
		
	joinret2=pthread_join(thread2,NULL);

	if(joinret2==0)
		cout<<"Join success"<<endl;
	else
		cout<<"Join failed"<<endl;*/
	/*void *sum;
	void *mul;
	pthread_join(thread1,&sum);
	pthread_join(thread2,&mul);*/
	
	/*cout<<"Sum is = "<<((int *)sum)<<endl;
	cout<<"Multiplication is = "<<((int *)mul)<<endl;*/
	
	/*printf("In main thread1 returned value sum =  %ld \n", (int *) sum );
	printf("In main thread2 returned value mul =  %ld \n", (int *) mul );*/
	
	pthread_exit(NULL);
	
	return 0;
}
