#ifndef __GRAPH_H
#define __GRAPH_H
#include <iostream>
#include <list>
#include <cstring>

using namespace std;

class Graph
{
   int V;
   bool directed;
   list<int> *adj; //Adjacency list.

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

   void addEdge(int v, int w)
     {
        // Directed Graph v --> w
        adj[v].push_back(w);
        // undirected graph
        // adj[v].push_back(w);
        if (!directed)
          adj[w].push_back(v);
     }

   // This program finds whether G contains cycle or not.
   enum Color {white, gray, black};

   bool isCyclicUtil(int s, Color color[])
     {
        if (color[s] == white)
          {
             color[s] = gray;

             list<int>::iterator itr = adj[s].begin();
             int u;
             for (;itr != adj[s].end(); ++itr)
               {
                  u = *itr;
                  if (color[u] == white)
                    return  isCyclicUtil(u, color);
                  else if (color[u] == gray)
                    {
                       //Boom! we found the back edge, s, u
                       return true;
                    }
               }
          }

        color[s] = black;

        return false;
     }

   bool isCyclic()
     {
        Color *color = new Color[V];

        memset(color, 0, V * sizeof(Color));

        bool found = false;
        for (int i = 0; i < V; ++i)
          {
             if (isCyclicUtil(i, color))
               {
                  cout << "Found cyclic while  dong DFS on vertex: " << i << endl;
                  found = true;
                  break;
               }
          }

        return found;
     }
};

#endif
