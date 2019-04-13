/*
HACKERRANK PROBLEM - JOURNEY TO THE MOON
The member states of the UN are planning to send people to the moon. 
They want them to be from different countries. 
You will be given a list of pairs of astronaut ID's. 
Each pair is made of astronauts from the same country. 
Determine how many pairs of astronauts from different countries they can choose from.

For more details visit https://www.hackerrank.com/challenges/journey-to-the-moon/problem
*/

#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *l;

  public:
    Graph(int v)
    {
        V = v;
        l = new list<int>[V];
    }
    void addEdge(int u, int v)
    {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void dfsHelper(int i, bool visited[], int &country_size)
    {
        visited[i] = true;
        country_size++;
        for (auto neighbor : l[i])
        {
            if (!visited[neighbor])
            {
                dfsHelper(neighbor, visited, country_size);
            }
        }
    }

    int dfsMoon()
    {
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;
        int n = V;
        int total_ways = (n) * (n - 1) / 2;
        for (int i = 0; i < V; i++)
        {
            if (visited[i] == false)
            {
                int country_size = 0;
                dfsHelper(i, visited, country_size);
                //cout<<"Country Size"<<country_size<<endl;
                total_ways -= country_size * (country_size - 1) / 2;
            }
        }
        return total_ways;
    }
};

int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(2, 3);
    g.addEdge(0, 4);
    cout << g.dfsMoon();
    return 0;
}