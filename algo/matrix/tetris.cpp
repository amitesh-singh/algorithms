#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int testCases;
int N;

static void
_printMatrix(int **m)
{
   for (int i = 0; i < N; ++i)
     {
        for (int j = 0; j < N; ++j)
          cout << m[i][j] << " ";
        cout << endl;
     }
}

enum {
     HOR = 0,
     VER = 1
};

struct Object
{
   int _r, _c;
   int _type;

   Object(int r, int c, int type):
     _r(r), _c(c), _type(type)
   {
   }
   void print()
     {
        //cout << "type: " << _type << "(" << _r << "," << _c << ")";
        //cout << endl;
     }

   bool isSafe(int **m, int r, int c)
     {
        if (r >= 0 && r < N && c >= 0 && c < N
            && m[r][c] == 0)
          return true;

        return false;
     }

   //move down a step
   bool moveDown(int **m)
     {
        bool ret = false;
        if (_type == HOR)
          {
             //check next bottom 
             if (isSafe(m, _r + 1, _c)
                 && isSafe(m, _r + 1, _c + 1))
               {
                  m[_r][_c] = 0;
                  m[_r][_c + 1] = 0;
                  m[_r + 1][_c] = 1;
                  m[_r + 1][_c + 1] = 1;
                  ret = true;
                  _r = _r + 1;
               }
             else
               {
                  //cout << "No place to move: (" << _r << "," << _c << ")\n";
               }
          }
        else if (_type == VER)
          {
             if (isSafe(m, _r + 2, _c)
                 && isSafe(m, _r + 3, _c))
               {
                  m[_r][_c] = 0;
                  m[_r + 1][_c] = 0;
                  m[_r + 2][_c] = 1;
                  m[_r + 3][_c] = 1;
                  ret = true;
                  _r = _r + 2;
               }
             else
               {
                  //cout << "No place to move: (" << _r << "," << _c << ")\n";
               }
          }

        return ret;
     }
};

static bool
isNeighbour(int **m, int r, int c)
{
   if (r >= 0 && r < N && c >= 0 && c < N &&
       m[r][c] == 1)
     return true;

   return false;
}

static void
_findObjectsUtil(int **m, int r, int c,
                 int **sol, vector<Object> &objList)
{
   if (sol[r][c] == 1) return;

   if (isNeighbour(m, r, c))
     {
        sol[r][c] = 1;
        //check Right
        if (isNeighbour(m, r, c + 1) && sol[r][c + 1] == 0 && m[r][c + 1] == 1)
          {
             objList.push_back(Object(r, c, HOR));
             sol[r][c + 1] = 1;
             return;
          }
        else if (isNeighbour(m, r + 1, c) && sol[r + 1][c] == 0 &&
                 m[r + 1][c] == 1)
          {
             objList.push_back(Object(r, c, VER));
             sol[r + 1][c] = 1;
             return;
          }
     }

   return;
}

static void
_findObjects(int **m, int **sol, vector<Object> &objList)
{
   for (int i = 0; i < N; ++i)
     {
        for (int j = 0; j < N; ++j)
          {
             _findObjectsUtil(m, i, j, sol, objList);
          }
     }
}

struct CompareObject
{
   inline bool operator()(const Object &lhs, const Object &rhs)
     {
        return lhs._r > rhs._r;
     }
};

int main()
{
   freopen("tetris_input.txt", "r", stdin);
   cin >> testCases;

   for (int test = 1; test <= testCases; ++test)
     {
        cin >> N;

        vector<Object> objList;

        int **m = new int*[N];
        int **sol = new int*[N];
        for (int i = 0; i < N; ++i)
          {
             m[i] = new int[N];
             sol[i] = new int[N];
          }

        for (int i = 0; i < N; ++i)
          {
             for (int j = 0; j < N; ++j)
               {
                  cin >> m[i][j];
                  sol[i][j] = 0;
               }
          }

        _printMatrix(m);

        //Write your algo here

        //find objects of type 1X2 and 2X1
        _findObjects(m, sol, objList);

        sort(objList.begin(), objList.end(), CompareObject());
        cout << "After sorting based on row\n";
        for (int i = 0; i < objList.size(); ++i)
          {
             objList[i].print();
          }

        //keep running until all objects reaches at bottom
        int steps = 0;
        bool ret = false;
        while (1)
          {
             cout << "step: " << ++steps << "   ";
             ret = false;
             for (int i = 0; i < objList.size(); ++i)
               {
                  if (objList[i].moveDown(m) == true)
                    {
                       ret = true;
                    }
               }
             if (!ret)
               break;
          }

        cout << "Final matrix: \n";
        _printMatrix(m);

        for (int i = 0; i < N; ++i)
          {
             delete []m[i];
             delete [] sol[i];
          }
        delete []m;
        delete [] sol;

        cout << "*****************************\n";
     }

   return 0;
}

