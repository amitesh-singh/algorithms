#include "graph.h"

int TestCases;

int main()
{
    freopen("input.txt", "r", stdin);
    
    cin >> TestCases;
    for (int test = 1; test <= TestCases; ++test)
    {
        int vertices;
        cin >> vertices;
        cout << "Vertices: " << vertices << endl;
        Graph g;
        for (int i = 0; i < vertices; i++)
        {
            int v1, v2;
            cin >> v1;
            cin >> v2;

            cout << "adding " << v1 << "," << v2 << endl;
            Vertex *vert1, *vert2;
            vert1 = new Vertex(v1);
            vert2 = new Vertex(v2);

            g.addEdges(vert1, vert2);
        }
        g.BFS(g.getVertex(2));
    }
    
    return 0;
}