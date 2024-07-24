// Created by Syed Arham Ahmed , 22i-1552 , CY-B
#include <iostream>
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
using namespace std;
int e=0,c=0,b=0;

void *bill(void *arg)
{
	cout<<"Calculating your Bill"<<endl;
	int total_bill=0;
	
	cout<<" Eggs = "<<e<<" * 15 "<<" , "<<" Bread = "<<b<<" * 60 "<<" , "<<" Chocolate = "<<c<<" * 50"<<endl;
	
	e=e*15;
	b=b*60;
	c=c*50;
	
	//total_bill=(e*15)+(b*60)+(c*50);
	total_bill=e+c+b;
	pthread_exit((void *)total_bill);
}

void *Tax_Below(void *arg)
{
	int bill=*(int*)arg;
	int tax_below=0;
	
	tax_below=0.08*bill;
	
	cout<<"Your total tax is = "<<tax_below<<endl;
	cout<<"Your total bill with tax is = "<<tax_below+bill<<endl;
	pthread_exit(NULL);
	//pthread_exit((void *)tax_below);
}

void *Tax_Above(void *arg)
{
	int bill=*(int*)arg;
	int tax_above=0;
	
	tax_above=0.10*bill;
	
	cout<<"You are being charged 10% tax because your bill exceeds 250"<<endl;
	cout<<"Your total tax is = "<<tax_above<<endl;
	cout<<"Your total bill with tax is = "<<tax_above+bill<<endl;
	pthread_exit(NULL);
	//pthread_exit((void*)tax_above);
}

void *display(void *arg)
{
	
	
    cout << "Items sorted by prices:" << endl;
    
    if (e >= b && e >= c) 
    {
        
        cout << "Eggs: " << e << endl;
        if (b >= c) 
        {
           
            cout << "Bread: " << b << endl;
            cout << "Chocolate: " << c << endl;
        } 
        else 
        {
            
            cout << "Chocolate: " << c << endl;
            cout << "Bread: " << b << endl;
        }
    } 
    else if (b >= e && b >= c) 
    {
        
        cout << "Bread: " << b << endl;
        if (e >= c) 
        {
          
            cout << "Eggs: " << e << endl;
            cout << "Chocolate: " << c << endl;
        } 
        else 
        {
           
            cout << "Chocolate: " << c << endl;
            cout << "Eggs: " << e << endl;
        }
    } 
    else
    {
      
        cout << "Chocolate: " << c << endl;
        if (e >= b) 
        {
           
            cout << "Eggs: " << e << endl;
            cout << "Bread: " << b << endl;
        } 
        else 
        {
        
            cout << "Bread: " << b << endl;
            cout << "Eggs: " << e << endl;
        }
    }
	
	pthread_exit(NULL);
}

int main()
{
	
	int choice=9;
	while(choice!=0)
	{
		cout<<"Press 1 to purchase eggs"<<endl;
		cout<<"Press 2 to purchase bread"<<endl;
		cout<<"Press 3 to purchase chocolate"<<endl;
		cout<<"Press 0 to end purchase"<<endl;
		cin>>choice;
		
		if(choice==1)
			e++;
		else if(choice==2)
			b++;
		else if(choice==3)
			c++;
		else if(choice==0)
			cout<<"Thanks for your order"<<endl;
	}
	
	pthread_t thread1;
	
	pthread_create(&thread1,NULL,bill,NULL);
	

	int bill_result;
	pthread_join(thread1,(void**)&bill_result);
	
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
	
	if(bill_result<250)
	{
		pthread_t thread2;
		pthread_create(&thread2,&attr,Tax_Below,(void*)&bill_result);
		sleep(1);
	}
		
	else if(bill_result>=250)
	{
		pthread_t thread3;
		pthread_create(&thread3,&attr,Tax_Above,(void*)&bill_result);
		sleep(1);
	}
	pthread_t thread4;
	pthread_create(&thread4,&attr,display,NULL);
	sleep(1);
	pthread_attr_destroy(&attr);
	cout<<"Thread 1 has returned your bill without tax = "<<bill_result<<endl;

	return 0;
}
