#include <bits/stdc++.h>
#define ll long long
template <typename T, typename U>
inline bool amax(T &x, U y)
{
  return (x < y) ? (x = y, true) : false;
}
using namespace std;
int main()
{
  int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
  int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

  ll N;
  cin >> N;
  vector<string> g(N);
  for (int i = 0; i < N; i++)
    cin >> g[i];

  string ans;
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      for (int k = 0; k < 8; k++)
      {
        string cur;
        for (int t = 0; t < N; t++)
        {
          int ni = i + dx[k] * t;
          int nj = j + dy[k] * t;
          ni %= N, nj %= N;
          if (ni < 0)
            ni += N;
          if (nj < 0)
            nj += N;
          cur.push_back(g[ni][nj]);
        }
        amax(ans, cur);
      }
  cout << ans << endl;
  return 0;
}
