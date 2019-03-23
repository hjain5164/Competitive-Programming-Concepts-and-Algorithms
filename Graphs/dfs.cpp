#include <iostream>
#include <map>
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
    // Recursive function of DFS
    void dfsHelper(T node, map<T, bool> &visited)
    {
        //Whenever we come to a node mark it visited.
        visited[node] = true;
        cout << node << " ";
        //Try to find out a node which is a neighbor of current node and not yet visited
        for (T neighbor : adjList[node])
        {
            if (!visited[neighbor])
            {
                dfsHelper(neighbor, visited);
            }
        }
    }
    void dfs(T source_node)
    {
        map<T, bool> visited;
        dfsHelper(source_node, visited);
    }
};
int main()
{
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(0, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.dfs(0);
    return 0;
}
