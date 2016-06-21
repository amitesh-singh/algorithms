#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int N, B, P;
int K;

struct Canon
{
  int x, y;
  float p;
  bool destroyed;

  Canon(): x(0), y(0), p(0), destroyed(false)
  {
  }

  void explodeBomb(int r, int c, float p1)
  {
    float d = abs(x - r - 1) + abs(y - c - 1);
    float m = p1/((1 + d) * 1.0f);

    p = p - m;
  //  cout << "p: " << p << endl;
    if (p <= 0)
    {
      //cout << "setting destroyed to true";
      destroyed = true;
      p = 0;
    }
  }
};

Canon canons[100];

int missiles = INT_MAX;

int findRemainingBombs(Canon (&canon)[100])
{
  int ret = 0;
    for (int i = 0; i < K; ++i)
    {
      if (!canon[i].destroyed)
        ret++;
    }

    return ret;
}

void _solve(int r, int c, int b, Canon (&canon)[100])
{
  if (b >= B )
  {
  //  cout << "All bombs are used\n";
    int remBombs = findRemainingBombs(canon);
    cout << "remaining bombs: " << remBombs << endl;
    //printCanons();

    if (missiles > remBombs)
    {
      missiles = remBombs;
    }
  }
  int j = c;
  for (int i = r; i < N; ++i)
  {
    for (; j < N; ++j)
    {
      Canon tmpCanons[100];
      for (int k = 0; k < K; ++k)
      {
        tmpCanons[k] = canon[k];
        tmpCanons[k].explodeBomb(i, j, P);
      }

      _solve(i, j, b + 1, tmpCanons);

    }
    j = 0;
  }
}

void SolveProblem(int r, int c, int b, Canon (&canon)[100])
{
  _solve(0, 0, 0, canon);
}

int main()
{
  int T;

  freopen("bomb_input.txt", "r", stdin);
  cin >> T;

  for (int t = 1; t <= T; ++t)
  {
      cin >> N >> B >> P;
      cin >> K;

      for (int i = 0; i < K; ++i)
      {
        cin >> canons[i].x >> canons[i].y >> canons[i].p;
        canons[i].destroyed = false;
      }

      SolveProblem(0, 0, 0, canons);

      cout << "Answer: " << missiles << endl;
      missiles = INT_MAX;
  }

  return 0;
}
