#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<queue>
#include<ctime>
using namespace std;

const int q_size=10;
const int min_pages=10;
const int max_pages=30;
const int pages_add=10;
int available_pages=0;
bool empty_check=false;
pthread_mutex_t mutex1;
pthread_t laborThread,printer1Thread,printer2Thread;


class Printer{

private:
	queue<int> q1;
	queue<int> q2;
public:
	Printer()
	{
	
	}
	
	void addq1(int pages)
	{	
		q1.push(pages);
	}
	
	void addq2(int pages)
	{	
		q2.push(pages);
	}
	
	bool paper_check(int pagesReq)
	{
		return pagesReq<=available_pages;
	}

	bool printNext()
	{	
		if(!q1.empty())
		{
			int pages=q1.front();
			if(paper_check(pages))
			{
				q1.pop();
				cout<<"Printer printed from q1 a document of pages = "<<pages<<endl;
				available_pages-=pages;
				return true;
			}
		}
		else if(!q2.empty())
		{	
			int pages=q2.front();
			if(paper_check(pages))
			{
				q2.pop();
				cout<<"Printer printed from q2 a document of pages = "<<pages<<endl;
				available_pages-=pages;
				return true;
			}
		}
		
		if(q1.empty()&&q2.empty())
		{
			empty_check=true;
		}
		return false;
	}
	
	
	
};

bool paperAvailable=true;
void *labor(void *arg)
{
	
		
	while(true)
	{
		pthread_mutex_lock(&mutex1);
		
		if(paperAvailable)
		{
			paperAvailable=false;
			cout<<"Labor added = "<<pages_add<<" pages to the printer"<<endl;
			available_pages+=pages_add;
		}
		paperAvailable=true;
		pthread_mutex_unlock(&mutex1);
		
		sleep(1);
		/*if(empty_check==true)
			pthread_exit(NULL);*/
		
	}
	
	//pthread_exit(NULL);
}

void *printerFunc(void *printerptr)
{
	Printer* printer=(Printer*)printerptr;
	//cout<<"Ge"<<endl;
	while(true)
	{
		pthread_mutex_lock(&mutex1);
		
	        if (paperAvailable && printer->printNext()) 
	        {
    			paperAvailable = false;
    			
		}

	
		pthread_mutex_unlock(&mutex1);

		
		sleep(1);
    }

    pthread_exit(NULL);
}	


int main()
{
	srand(time(NULL));
	pthread_mutex_init(&mutex1,NULL);
	
	Printer printer1,printer2;
	
	pthread_create(&laborThread,NULL,labor,NULL);
	pthread_create(&printer1Thread,NULL,printerFunc,&printer1);
	
	pthread_create(&printer2Thread,NULL,printerFunc,&printer2);
	
	
	for(int i=0;i<q_size;i++)
	{
		int pages=min_pages+rand()%((max_pages-min_pages)+1);
		
		cout<<"Pages = "<<pages<<endl;
		
		if(i%2==0)
		{
			printer1.addq1(pages);
			printer2.addq1(pages);
		}
		else
		{
			printer1.addq2(pages);
			printer2.addq2(pages);
		}
	}
	
	
	pthread_join(laborThread,NULL);
	pthread_join(printer1Thread, NULL);
   	pthread_join(printer2Thread, NULL);
	
	pthread_mutex_destroy(&mutex1);
	pthread_exit(NULL);
	
	return 0;
}
