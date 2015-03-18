#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;


//Question:
// Find out the no. of 1s in matrix which are connected in left, right,
// top and bottpm
int N;

struct Pos
{
   int r_, c_;
   Pos(int r, int c): r_(r), c_(c) {}
};

static bool
isSafe(int **m, int r, int c)
{
   if (r >= 0 && r < N && c >= 0 && c < N
       && m[r][c] == 1)
     return true;

   return false;
}

static void
_util(int **m, int **sol, int r, int c, int &ret)
{
   if (sol[r][c] == 1)
     return;
   if (!isSafe(m, r, c))
        return;

   sol[r][c] = 1;
   //check left, right, top, bottom and diagonals = 8 directions

   //Left
   if (isSafe(m, r, c - 1) && !sol[r][c - 1])
     {
        ret++;
        _util(m, sol, r, c - 1, ret);
     }
   //check right
   if (isSafe(m, r, c + 1) && !sol[r][c + 1])
     {
        ret++;
        _util(m, sol, r, c + 1, ret);
     }

   //check Up
   if (isSafe(m, r - 1, c) && !sol[r - 1][c])
     {
        ret++;
        _util(m, sol, r - 1, c, ret);
     }
   // check Down
   if (isSafe(m, r + 1, c) && !sol[r + 1][c])
     {
        ret++;
        _util(m, sol, r + 1, c, ret);
     }
}

static int
_findMaxInfectedArea(int **m, int **sol, vector<Pos> &posList)
{
   int ret;
   int Max = -1;
   for (int i = 0; i < posList.size(); ++i)
     {
        ret = 1;
        _util(m, sol, posList[i].r_, posList[i].c_, ret);
        if (Max < ret)
          Max = ret;
     }

   return Max;
}

int Answer;
int TestCases;
int main()
{
   freopen("area_input.txt", "r", stdin);
   cin >> TestCases;
   vector<Pos> posList;
   for (int test = 1; test <= TestCases; ++test)
     {
        cin >> N;
        posList.clear();

        int **m = new int*[N];
        int **sol = new int*[N];
        for (int i = 0; i < N; ++i)
          {
             m[i] = new int[N];
             sol[i] = new int[N];
          }

        //Lets read the matrix
        for (int i = 0; i < N; ++i)
          {
             for (int j = 0; j < N; ++j)
               {
                  cin >> m[i][j];
                  sol[i][j] = 0;
                  if (m[i][j] == 1)
                    posList.push_back(Pos(i, j));
               }
          }

        Answer = _findMaxInfectedArea(m, sol, posList);
        cout << "#" << test << " " << Answer << endl;

        //cleaning
        for (int i = 0; i < N; ++i)
          {
             delete []m[i];
             delete []sol[i];
          }

        delete [] m;
        delete [] sol;
     }

   return 0;
}
