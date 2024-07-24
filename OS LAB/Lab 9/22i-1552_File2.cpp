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
	char str[256]="hello arham";
	char rec[256];
	int fifo_read=open("pipe_one",O_RDONLY);
	int fifo_write;
	if(fifo_read<0)
	{
		cout<<"Error opening file"<<endl;
	}	
	else
	{
		while(true)
		{
			read(fifo_read,str,sizeof(str));
			
			cout<<"Tommy sent = "<<str<<endl;
			if(strcmp(str,"abort")==0)
				break;
			cout<<"Type your reply (abort) to end = ";
			cin>>rec;
			fifo_write=open("pipe_two",O_WRONLY);
			write(fifo_write,rec,sizeof(rec));
			close(fifo_write);
			
			if(strcmp(str,"abort")==0)
				break;
		}
		close (fifo_read);
	}
	return 0;
}
