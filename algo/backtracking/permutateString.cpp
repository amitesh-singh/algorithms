#include <iostream>
#include <string>

using namespace std;

int T;
string str;

static void
permuteString(string soFar, string rest)
{
  // base case
  if (rest.empty())
  {
    cout << soFar << endl;
  }
  else
  {
    //recursive case
    for (int i = 0; i < rest.length(); ++i)
    {
      string remaining = rest.substr(0, i) + rest.substr(i + 1);
      permuteString(soFar + rest[i], remaining);
    }

  }

}

int main()
{
  freopen("input.txt", "r", stdin);

  cin >> T; // get the total no. of test cases.
  for (int test = 1; test <= T; ++test)
  {
    cin >> str;

    permuteString("", str);
  }

  return 0;
}
