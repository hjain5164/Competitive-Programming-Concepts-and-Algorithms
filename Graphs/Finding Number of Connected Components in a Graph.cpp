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
    void dfsHelper(T node, map<T, bool> &visited)
    {
        visited[node] = true;
        cout << node << " ";
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
        int component = 1;
        dfsHelper(source_node, visited);
        cout << endl;
        for (auto i : adjList)
        {
            T city = i.first;
            if (!visited[city])
            {
                dfsHelper(city, visited);
                component++;
            }
        }
        cout << "\nNumber of Components : " << component << endl;
    }
};
int main()
{
    Graph<string> g;
    g.addEdge("Amritsar", "Jaipur");
    g.addEdge("Amritsar", "Delhi");
    g.addEdge("Delhi", "Jaipur");
    g.addEdge("Mumbai", "Jaipur");
    g.addEdge("Mumbai", "Bhopal");
    g.addEdge("Delhi", "Bhopal");
    g.addEdge("Mumbai", "Bangalore");
    g.addEdge("Agra", "Delhi");
    g.addEdge("Andaman", "Nicobar");
    g.dfs("Amritsar");
    return 0;
}
