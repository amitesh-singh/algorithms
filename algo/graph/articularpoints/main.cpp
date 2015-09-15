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

        cout << "**** START *****\n";
        // Its an undirected G
        Graph g(V, false);
        cout << "V: " << V << " E: " << E << endl;
        for (int i = 0; i < E; ++i)
          {
             cin >> e1 >> e2;
             g.addEdge(e1, e2);
          }

        g.findArtPoints();
        cout << " ********* END ******\n";
     }

   return 0;
}
