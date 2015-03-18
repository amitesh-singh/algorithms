#include "graph.h"
#include <cstdio>

int test_case = 0;
int main()
{
   Graph g(5, false);

   g.addEdges(0, 1);
   g.addEdges(0, 2);
   g.addEdges(1, 2);
   g.addEdges(2, 3);
   g.addEdges(3, 4);

   g.printPath(0, 4);
   cout << endl;
   g.printPath(1, 3);
   cout << endl;
   return 0;
}
