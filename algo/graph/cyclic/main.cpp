#include "graph.h"
#include <cstdio>
#include <cstring>

int TestCases;
int  testCase;
int V, E;
int e1, e2;

int main()
{
   freopen("input.txt", "r", stdin);
   cin >> TestCases;

   for (testCase = 1; testCase <= TestCases; ++testCase)
     {
        cin >> V >> E;

        Graph g(V, true);
        cout << "START------------------------\n";
        for (int i = 0; i < E; ++i)
          {
             cin >> e1 >> e2;
             cout << "(" << e1 << "," << e2 << ") ";
             g.addEdge(e1, e2);
          }
        cout << endl;
        cout << "Is Graph cycle: " << g.isCyclic() << endl;
        cout << "END------------------------\n";
     }

   return 0;
}
