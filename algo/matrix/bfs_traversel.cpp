//We shall traverse in a matrix given a reason that adjacents blocks are
// 1s.
// Lets do this in the way we do graph bfs traversal

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

enum Color {white, grey, black};
int testCases;
int N;

int m[100][100];
int sol[100][100];

Color color[100][100];

struct Pos
{
   int r_, c_;
   Pos(int r, int c): r_(r), c_(c) {}
};

static bool
isSafe(int r, int c)
{
   if (r >= 0 && r < N && c >= 0 && c < N
       && m[r][c] == 1)
     return true;

   return false;
}

static void
_bfsUtil(int x, int y)
{
   if (isSafe(x, y) == 0) return;
   queue<Pos> q;

   q.push(Pos(x, y));

   color[x][y] = grey;

   //lets visit children

   while (!q.empty())
     {
        Pos curr = q.front();
        q.pop();
#ifdef DEBUG
        cout << "node: " << curr.r_ << ", " << curr.c_  << " is grey now" << endl;
#endif
        x = curr.r_;
        y = curr.c_;

        //Left
        if (isSafe(x, y - 1))
          {
             if (color[x][y - 1] == white)
               {
                  color[x][y - 1] = grey;
                  q.push(Pos(x, y - 1));
               }
          }

        //Right
        if (isSafe(x, y + 1))
          {
             if (color[x][y + 1] == white)
               {
                  color[x][y + 1] = grey;
                  q.push(Pos(x, y + 1));
               }
          }

        // Up
        if (isSafe(x - 1, y))
          {
             if (color[x - 1][y] == white)
               {
                  color[x - 1][y] = grey;
                  q.push(Pos(x - 1, y));
               }
          }

        //Down
        if (isSafe(x + 1, y))
          {
             if (color[x + 1][y] == white)
               {
                  color[x + 1][y] = grey;
                  q.push(Pos(x + 1, y));
               }
          }
        color[x][y] = black;
#ifdef DEBUG
        cout << "node: " << x << "," << y << " is black now\n";
#endif
        cout << "visited: " << x << ", " << y << endl;
     }
}

static void
BFS(int x, int y)
{
   _bfsUtil(x, y);
}
int x, y;

int main()
{
   freopen("matrix_bfs.txt", "r", stdin);
   cin >> testCases;

   for (int test = 1; test <= testCases; ++test)
     {
        cin >> N;
        cin >> x >> y; //starting point
        for (int r = 0; r < N; ++r)
          {
             for (int c = 0; c < N; ++c)
               {
                  cin >> m[r][c];
                  sol[r][c] = 0;
               }
          }

        cout << "# " << test << endl;

        BFS(x, y);
        cout << "############################ " << endl;
     }

   return 0;
}
