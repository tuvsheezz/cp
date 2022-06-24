#include <bits/stdc++.h>
using namespace std;

int n, a, b, c, ans = INT_MAX;
vector<int> p(10, 0), q(10, 0);
int qqqq = 0;

void dfs(int cur)
{
  if (cur == n)
  {
    int ta = 0, tb = 0, tc = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
      if (q[i] == 0)
        ta += p[i];
      if (q[i] == 1)
        tb += p[i];
      if (q[i] == 2)
        tc += p[i];
      if (q[i] == 3)
        cnt++;
    }

    if (ta == 0 || tc == 0 || tb == 0)
      return;

    ans = min(ans, (n - cnt - 3) * 10 + abs(a - ta) + abs(b - tb) + abs(c - tc));
    return;
  }
  q[cur] = 0;
  dfs(cur + 1);
  q[cur] = 1;
  dfs(cur + 1);
  q[cur] = 2;
  dfs(cur + 1);
  q[cur] = 3;
  dfs(cur + 1);
}

int main()
{
  cin >> n >> a >> b >> c;
  for (int i = 0; i < n; i++)
    cin >> p[i];

  dfs(0);

  cout << ans << '\n';
  return 0;
}
