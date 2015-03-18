#ifndef __GRAPH_H
#define __GRAPH_H
#include <iostream>
#include <list>
#include <map>
#include <stack>

using namespace std;

class Graph
{
   int V;
   bool directed;
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
   Graph(int n, bool dir): V(n),
                           directed(dir),
                           adj(new list<int>[V])
   {
   }

   ~Graph()
     {
        delete [] adj;
     }

   void addEdges(int v, int w)
     {
        // Directed Graph v --> w
        adj[v].push_back(w);
        // undirected graph
        // adj[v].push_back(w);
        if (!directed)
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

   //iterAtive cyclic code.
   bool CyclicUtilIterative(int v, bool visited[])
     {
        stack<int> s;
        s.push(v);

        while (!s.empty())
          {
             int x = s.top();
             s.pop();
             if (visited[x])
               continue;
             visited[x] = true;
             list<int>::iterator itr = adj[x].begin();
             for (; itr != adj[x].end(); ++itr)
               {
                  if (!visited[*itr])
                    s.push(*itr);
                  else if (*itr != v)
                    return true;
               }
          }

        return false;
     }

   //iterAtive cyclic code.
   bool isCyclicIterative()
     {
        bool *visited = new bool[V];
        map<int, int> parent;

        for (int i = 0; i < V; ++i)
          {
             visited[i] = false;
          }
        for (int i = 0; i < V; ++i)
          {
             parent.clear();
             if (!visited[i] && CyclicUtilIterative(i, visited))
               {
                  return true;
               }
          }

        return false;
     }

   //recursive method.
   bool isCyclic()
     {
        bool *visited = new bool[V];

        for (int i = 0; i < V; ++i)
          {
             visited[i] = false;
          }

        for (int i = 0; i < V; ++i)
          {
             if (!visited[i] && CyclicUtil(i, visited, -1))
               {
                  return true;
               }
          }

        return false;
     }

   //recursive code.
   bool CyclicUtil(int v, bool visited[], int parent)
     {
        visited[v] = true;

        list<int>::iterator itr = adj[v].begin();
        for (; itr != adj[v].end(); ++itr)
          {
             if (!visited[*itr])
               {
                  if (CyclicUtil(*itr, visited, v))
                    {
                       return true;
                    }
               }
             else if (*itr != parent)
               {
                  return true;
               }
          }

        return false;
     }
};


#endif
