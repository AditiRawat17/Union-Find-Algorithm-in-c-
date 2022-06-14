#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
 

struct Edge
{
    int src, dest;
};
 

class Graph
{
public:
    
    vector<vector<int>> adjList;
 
    
    Graph(vector<Edge> const &edges, int n)
    {
        
        adjList.resize(n);
 
        
        for (auto &edge: edges)
        {
            adjList[edge.src].push_back(edge.dest);
        }
    }
};
 

class DisjointSet
{
    unordered_map<int, int> parent;
public:
    
    void MakeSet(int n)
    {
        
        for (int i = 0; i < n; i++) 
        {
            parent[i] = i;
        }
    }
 
    
    int Find(int k)
    {
        
        
        if (parent[k] == k)
        {
            return k;
        }
 
        
        return Find(parent[k]);
    }
 
    
    void Union(int a, int b)
    {
       
        int x = Find(a);
        int y = Find(b);
 
        parent[x] = y;
    }
};
 

bool findCycle(Graph const &graph, int n)
{
    
    DisjointSet ds;
 
   
    ds.MakeSet(n);
 
   
    for (int u = 0; u < n; u++)
    {
        
        for (int v: graph.adjList[u])
        {
            
            int x = ds.Find(u);
            int y = ds.Find(v);
 
           
            if (x == y) 
            {
                return true;
            }
            else {
                ds.Union(x, y);
            }
        }
    }
 
    return false;
}
 

int main()
{
    
    vector<Edge> edges =
    {
        {0, 1}, {0, 6}, {0, 7}, {1, 2}, {1, 5}, {2, 3},
        {2, 4}, {7, 8}, {7, 11}, {8, 9}, {8, 10}, {10, 11}
      
    };
 
   
    int n = 12;
 
   
    Graph graph(edges, n);
 
    if (findCycle(graph, n))
    {
        cout << "Cycle Found";
    }
    else {
        cout << "No Cycle Found";
    }
 
    return 0;
}
