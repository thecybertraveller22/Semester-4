#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<iostream>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/stat.h>
using namespace std;

int main()
{
	char str[256]="hello arham2";
	//char sender[256];
	char rec[256];
	int fifo_write,fifo_read;
	int f1,f2;
	
	f1=mkfifo("pipe_one",0666);
	f2=mkfifo("pipe_two",0666);
	if(f1<0)
		cout<<"Pipe one not created"<<endl;
	else
		cout<<"Pipe one created"<<endl;
		
	if(f2<0)
		cout<<"Pipe TWO not created"<<endl;
	else
		cout<<"Pipe TWO created"<<endl;
	
	fifo_write=open("pipe_one",O_WRONLY);
	
	if(fifo_write<0)
	{
		cout<<"Error opening file"<<endl;
	}
	else
	{
		while(true)
		{
			cout<<"Enter text = "<<endl;
			cin>>str;
			write(fifo_write,str,sizeof(str));
			cout<<"*"<<str<<"*"<<endl;
			if (strcmp(str, "abort") == 0) 
			{
            			break;
       		}
			fifo_read=open("pipe_two",O_RDONLY);
			read(fifo_read,rec,sizeof(rec));
			close(fifo_read);
			
			cout<<"Arham sent = "<<rec<<endl;
			if (strcmp(str, "abort") == 0) 
			{
            			break;
       		}
       			
		}
		close(fifo_write);
	}
	return 0;
}
