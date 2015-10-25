#include <iostream>
#include <cstdio>
#include <list>
#include <cstring>

using namespace std;

int bananaCapicity[100000];
class Graph
{
   int V;
   list<int> *adj;

 public:
   Graph(int _V): V(_V)
   {
      adj = new list<int>[V];
   }
   ~Graph()
     {
        delete [] adj;
     }

   void addEdge(int u, int v)
     {
        adj[u].push_back(v);
        adj[v].push_back(u);
     }

   void dfs(int s, bool visited[], long long &sum)
     {
        visited[s] = true;

        list<int>::iterator itr = adj[s].begin();

        for (; itr != adj[s].end(); ++itr)
          {
             if (visited[*itr] == false)
               {
                  dfs(*itr, visited, sum);
               }
          }

        //cout << "visited: " << s << endl;
        sum += bananaCapicity[s];
        //cout << "sum --->: " << sum << endl;
     }

   long long maxBananas()
     {
        long long sum = 0;
        long long max = 0;

        bool *visited = new bool[V];
        memset(visited, 0, sizeof(bool) * V);

        for (int i = 0; i < V;++i)
          {
             sum = 0;
             if (visited[i] == false)
               {
                  dfs(i, visited, sum);
               }
             //cout << "sum: " << sum << endl;
             if (sum > max)
               max = sum;
          }

        delete [] visited;

        return max;
     }

};

int T, M, N;

int main()
{
   freopen("input.txt", "r", stdin);
   cin >> T;
   //cout << T;

   for (int testCase = 1; testCase <= T; ++testCase)
     {
        cin >> N >> M;

        Graph g(N);
        for (int i = 0; i < M; ++i)
          {
             int u, v;
             cin >> u >> v;

             g.addEdge(u - 1, v - 1);
          }
        for (int i = 0; i < N; ++i)
          {
             cin >> bananaCapicity[i];
          }

       cout << g.maxBananas() << endl;
     }

   return 0;
}
