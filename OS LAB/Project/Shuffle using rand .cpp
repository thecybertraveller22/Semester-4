#include <iostream>
#include <ctime>  
#include <cstdlib> 

using namespace std;

void fisherYatesShuffle(int arr[], int n) 
{
    for (int i = n - 1; i > 0; --i) 
    {
        int j = rand() % (i + 1);
        swap(arr[i], arr[j]);
    }
}

int main() 
{
    int arr[] = {1, 2, 4, 6, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    srand(time(0));

    fisherYatesShuffle(arr, n);

    cout << "Shuffled array: ";
    for (int i = 0; i < n; ++i) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
