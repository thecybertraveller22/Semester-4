#include <iostream>
#include <fstream>
#include <algorithm>
#include <limits>
#include <ctime>
#include <cstdlib>

using namespace std;

const int MAX_CITIES = 4;

class Graph
{
private:
    int numCities;
    int distances[MAX_CITIES][MAX_CITIES];

public:
    Graph(int n) : numCities(n)
    {
        for (int i = 0; i < numCities; ++i)
        {
            for (int j = 0; j < numCities; ++j)
            {
                distances[i][j] = 0;
            }
        }
    }

    void addEdge(int from, int to, int dist)
    {
        distances[from][to] = dist;
        distances[to][from] = dist;
    }

    int getNumCities() const
    {
        return numCities;
    }

    int getDistance(int from, int to) const
    {
        return distances[from][to];
    }
};

int calculateTourCost(int tour[], int numCities, const Graph &graph)
{
    int cost = 0;
    for (int i = 0; i < numCities; ++i)
    {
        int from = tour[i];
        int to = tour[(i + 1) % numCities];
        cost += graph.getDistance(from, to);
    }
    return cost;
}

void generateRandomTour(int tour[], int numCities)
{
    for (int i = 0; i < numCities; ++i)
    {
        tour[i] = i;
    }
    random_shuffle(tour, tour + numCities);
}

void findTSPSolution(const Graph &graph)
{
    int numCities = graph.getNumCities();
    int tour[MAX_CITIES];
    int bestTour[MAX_CITIES];
    int minCost = numeric_limits<int>::max();

    srand(time(nullptr));

    for (int i = 0; i < numCities; ++i)
    {
        generateRandomTour(tour, numCities);
        int tourCost = calculateTourCost(tour, numCities, graph);
        if (tourCost < minCost)
        {
            minCost = tourCost;
            copy(tour, tour + numCities, bestTour);
        }
    }

    cout << "Best tour: ";
    for (int i = 0; i < numCities; ++i)
    {
        cout << bestTour[i] + 1 << " "; 
    }
    cout << "Cost: " << minCost << endl;
}

int main()
{
    ifstream file("testFile.txt");
    if (!file.is_open())
    {
        cerr << "Error: Unable to open file" << endl;
        return 1;
    }

    int numCities;
    file >> numCities; 

    Graph graph(numCities);

    int city1, city2, dist;
    while (file >> city1 >> city2 >> dist)
    {
        graph.addEdge(city1 - 1, city2 - 1, dist); 
    }

    file.close();

    findTSPSolution(graph);

    return 0;
}
