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
        map<T, bool> visited;
        q.push(source_node);
        visited[source_node] = true;
        while (!q.empty())
        {
            T node = q.front();
            cout << node << "  ";
            q.pop();
            // For the neighbors of the current node, find out the nodes which are not visited.
            for (int neighbor : adjList[node])
            {
                if (!visited[neighbor])
                {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
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
