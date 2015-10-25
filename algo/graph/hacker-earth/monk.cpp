#include <iostream>
#include <vector>
#include <cstdio>
#include <list>
#include <cstdlib>
#include <cstring>

using namespace std;


int T, E;
int u, v;
int Max;

struct Edge
{
   int u, v;
   Edge(int x, int y): u(x), v(y) {}
};
int main()
{
   freopen("input_roads.txt", "r", stdin);
   vector<Edge> edges;

   cin >> T;

   for (int testCase = 1; testCase <= T; ++testCase)
     {
        cin >> E;
        Max = -1;
        edges.clear();

        for (int i = 0; i < E; ++i)
          {
             cin >> u >> v;
             edges.push_back(Edge(u - 1, v - 1));

             if (u > Max)
               Max = u;
             if (v > Max)
               Max = v;
          }

        //cout << "Max: " << Max << endl;
        bool *visited = new bool[Max];

        memset(visited, 0, Max);
        for (int i = 0; i < edges.size(); ++i)
          {
             visited[edges[i].u] = true;
             visited[edges[i].v] = true;
          }
        int answer = 0;
        for (int i = 0; i < Max; ++i)
          {
             if (visited[i]) ++answer;
          }

        cout << answer << endl;
     }


   return 0;
}
