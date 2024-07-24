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
	int choice=-1;
	
	while(choice!=0)
	{
	// i have used 4 different exec calls 
		//cout<<"This program assumes files already exist, you can create new file thoroght this program as well "<<endl;
		cout<<"1. Execl View directory using ls"<<endl;
		cout<<"2. Execlp Cat Command"<<endl;
		cout<<"3. Execv call using cp and cat"<<endl;
		cout<<"4. Execvp Rename the files using mv"<<endl;
		cout<<"5. Execlp remove file"<<endl;
		cout<<"6. Execlp touch file"<<endl;
		cout<<"7. Call a.out file"<<endl;
		cout<<"0. Exit"<<endl;
		cin>>choice;
		
		while(choice<0 || choice>7)
		{
			cout<<"You have entered an in-valid choice"<<endl;
			cout<<"Re-enter your choice : ";
			cin >> choice;
		}
		
		if(choice==1) // ls
		{
			pid_t childpid = fork();
	
			if(childpid==0)
			{
				cout<<"Child with id = "<<getpid()<<endl;
				execl("/bin/ls" ,"ls","-l","/usr",NULL);
				cout<<"Exec failed"<<endl;
			}
			else if (childpid >0)
			{
				wait(NULL);
				cout<<"Parent process with pid = "<<getpid()<<endl;
			}	
		}
		else if(choice==2) // cat
		{
			pid_t childpid = fork();
	
			if(childpid==0)
			{
				cout<<"Child with id = "<<getpid()<<endl;
				//execl("/home/arham/Desktop/OS LAB/Lab 4","cat","arham",NULL);
				//execlp("/bin/cat","/home/arham/Desktop/OS LAB/Lab 4","arham.txt",NULL);
				
				/////////execlp("cat","cat","renamedarham.txt",NULL);
				//execl("/bin/cat","cat","arham",NULL);
				
				string filename;
				cout << "Enter the file name: ";
				cin >> filename;
				
				
				const char* filename_cstr = filename.c_str();
				
				execlp("cat", "cat", filename_cstr, NULL);
				cout<<"Exec failed"<<endl;
			}
			else if (childpid >0)
			{
				wait(NULL);
				cout<<"Parent process with pid = "<<getpid()<<endl;
			}	
		}
		else if(choice==3) // cp &  cat
		{
			string sourceFile,destinationFile,destinationPath;
			pid_t childpid = fork();
			
			if(childpid==0)
			{	
				cout << "Enter source file name: ";
				cin >> sourceFile;
				cout << "Enter destination file name: ";
				cin >> destinationFile;
				cout << "Swapping the contents of the files" << endl;
				
				
				string sourcePath = "/home/arham/Desktop/OS LAB/Lab 4/" + sourceFile;
				destinationPath = "/home/arham/Desktop/OS LAB/Lab 4/" + destinationFile;
				
				
				const char *cp_args[] = {"/bin/cp", sourcePath.c_str(), destinationPath.c_str(), NULL};
				const char *cat_args[] = {"/bin/cat", destinationPath.c_str(), NULL};
				
				
				execv("/bin/cp", const_cast<char *const *>(cp_args));
				
				cout<<"Execv failed"<<endl;
			}
			else if (childpid >0)
			{
				wait(NULL);
				cout<<"Parent process with pid = "<<getpid()<<endl;
				//string file="/home/arham/Desktop/OS LAB/Lab 4/" + destinationFile;
				const char *cat_args[] = {"/bin/cat", destinationPath.c_str(), NULL};
       				execv("/bin/cat", const_cast<char *const *>(cat_args));
       				cout<<"Execv failed"<<endl;
			}
		}
		else if(choice==4) // mv
		{
			string sourceFile,renamed;
			pid_t childpid = fork();
			
			if(childpid==0)
			{
				cout << "Enter source file name: ";
				cin >> sourceFile;
				cout << "Enter new file name: ";
				cin >> renamed;
				
				const char* renamed_cstr = renamed.c_str();
				const char* sourceFile_cstr = sourceFile.c_str();
				
				cout<<"Renaming the files"<<endl;
				const char *args[] = {"mv", sourceFile_cstr, renamed_cstr, NULL};
				execvp("mv",const_cast<char *const *> (args));
				cout<<"Execvp failed"<<endl;
			}
			else if (childpid >0)
			{
				wait(NULL);
				cout<<"Parent process with pid = "<<getpid()<<endl;
			}
		}
		else if(choice==5) //rm
		{
			string sourceFile;
			pid_t childpid = fork();
	
			if(childpid==0)
			{
				cout<<"Child with id = "<<getpid()<<endl;
				//execl("/home/arham/Desktop/OS LAB/Lab 4","cat","arham",NULL);
				//execlp("/bin/cat","/home/arham/Desktop/OS LAB/Lab 4","arham.txt",NULL);
				cout << "Enter source file name: ";
				cin >> sourceFile;
				
				const char* sourceFile_cstr = sourceFile.c_str();
				
				cout<<"Removing file"<<endl;
				execlp("rm","rm",sourceFile_cstr,NULL);
				//execl("/bin/cat","cat","arham",NULL);
				cout<<"Exec failed"<<endl;
			}
			else if (childpid >0)
			{
				wait(NULL);
				cout<<"Parent process with pid = "<<getpid()<<endl;
			}
		}
		else if(choice==6)//touch
		{
			string sourceFile;
			pid_t childpid = fork();
	
			if(childpid==0)
			{
				cout<<"Child with id = "<<getpid()<<endl;
				//execl("/home/arham/Desktop/OS LAB/Lab 4","cat","arham",NULL);
				//execlp("/bin/cat","/home/arham/Desktop/OS LAB/Lab 4","arham.txt",NULL);
				
				cout << "Enter source file name: ";
				cin >> sourceFile;
				
				const char* sourceFile_cstr = sourceFile.c_str();
				
				cout<<"Creating new file"<<endl;
				execlp("touch","touch",sourceFile_cstr,NULL);
				//execl("/bin/cat","cat","arham",NULL);
				cout<<"Exec failed"<<endl;
			}
			else if (childpid >0)
			{
				wait(NULL);
				cout<<"Parent process with pid = "<<getpid()<<endl;
			}
		}
		else if(choice==7) // calling a.out file like we did in terminal batch wala kaam
		{
			pid_t childpid = fork();
			
			if(childpid==0)
			{
				cout<<"Child with id = "<<getpid()<<endl;
				
				execlp("./a.out","a.out",NULL);
				cout<<"Exec failed"<<endl;
			}
			else if(childpid>0)
			{
				wait(NULL);
				cout<<"Parent process with pid = "<<getpid()<<endl;
			}
		}
		else if(choice==0)
		{
			exit(0);
		}
		
	}
	
	cout<<"Goodbye...................................................."<<endl;
	return 0;
}
