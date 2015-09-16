#include <iostream>
#include <cstdio>

using namespace std;

int matrix[100][20];
   //rows, column, k times flipping
int N, M, K;
bool visited[100];
int candidates[100];


bool compareRows(int r1, int r2)
{
   for (int i = 0; i < M; ++i)
     {
        if (matrix[r1][i] != matrix[r2][i])
          return false;
     }

   return true;
}

int main()
{
   freopen("flip_input.txt", "r", stdin);
   cin >> N >> M >> K;
  // cout << N << " " << M << " " << K << endl;

   //Take the max value
   int candCount = 0;
   for (int i = 0; i < N; ++i)
     {
        visited[i] = false;
        int x = K;
        for (int j = 0; j < M; ++j)
          {
             cin >> matrix[i][j];
   //          cout << matrix[i][j] << " ";
             if (matrix[i][j] == 0)
               --x;
          }
        if (x % 2 == 0)
          {
             candidates[candCount++] = i;
          }
     }

   int max = 0;
   for (int i = 0; i < candCount; ++i)
     {
        int j = i + 1;
        int occurrence = 1;
        while (j < candCount)
          {
             if (visited[j] == false &&
                 compareRows(i, j))
               {
                  ++occurrence;
                  visited[j] = true;
               }
             j++;
          }
        if (max < occurrence)
          max = occurrence;
     }

   cout << max << endl;

   return 0;
}
