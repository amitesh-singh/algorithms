#include <iostream>
#include <list>
#include <stack>
#include <cstdio>

using namespace std;

class Graph
{
   bool directed;
   int V;
   list<int> *adj; //Adjacency list

public:
   // n -> no .of vetices
   // dir -> directed or undirected.
   Graph(int n, bool dir): directed(dir), V(n), adj(new list<int>[V])
   {
   }

   void addEdges(int v, int w)
   {
      adj[v].push_back(w);
      if (!directed)
         adj[w].push_back(v);
   }

   enum Color {white, grey, black};

   void DFSCormen(int v)
     {
        int time = 0;
        Color *color = new Color[V];
        int *d = new int[V];
        int *f = new int[V];

        for (int i = 0; i < V; ++i)
          {
             color[i] = white;
             d[i] = f[i] = 0;
          }

        stack<int> s;

        s.push(v);
        int current;
        bool reprocess = false;
        time = time + 1;
        d[v] = time;
        color[v] = grey;
        cout << endl;
        cout << v << " is discovered now\n";

        bool isAllChildrenFinished = true;
        int count = 0;

        while (!s.empty())
          {
             ++count;
             reprocess = false;
             isAllChildrenFinished = true;
             current = s.top();
             list<int>::iterator itr = adj[current].begin();
             list<int>::iterator itr2= adj[current].begin();

             for (; itr != adj[current].end(); ++itr)
               {
                  if (color[*itr] == white)
                    {
                       color[*itr] = grey;
                       s.push(*itr);
                       isAllChildrenFinished = false;
                       reprocess = true;
                       d[*itr] = ++time;
                       cout << (int)(*itr) << " is discovered now\n";
                       break;
                    }
                  else if (color[*itr] == grey)
                    {
                       isAllChildrenFinished = true;
                    }
               }

             if (reprocess)
               continue;

             if (isAllChildrenFinished)
               {
                  f[current] = ++time;
                  s.pop();
                  color[current] = black;
                  cout << current << "(" << d[current] << "/" << f[current] << ") is black now\n";
               }
          }
        cout << "total iterations in while loop: " << count << endl;
        cout << endl;

        delete [] color;
        delete [] f;
        delete [] d;
     }

}; //class ends

int T;
int V, E;
int v1, v2;

int main()
{
   // Iterative Graph traveral

   freopen("input.txt", "r", stdin);
   cin >> T;

   for (int testCase = 1; testCase <= T; ++testCase)
     {
        cin >> V >> E;
        Graph g(V, true);

        for (int i = 0; i < E; ++i)
          {
             cin >> v1 >> v2;
             g.addEdges(v1, v2);
          }

        g.DFSCormen(0);
     }

   return 0;
}
