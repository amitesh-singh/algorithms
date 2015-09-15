#ifndef _GRAPH_H__
#define _GRAPH_H__

#include <iostream>
#include <list>
#include <stack>
#include <cstring> // for mmeset()

using namespace std;

class Graph
{
   int V;
   list<int> *adj;
   int *d; //discovery time
   int *p; // parent
   int *low; // low points
   bool directed;
   int time;

 public:
   enum Color {white, gray, black};
   Color *color;

   Graph(int _V, bool _directed): V(_V), adj(new list<int>[V])
   {
      d = new int[V]; //discovery
      p = new int[V]; //parent
      low = new int[V]; // low
      color = new Color[V]; //color
      directed = _directed;
   }

   ~Graph()
     {
        delete [] d;
        delete [] p;
        delete [] low;
        delete [] adj;
     }

   void addEdge(int e1, int e2)
     {
        //Directed Graph
        adj[e1].push_back(e2);

        if (!directed)
          {
             adj[e2].push_back(e1);
          }
     }

   void findArtPointsUtil(int s, bool ap[])
     {
        ++time;
        d[s] = low[s] = time;
        color[s] = gray;
        int v;
        int children = 0;

        list<int>::iterator itr = adj[s].begin();

        for (; itr != adj[s].end(); ++itr)
          {
             v = *itr;
             if (color[*itr] == white)
               {
                  children++;
                  p[v] = s;
                  findArtPointsUtil(v, ap);

                  low[s] = min(low[s], low[v]);

                  if (p[s] == -1 && children > 1)
                    {
                       ap[s] = true; // this node s is articular point & (s,v) is a bridge
                    }
                  if (p[s] != -1 && low[v] >= d[s])
                    {
                       ap[s] = true; // this node is articular point & (s,v) is a bridge
                    }
               }
             else if (v != p[s])
               {
                  low[s] = min(low[s], d[v]);
               }
          }

        color[s] = black;
     }

   void findArtPoints()
     {
        bool *ap = new bool[V];

        time = 0;
        for (int i = 0; i < V; ++i)
          {
             p[i] = -1;
             color[i] = white;
             ap[i] = false;
          }

        for (int i = 0; i < V; ++i)
          {
             if (color[i] == white)
               findArtPointsUtil(i, ap);
          }

        bool isBiconnected = true;

        cout << "Articular points: " << endl;
        for (int i = 0; i < V; ++i)
          {
             if (ap[i] == true)
               {
                  isBiconnected = false;
                  cout << i << " ";
               }
          }
        cout << endl;

        if (isBiconnected)
          {
             cout << "This graph is biconnected\n";
          }

        delete [] ap;
     }
};

#endif
