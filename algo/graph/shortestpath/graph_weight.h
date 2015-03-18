#include <iostream>
#include <list>
#include <queue>

using namespace std;

//Dkishtra Algorithm
// This will only work on +ve edges.
// will fail for negative edges ---> Beware of this.

class Graph
{
   struct Weight
     {
        int e1, e2;
        int w;
        Weight(int _e1, int _e2, int _w): e1(_e1), e2(_e2),
                                          w(_w)
        {
        }
     };
   int V;
   list<int> *adj;
   vector<Weight> weights;
 public:
   int getWeight(int e1, int e2)
     {
        for (int i = 0; i < weights.size(); ++i)
          {
             if (weights[i].e1 == e1 && weights[i].e2 == e2)
               return weights[i].w;
          }

        return 0;
     }

   Graph(int n): V(n)
   {
      adj = new list<int>[V];
   }

   ~Graph()
     {
        delete [] adj;
     }

   void addEdges(int e1, int e2, int w)
     {
        adj[e1].push_back(e2);
        adj[e2].push_back(e1);
        weights.push_back(Weight(e1, e2, w));
        weights.push_back(Weight(e2, e1, w));
     }

   //we gonna do BFS
   void shortestDUtil(int v, bool visited[], int d[])
     {
        queue<int> q;

        q.push(v);
        visited[v] = true;
        d[v] = 0;

        while (!q.empty())
          {
             int current = q.front();
             q.pop();
             cout << current << ",";

             list<int>::iterator itr = adj[current].begin();
             for (; itr != adj[current].end(); ++itr)
               {
                  if (!visited[*itr])
                    {
                       visited[*itr] = true;
                       q.push(*itr);
                       d[*itr] = d[current] + getWeight(current, *itr);
                    }
               }
          }
     }

   void shortestD(int v)
     {
        bool *visited = new bool[V];
        int *d = new int[V];

        for (int i = 0; i < V; ++i)
          {
             visited[i] = false;
             d[i] = 0;
          }

        cout << "***********START**************\n";
        shortestDUtil(v, visited, d);
        cout << endl;

        for (int i = 0; i < V; ++i)
          {
             cout << "d[" << i << "]: " << d[i] << endl;
          }
        cout << "***********END**************\n";

        delete [] visited;
        delete [] d;
     }
};
