#include "Graph_Iterative.h"

int main()
{
   //undirected graph

   cout << "Directed Graph: ";
   Graph g2(3, true);

   g2.addEdges(0, 1);
   g2.addEdges(1, 2);

   cout << "corment DFS:";
   g2.DFSCormen(0);

   return 0;
}
