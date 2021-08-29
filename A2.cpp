#include <bits/stdc++.h>
using namespace std;

int solve()
{
  int mp[30][30], T;
  for (int i = 0; i < 30; i++)
    for (int j = 0; j < 30; j++)
      mp[i][j] = (i == j) ? 0 : -1;

  string S;
  cin >> S;
  int K, len = S.size(), ans;
  cin >> K;
  vector<int> cand;
  while (K--)
  {
    string P;
    cin >> P;
    int x = P[0] - 'A', y = P[1] - 'A';

    if (mp[x][y] == -1)
      mp[x][y] = 1;
    else
      mp[x][y] = min(mp[x][y], 1);

    for (int i = 0; i < 30; i++)
    {
      x = P[0] - 'A', y = P[1] - 'A';
      int c = i;
      while (mp[c][x] != -1)
      {
        mp[c][y] = (mp[c][y] == -1) ? mp[c][x] + 1 : min(mp[c][y], mp[c][x] + 1);
        y = c;
        x = y;
      }
      x = P[0] - 'A', y = P[1] - 'A';
      while (mp[y][i] != -1)
      {
        mp[x][i] = (mp[x][i] == -1) ? mp[y][i] + 1 : min(mp[x][i], mp[y][i] + 1);
      }
    }
  }

  for (int i = 0; i < 30; i++)
  {
    int tmp = 0;
    bool flag = true;
    for (int j = 0; j < len; j++)
    {
      int ind = S[j] - 'A';
      if (mp[ind][i] == -1)
        flag = false;
      else
        tmp += mp[ind][i];
    }

    if (flag)
      cand.push_back(tmp);
  }

  for (int i = 0; i < 26; i++)
    for (int j = 0; j < 26; j++)
      if (mp[i][j] != -1)
        printf("%c%c: %d\n", 'A' + i, 'A' + j, mp[i][j]);

  if (cand.empty())
    ans = -1;
  else
  {
    ans = cand[0];
    for (auto const &x : cand)
      ans = min(ans, x);
  }
  return ans;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++)
    printf("Case #%d: %d\n", i, solve());
  return 0;
}