#include <iostream>
#include <algorithm>
#include <random>

using namespace std;

int main() 
{
    
    int arr[] = {1, 2, 3, 4, 5};


    int n = sizeof(arr) / sizeof(arr[0]);


    random_device rd;


    mt19937 g(rd());

    
    shuffle(arr, arr + n, g);


    cout << "Shuffled array: ";
    for (int i = 0; i < n; ++i) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
