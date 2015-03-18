#ifndef _GRAPH_H
#define _GRAPH_H

#include<iostream>
#include<map>
#include<vector>
#include <set>
#include <list>

using namespace std;

namespace ami
{

   class Graph
     {
        int V;
        list<int> *adj;
      public:
        Graph(int n): V(n), adj(new list<int>[V])
        {
        }

        ~Graph()
          {
             delete [] adj;
          }

        void addEdges(int e1, int e2)
          {
             adj[e1].push_back(e2);
             adj[e2].push_back(e1);
          }

        enum Color
          {
             white, gray, black
          };
        // s -> source from where we will start the BFS
        void BFS(int s)
          {
             Color *color = new Color[V];
             for (int i = 0; i < V; ++i)
               {
                  //All the vertices are set to white color
                  color[i] = white;
               }
          }
     };
}

#endif //end
