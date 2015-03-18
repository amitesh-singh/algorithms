#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <cstdlib>

//TODO: solve this by using BFS
// it would be faster than DFS since we know the start and end point.
// we just need to check whether they are connected or not.
using namespace std;

struct Pos
{
   int x, y;
};

int testCases = 3;
const int ROWS = 4;
const int COLS = 4;

static bool
isSafe(int m[][COLS], int r, int c)
{
   if (m[r][c] == 2 || m[r][c] == 3)
     return true;
   if (r >=0 && r < ROWS && c >= 0 && c < COLS
       && m[r][c] == 1)
     return true;

   return false;
}

static bool
solveMazeUtil(int m[][COLS], int r, int c, Pos &end, int sol[][COLS])
{
   //Add condition for exit.
   if (r == end.y && c == end.x)
     {
        cout << "Found 3....\n";
        sol[r][c] = 1;

        return true;
     }

   if (isSafe(m, r, c))
     {
        //backtracking.. will revert to 0 if not found.
        sol[r][c] = 1;
        //move right
        if (sol[r][c + 1] == 0 && solveMazeUtil(m, r, c + 1, end, sol))
          return true;
        // move down
        if (sol[r + 1][c] == 0 && solveMazeUtil(m, r + 1, c, end, sol))
          return true;

        //move left
        if (sol[r][c - 1] == 0 && solveMazeUtil(m, r, c - 1, end, sol))
          return true;
        //move up
        if (sol[r - 1][c] == 0 && solveMazeUtil(m, r - 1, c, end, sol))
          return true;

        sol[r][c] = 0;

        return false;
     }

   return false;
}


static bool
solveMaze(int m[][COLS], Pos &start, Pos &end)
{
   int sol[ROWS][COLS];
   memset(sol, 0, ROWS * COLS * sizeof(int));

   bool ret = solveMazeUtil(m, start.y, start.x, end, sol);

   return ret;
}

int main()
{
   freopen("input.txt", "r", stdin);

   int num;
   char c;
   char buf[2];
   int m[ROWS][COLS];
   Pos startPos, endPos;
   for (int test = 1; test <= testCases; ++test)
     {
        cin >> num;

        for (int i = 0; i < ROWS; ++i)
          {
             for (int j = 0; j < COLS; ++j)
               {
                  cin >> c;
                  memset(buf, 0, 2);
                  sprintf(buf, "%c", c);
                  m[i][j] = atoi(buf);
                  if (m[i][j] == 2)
                    {
                       startPos.x = j;
                       startPos.y = i;
                    }
                  else if (m[i][j] == 3)
                    {
                       endPos.x = j;
                       endPos.y = i;
                    }
               }
          } //done with reading matrix.

        bool ret = solveMaze(m, startPos, endPos);

        cout << "#" << test << " " << ret << endl;
     }
   return 0;
}

