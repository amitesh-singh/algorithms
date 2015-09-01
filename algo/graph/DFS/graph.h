#ifndef __GRAPH_H
#define __GRAPH_H
#include <iostream>
#include <list>

using namespace std;

class Graph
{
   int V;
   list<int> *adj; //Adjacency list.
   enum Color {white, gray, black};

   void DFSUtil(int v, Color color[])
     {
        color[v] = gray; //We discovered v, make it gray
        cout << v << " ";

        list<int>::iterator itr = adj[v].begin();
        for (; itr != adj[v].end(); ++itr)
          {
             if (color[*itr] == white)
               {
                  color[*itr] = gray;
                  DFSUtil(*itr, visited);
               }
          }

        color[v] = black; // We are done and make it black
        cout << v << ",";
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
        adj[v].push_back(w);
        // undirected graph
        // adj[v].push_back(w);
        // adj[w].push_back(v);
     }

   //v -> the vertex from where we will start of DFS
   void DFS(int v)
     {
        Color *color = new Color[V];

        for (int i = 0; i < V; ++i)
          color[i] = white;

        DFSUtil(v, color);

        delete [] color;
     }
};


#endif
