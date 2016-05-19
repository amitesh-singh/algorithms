#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <list>
#include <vector>

using namespace std;


/*

   input is no. of nodes along with x,y
output:
   connect all given nodes

   e.g. 4
   0--------1
   | \    / |
   |__\__/__|
   2--------3


 */


double weight[1000][1000];

struct pos
{
   int x, y;

   pos(int a, int b):x(a), y(b) {}
};


vector<pos> posList;

class Graph
{
   int n;
   list<int> *adj;
 public:
   Graph(int _n): n(_n)
   {
      adj = new list<int>[n];
   }

   void addEdge(int u, int v)
     {
        adj[u].push_back(v);

        weight[u][v] = sqrt((posList[u].x - posList[v].x) * (posList[u].x - posList[v].x) + (posList[u].y - posList[v].y) * (posList[u].y - posList[v].y));
        //adj[u].push_back(v);
     }
   //printing in adj list manner.
   void print()
     {
        for (int i = 0; i < n; ++i)
          {
            cout << i << ":";
            list<int>::iterator itr = adj[i].begin();
            for (; itr != adj[i].end(); ++itr)
              {
                 cout << *itr << ", ";
              }
            cout << endl;
          }

        cout << "weight: \n";
        for (int i = 0; i < n; ++i)
          {
             for (int j = 0; j < n; ++j)
               {
                  cout << weight[i][j] << " ";
               }
             cout << endl;
          }
     }

   void build()
     {
        // build graph, connect all components to each other
        // without any self-loop
        bool *visited = new bool[n];

        memset(visited, false, sizeof(bool) * n);

        for (int i = 0; i < n ; ++i)
          {
             for (int j = 1; j < n; ++j)
               {
                  if (visited[j] || visited[i] ||
                      i == j) continue;

                  addEdge(i, j);
                  addEdge(j, i);
               }
             visited[i] = true;
          }

          delete [] visited;
     }

   void prim(int s)
     {
     }

};

int T, N;
int main()
{
   freopen("input_xy.txt", "r", stdin);

   cin >> T;
   for (int testCase = 1; testCase <= T; ++testCase)
     {
        cin >> N;

        Graph g(N);
        posList.clear();
        for (int i = 0; i < N; ++i)
          {
             double x, y;
             cin >> x >> y;

             posList.push_back(pos(x,y));
          }
        g.build();
        g.print();
     }

   return 0;
}
