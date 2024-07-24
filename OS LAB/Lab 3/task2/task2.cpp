#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int cal_d_mul_a(int d, int a)
{
    return d * a;
}

int calculate_a_plus_b(int a, int b)
{
    return a + b;
}

int calculate_c_minus_a(int c, int a)
{
    return c - a;
}

int main()
{
    int a = 1, b = 2, c = 3, d = 4; 
    int pipe_d_times_a[2]; 
    int pipe_a_plus_b[2];  
    int pipe_c_minus_a[2]; 

 
    if (pipe(pipe_d_times_a) == -1 || pipe(pipe_a_plus_b) == -1 || pipe(pipe_c_minus_a) == -1)
    {
        cerr << "Error in pipe creation" << endl;
        return 1;
    }

  
    pid_t pid_d_times_a = fork();

    if (pid_d_times_a == 0)
    {
        close(pipe_d_times_a[0]);
        int result_d_times_a = cal_d_mul_a(d, a);
        write(pipe_d_times_a[1], &result_d_times_a, sizeof(result_d_times_a));
        close(pipe_d_times_a[1]); 
        return 0;
    }

   
    pid_t pid_a_plus_b = fork();

    if (pid_a_plus_b == 0)
    {
      
        close(pipe_a_plus_b[0]); 
        int result_a_plus_b = calculate_a_plus_b(a, b);
        write(pipe_a_plus_b[1], &result_a_plus_b, sizeof(result_a_plus_b));
        close(pipe_a_plus_b[1]); 


        pid_t pid_c_minus_a = fork();

        if (pid_c_minus_a == 0)
        {

            close(pipe_c_minus_a[0]);
            int result_c_minus_a = calculate_c_minus_a(c, a);
            write(pipe_c_minus_a[1], &result_c_minus_a, sizeof(result_c_minus_a));
            close(pipe_c_minus_a[1]); 
            return 0;
        }
        else
        {
            waitpid(pid_c_minus_a, nullptr, 0); 
        }

        return 0;
    }

   
    waitpid(pid_d_times_a, nullptr, 0); 

    close(pipe_d_times_a[1]); 
    int result_d_times_a;
    read(pipe_d_times_a[0], &result_d_times_a, sizeof(result_d_times_a));
    close(pipe_d_times_a[0]); 

    waitpid(pid_a_plus_b, nullptr, 0);

    close(pipe_a_plus_b[1]); 
    int result_a_plus_b;
    read(pipe_a_plus_b[0], &result_a_plus_b, sizeof(result_a_plus_b));
    close(pipe_a_plus_b[0]); 

    wait(nullptr); 

    close(pipe_c_minus_a[1]); 
    int result_c_minus_a;
    read(pipe_c_minus_a[0], &result_c_minus_a, sizeof(result_c_minus_a));
    close(pipe_c_minus_a[0]);

  
    int final_result = result_d_times_a * (result_a_plus_b + result_c_minus_a);

 
    cout << "Result of the equation A = (d*a) * [ (a+b) + (c-a) ]: " << final_result << endl;

    return 0;
}
