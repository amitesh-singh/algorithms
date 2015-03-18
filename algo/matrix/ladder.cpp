#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

const int ROWS = 16;
const int COLS = 16;
int testCases = 1;

static bool
isSafe(int **m, int r, int c)
{
   if (r >= 0 && r < ROWS && c >= 0 && c < COLS
       && (m[r][c] == 1 || m[r][c] == 3))
     return true;

   return false;
}

static bool
findPathUtil(int **m, int r, int c, int sol[][COLS])
{
   //check exit situation.
   if (r == ROWS - 1 && c == COLS - 1)
     {
        sol[r][c] = 1;
        return true;
     }

   if (isSafe(m, r, c))
     {
        sol[r][c] = 1;
        //move down .. first priority
        if (sol[r + 1][c] == 0 && findPathUtil(m, r + 1, c, sol))
          return true;
        //move right
        if (sol[r][c + 1] == 0 && findPathUtil(m, r, c + 1, sol))
          return true;

        sol[r][c] = 0;

        return false;
     }

   return false;
}

static bool
findPath(int **m, int r, int c)
{
   int sol[ROWS][COLS];

   memset(sol, 0, ROWS * COLS * sizeof(int));

   bool ret = findPathUtil(m, r, c, sol);

   return ret;
}

int main()
{
   freopen("ladder_input.txt", "r", stdin);

   int **m = new int*[ROWS];
   for (int i = 0; i < ROWS; ++i)
     {
        m[i] = new int[COLS];
     }
   //memset(m, 0, ROWS * COLS * sizeof(int));

   int num;
   char c;
   char buf[4];
   for (int test = 1; test <= testCases; ++test)
     {
        cin >> num;

        for (int i = 0; i < ROWS; ++i)
          {
             for (int j = 0; j < COLS; ++j)
               {
                  cout << i << "," << j << endl;
                  cin >> c;
                  memset(buf, 0, 4);
                  sprintf(buf, "%c", c);
                  m[i][j] = atoi(buf);
               }
          }

        //try first row 
        for (int t = 0; t < COLS; ++t)
          {
             //end position is the right bottom
             bool ret = findPath(m, 0, t);
             cout << "#" << t << " " << ret << endl;
          }
     }

   for (int i = 0; i < ROWS; ++i)
     {
        delete [] m[i];
     }

   delete [] m;

   return 0;
}
