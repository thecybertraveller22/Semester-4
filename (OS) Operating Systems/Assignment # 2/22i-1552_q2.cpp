/*Explaining the tie breaker mechanism:
	First off alll after outputting all the calcualtions by each thread I have added another loop to ckeck for duplicate values and output the thread numbers with duplicates
	Next to break this duplication I simply output the smallest calculation provided by the thread at the earliest ie: the thread which gave the result in the shortest time is the one i choose as my final  shortest output
	
	Syed Arham Ahmed BS-CY-B 22i-1552*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include<climits>
#include <pthread.h>

using namespace std;

const int MAX_CITIES = 4; 

int distances[MAX_CITIES][MAX_CITIES]; 
int numCities = 0;                     
int tourCosts[MAX_CITIES];              
int minCost = INT_MAX; 
int minCostThreadId = -1; 


void readDistancesFromFile(const string& filename) 
{
    ifstream file(filename);
    if (!file.is_open()) 
    {
        cerr << "Error: Unable to open file " << filename << endl;
        exit(1);
    }

    file >> numCities;

    int city1, city2, dist;
    while (file >> city1 >> city2 >> dist) 
    {
        distances[city1 - 1][city2 - 1] = dist;
        distances[city2 - 1][city1 - 1] = dist; 
    }

    file.close();
}

int calculateTourCost(int* tour) 
{
    int cost = 0;
    for (int i = 0; i < numCities; ++i) 
    {
        int from = tour[i];
        int to = tour[(i + 1) % numCities]; // Mod is liyay hy so that last city ky baad ham first city pr aa jain dobara
        cost += distances[from][to];
    }
    return cost;
}


void* findTSPSolution(void* arg) 
{
    int threadId = *(int*)arg;

    int cities[MAX_CITIES];
    for (int i = 0; i < numCities; ++i)
        cities[i] = i;

   
    srand(time(nullptr) + threadId);

   
    for (int i = 0; i < numCities; ++i) 
    {
        int j = rand() % numCities;
        swap(cities[i], cities[j]);  //cities ko randomly ja rhy
    }

  
    int tourCost = calculateTourCost(cities);

    
    tourCosts[threadId] = tourCost;

    
    if (tourCost < minCost) 
    {
        minCost = tourCost;
        minCostThreadId = threadId;
    }
	
    pthread_exit(NULL);
}

int main() 
{
    // pthread_attr_t attr;
    // pthread_attr_init(&attr);
    // pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
 	
    const string filename = "testFile.txt";
    readDistancesFromFile(filename);

    int numThreads;
    cout << "Enter the number of threads: ";
    cin >> numThreads;

    pthread_t threads[numThreads];
    int threadIds[numThreads];

   
    for (int i = 0; i < numThreads; ++i) 
    {
        threadIds[i] = i;
        pthread_create(&threads[i], NULL, findTSPSolution, &threadIds[i]);
    }

  
    for (int i = 0; i < numThreads; ++i) 
    {
        pthread_join(threads[i], nullptr);
    }

 
    for(int i=0;i<numThreads;++i)
    {
    	cout<<"Thread with id = "<<i<<" has calculated cost = "<<tourCosts[i]<<endl;
    }
    cout<<endl;
    
    for(int i=0;i<numThreads;++i)
    {
    	for(int j=i+1;j<numThreads;++j)
    	{
    		if(tourCosts[i]==tourCosts[j])
    		{
    			if(i!=j)
				if(tourCosts[i]==minCost)
					cout<<"Duplicate value of thread "<<i<<" and thread "<<j<<endl;
    		}
    	}
    }
    //pthread_attr_destroy(&attr);
    cout << "The first thread to find the Minimum tour cost is " << minCostThreadId << ", and the cost is = " << minCost << endl;
    //pthread_exit(NULL);

    return 0;
}
