#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <string>
using namespace std;


int main()
{
	cout<<"-------------------------------------"<<endl;
	cout<<"Welcome to the spell checker software"<<endl;
	cout<<"-------------------------------------"<<endl;
	cout<<endl;
	int pipefd[2];
	if(pipe(pipefd)==-1)
		cout<<"error in pipe "<<endl;
	cout<<"Enter text to check for spelling : ";
	string text;
	getline(cin,text);
	
	
	pid_t childpid = fork();
	
	if(childpid==0)//child
	{
		cout<<"Child with id : "<<getpid()<<" has started"<<endl;
		close(pipefd[0]);
		write(pipefd[1],&text,sizeof(text));
		close(pipefd[1]);
		execlp("./arhamspell", "arhamspell", text.c_str(), (char *)NULL);
		cout<<"Exec failed"<<endl;


		//cout<<"Text = "<<text<<endl;
		
	}
	else if(childpid>0)
	{
		int status;
		
		waitpid(childpid, &status, 0);
		
		cout<<"Parent process with pid = "<<getpid()<<endl;
		
		int exit=WEXITSTATUS(status);
		
		if(exit==1)
			cout<<"Parent says Spelling correct"<<endl;
		else
			cout<<"Parent says spelling in-correct"<<endl;
	}

	
	

	return 0;
}
