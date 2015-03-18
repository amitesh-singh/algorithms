#include "graph.h"

int main()
{
   Graph g(4);

   g.addEdges(0, 1);
   g.addEdges(0, 2);
   g.addEdges(2, 0);
   g.addEdges(2, 1);
   g.addEdges(0, 3);
   g.addEdges(2, 3);
   g.addEdges(3, 3);

   //start the DFS from '2'
   g.DFS(2);
   cout << endl;

   //start the DFS from '0'
   g.DFS(0);
   cout << endl;

   return 0;
}
