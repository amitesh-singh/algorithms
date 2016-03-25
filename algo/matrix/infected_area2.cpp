// Similar to infected_area.cpp, only difference is we look for diagnals directions only.

#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstdio>

using namespace std;

int testCases;
int N;

static const unsigned ARRSIZE = 100;

int m[ARRSIZE][ARRSIZE];
int sol[ARRSIZE][ARRSIZE];


struct Pos
{
   int r_, c_;
   Pos(int r, int c): r_(r), c_(c) {}
};

vector<Pos> posList;
static bool
isSafe(int r, int c)
{
   if (r >= 0 && r < N && c >= 0 && c < N
       && m[r][c] == 1)
     return true;

   return false;
}

static void
_util(int r, int c, int &ret)
{
   if (sol[r][c] == 1) return;
   if (isSafe(r, c) == 0) return;

   sol[r][c] = 1;

   if (isSafe(r - 1, c - 1) == 1 && !sol[r - 1][c - 1])
     {
        ret++;
        _util(r - 1, c - 1, ret);
     }
   if (isSafe(r + 1, c + 1) == 1
       && !sol[r + 1][c + 1])
     {
        ret++;
        _util(r + 1, c + 1, ret);
     }
   if (isSafe(r - 1, c + 1) == 1
       && !sol[r - 1][c + 1])
     {
        ret++;
        _util(r - 1, c + 1, ret);
     }
   if (isSafe(r + 1, c - 1) == 1
       && !sol[r + 1][c - 1])
     {
        ret++;
        _util(r + 1, c - 1, ret);
     }
}

static void
_findInfArea(int &ret)
{
   int res = 0;
   int max = 0;
   for (int i = 0; i < posList.size(); ++i)
     {
        res = 0;
        _util(posList[i].r_, posList[i].c_, res);
        if (res > max)
          max = res;
     }

   ret = max;
}

int main()
{
   freopen("infected_area2.txt", "r", stdin);

   cin >> testCases;
   int ret = 0;

   for (int test = 1; test <= testCases; ++test)
     {
        cin >> N;
        //row
        for (int i = 0; i < N; ++i)
          {
             //cols
             for (int j = 0; j < N; ++j)
               {
                  cin >> m[i][j];
                  sol[i][j] = 0;
                  if (m[i][j] == 1)
                    posList.push_back(Pos(i, j));
               }
          }

        _findInfArea(ret);
        cout << "#" << test << " " << ret << endl;
     }

   return 0;
}
