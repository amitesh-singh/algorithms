#include "graph.h"
#include <cstdio>

int test_case = 0;
int main()
{
   freopen("input.txt", "r", stdin);

   //read the test case
   cin >> test_case;
   int V;
   for (int test = 1; test <= test_case; ++test)
     {
        // read the no. of vertices
        cin >> V;
        Graph g(V, false);
        for (int i = 0; i < V; ++i)
          {
             int e1, e2;
             //read edges.
             cin >> e1 >> e2;
             g.addEdges(e1, e2);
          }
        g.BFS(0);
        //this function finds out the shorted distance of 0 to other 
        // vertices
        g.shortestSD(0);

        cout << "Cormen book implementation:\n";
        g.BFSCormen(0);
     }

   return 0;
}
