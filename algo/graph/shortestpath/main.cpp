#include "graph.h"


int main()
{
   Graph g(3);

   g.addEdges(0, 1);
   g.addEdges(1, 2);

   //run our shortest distance algorithms for 0 vertex
   g.shortestD(0);
   g.shortestD(1);
   g.shortestD(2);

   return 0;
}
