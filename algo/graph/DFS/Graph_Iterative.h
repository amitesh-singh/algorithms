#ifndef __GRAPH_ITR_H
#define __GRAPH_ITR_H

#include <iostream>
#include <list>
#include <stack>

using namespace std;

class Graph
{
   bool directed;
   int V;
   list<int> *adj; //Adjacency list

   void DFSUtil(int v, bool visited[])
   {
      stack<int> s;

      s.push(v);
      visited[v] = true;

      while (!s.empty())
      {
         int visited_node = s.top();
         s.pop();
         cout << visited_node << " ";

         list<int>::iterator itr = adj[visited_node].begin();
         for (; itr != adj[visited_node].end(); ++itr)
         {
            //push all the children into stack
            if (!visited[*itr])
              {
                 s.push(*itr);
                 visited[*itr] = true;
              }
         }
      }
      cout << endl;
   }

public:
   // n -> no .of vetices
   // dir -> directed or undirected.
   Graph(int n, bool dir): directed(dir), V(n), adj(new list<int>[V])
   {
   }

   void addEdges(int v, int w)
   {
      adj[v].push_back(w);
      if (!directed)
         adj[w].push_back(v);
   }

   void DFS(int v)
   {
      bool *visited = new bool[V];
      for (int i = 0; i < V; ++i)
      {
         visited[i] = false;
      }

      DFSUtil(v, visited);
   }

   enum Color {white, grey, black};

   void DFSCormen(int v)
     {
        int time = 0;
        Color *color = new Color[V];
        int *d = new int[V];
        int *f = new int[V];

        for (int i = 0; i < V; ++i)
          {
             color[i] = white;
             d[i] = f[i] = 0;
          }

        stack<int> s;

        s.push(v);
        color[v] = grey;
        time = time + 1;
        d[v] = time;
        int current = v;
        cout << v << " ";

        while (!s.empty());
          {
             cout << "hello..";
             current = s.top();
             s.pop();
             if (color[current] == white)
               {
                  color[current] = grey;
                  cout << current << " ";
                  list<int>::iterator itr = adj[current].begin();
                  for (; itr != adj[current].end(); ++itr)
                    {
                       if (color[*itr] == white)
                         {
                            s.push(*itr);
                         }
                    }
               }
          }
        cout << endl;

        delete [] color;
        delete [] f;
        delete [] d;
     }

}; //class ends

#endif
