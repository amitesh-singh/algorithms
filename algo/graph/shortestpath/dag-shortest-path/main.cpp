#include "graph.h"

#include <cstdio> // for freopen()

int TestCases;
int testCase;
int V, E, e1, e2, w;

int main()
{
   freopen("input.txt", "r", stdin);

   cin >> TestCases;

   for (testCase = 1; testCase <= TestCases; ++testCase)
     {
        cin >> V >> E;

        // Its a DAG
        Graph g(V);
        for (int i = 0; i < E; ++i)
          {
             cin >> e1 >> e2 >> w;
             g.addEdge(e1, e2, w);
          }

        g.dagSingleSourceShortestPath(0);
     }

   return 0;
}
