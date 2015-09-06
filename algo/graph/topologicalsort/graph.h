#include <iostream>
#include <list>
#include <stack>
#include <cstring>

using namespace std;

class Graph
{
   int _V;
   list<int> *adj;
 public:
    Graph(int V):_V(V), adj(new list<int>[_V])
      {
      }

    ~Graph()
      {
         delete [] adj;
      }

    void addEdge(int e1, int e2)
      {
         adj[e1].push_back(e2);
      }

    //Our topological sorting code.
    // First do DFS and after finish (or when the node is visited/turned black),
    // push the node into STACK
    enum Color {white, gray, black};

    void topologicalSortUtil(int source, Color color[], stack<int> &s)
      {
         //Discovered
         color[source] = gray;

         list<int>::iterator  itr = adj[source].begin();
         for (; itr != adj[source].end(); ++itr)
           {
              if (color[*itr] == white)
                {
                   color[*itr] = gray;
                   topologicalSortUtil(*itr, color, s);
                }
           }

         //Finished
         color[source] = black;
         s.push(source);
      }

    void topologicalSort()
      {
         Color *color = new Color[_V];
         stack<int> s;
         for (int i = 0; i < _V; ++i)
           {
              color[i] = white;
           }
         // or i could do memset() too.
         for (int i = 0; i < _V; ++i)
           {
              if (color[i] == white)
                topologicalSortUtil(i, color, s);
           }

         cout << "topological sort: " << endl;
         while (!s.empty())
           {
              cout << s.top() << " ";
              s.pop();
           }
         cout << endl;
         delete [] color;
      }

    void findPathsUtil(int s, int t, Color color[], int paths[])
      {
         color[s] = gray;

         list<int>::iterator itr = adj[s].begin();
         for (; itr!= adj[s].end(); ++itr)
           {
              if (*itr == t)
                paths[s] = paths[s] + 1;
              else
                {
                   if (color[*itr] == white)
                     {
                        color[*itr] = gray;
                        findPathsUtil(*itr, t, color, paths);
                     }
                   paths[s] += paths[*itr];
                }
           }
         color[s] = black;
      }

    int findPaths(int s, int t)
      {
         Color *color = new Color[_V];
         int *paths = new int[_V];

         memset(paths, 0, _V);
         memset(color, 0, _V);

         //paths[s] = 1;

         findPathsUtil(s, t, color, paths);

         delete [] color;
         int ret = paths[s];
         delete [] paths;

         return ret;
      }

    void topoSortUtil(int s, Color color[], int arr[], int &i)
      {
         color[s] = gray;

         list<int>::iterator itr = adj[s].begin();
         for (; itr != adj[s].end(); ++itr)
           {
              if (color[*itr] == white)
                {
                   color[*itr] = gray;
                   topoSortUtil(*itr, color, arr, i);
                }
           }
         color[s] = black;
         //cout << "s: " << s << " is finished\n";
         arr[i++] = s;
      }

    int findPathsAfterTS(int s, int t)
      {
         //First run Topological sort and then sort it out.
         Color *color = new Color[_V];
         int *arr = new int[_V];

         memset(color, 0, _V);
         memset(arr, -1, _V);
         int i = 0;

         topoSortUtil(s, color, arr, i);

         cout << "topological sort: " << i << endl;
         for (int j = i - 1; j >= 0; --j)
           {
              cout << arr[j] << " ";
           }

         int *paths = new int[t + 1];
         paths[t] = 1;
         for (int j = t - 1; j >= 1; ++j)
           {
              arr[j] = 0;
           }
         cout << endl;

         delete [] paths;
         delete [] color;
         delete [] arr;

         return 0;
      }
};
















