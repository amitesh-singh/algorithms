#include "graph.h"

#include <cstdio> // for freopen()

int TestCases;
int testCase;
int V, E, e1, e2, w;
int s;
int main()
{
   freopen("input.txt", "r", stdin);

   cin >> TestCases;

   for (testCase = 1; testCase <= TestCases; ++testCase)
     {
        cin >> V >> E;

        cout << "**** START *****\n";
        // Its a DAG
        Graph g(V);
        for (int i = 0; i < E; ++i)
          {
             cin >> e1 >> e2 >> w;
             g.addEdge(e1, e2, w);
          }
        cin >> s;

        g.dagSingleSourceShortestPath(s);
        cout << " ********* END ******\n";
     }

   return 0;
}
