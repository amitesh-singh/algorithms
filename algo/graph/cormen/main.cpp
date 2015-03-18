#include "graph.h"

int main()
{
   Graph g(4);

   g.addEdges(0, 1);
   g.addEdges(0, 2);
   g.addEdges(1, 3);

   g.DFSCormen();
   g.BFSCormen(0);
   g.clear();

   g.setV(4);
   g.addEdges(0, 1);
   g.addEdges(0, 2);
   g.addEdges(1, 3);
   g.addEdges(1, 2);

   g.DFSCormen();

   g.BFSCormen(0);

   return 0;
}
