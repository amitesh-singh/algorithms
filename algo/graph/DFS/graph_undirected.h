#ifndef __GRAPH_H
#define __GRAPH_H
#include <iostream>
#include <list>

using namespace std;

class Graph
{
   int V;
   list<int> *adj; //Adjacency list.

   void DFSUtil(int v, bool visited[])
     {
        //we already visted 'v'
        visited[v] = true;
        cout << v << " ";

        list<int>::iterator itr = adj[v].begin();
        for (; itr != adj[v].end(); ++itr)
          {
             if (!visited[*itr])
               DFSUtil(*itr, visited);
          }
     }

 public:
   Graph(int n): V(n), adj(new list<int>[V])
   {
   }

   ~Graph()
     {
        delete [] adj;
     }

   void addEdges(int v, int w)
     {
        // Directed Graph v --> w
        //adj[v].push_back(w);
        // undirected graph
        adj[v].push_back(w);
        adj[w].push_back(v);
     }

   //v -> the vertex from where we will start of DFS
   void DFS(int v)
     {
        bool *visited = new bool[V];

        for (int i = 0; i < V; ++i)
          visited[i] = false;

        DFSUtil(v, visited);

        delete [] visited;
     }
};


#endif
