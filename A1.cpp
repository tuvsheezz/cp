#include <bits/stdc++.h>
using namespace std;

int consistency(vector<int> v1, vector<int> v2)
{
  int ans = 0;

  ans -= 2 * v1[0];
  for (auto const &x : v1)
    ans += x * 2;

  for (auto const &x : v2)
    ans += x;
  return ans;
}

int solve(string S)
{
  int len = S.size();
  vector<int> vo(30, 0);
  vector<int> co(30, 0);
  for (int i = 0; i < len; i++)
  {
    if (S[i] == 'A' || S[i] == 'E' || S[i] == 'I' || S[i] == 'O' || S[i] == 'U')
      vo[S[i] - 'A']++;
    else
      co[S[i] - 'A']++;
  }
  sort(vo.begin(), vo.end(), greater<int>());
  sort(co.begin(), co.end(), greater<int>());

  return min(consistency(vo, co), consistency(co, vo));
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++)
  {
    string s;
    cin >> s;
    printf("Case #%d: %d\n", i, solve(s));
  }

  return 0;
}