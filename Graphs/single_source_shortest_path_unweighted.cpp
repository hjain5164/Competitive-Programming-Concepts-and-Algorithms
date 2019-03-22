#include <iostream>
#include <map>
#include <queue>
#include <list>
using namespace std;

template <typename T>
class Graph
{
    map<T, list<T>> adjList;

  public:
    Graph()
    {
    }
    void addEdge(T u, T v, bool bidir = true)
    {
        adjList[u].push_back(v);
        if (bidir)
            adjList[v].push_back(u);
    }
    void bfs(T source_node)
    {
        queue<T> q;
        map<T, int> dist;
        map<T, T> parent;
        for (auto i : adjList)
        {
            dist[i.first] = INT8_MAX;
        }
        q.push(source_node);
        dist[source_node] = 0;
        parent[source_node] = source_node;
        while (!q.empty())
        {
            T node = q.front();
            cout << node << "  ";
            q.pop();
            // For the neighbors of the current node, find out the nodes which are not visited.
            for (int neighbor : adjList[node])
            {
                if (dist[neighbor] == INT8_MAX)
                {
                    q.push(neighbor);
                    parent[neighbor] = node;
                    dist[neighbor] = dist[node] + 1;
                }
            }
        }
        cout << endl;
        //Printing all the distances
        for (auto i : adjList)
        {
            T node = i.first;
            cout << "Distance of " << node << " from " << source_node << " is " << dist[node] << endl;
        }
    }
};
int main()
{
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(0, 4);
    g.addEdge(2, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(3, 4);
    g.bfs(0);
}
