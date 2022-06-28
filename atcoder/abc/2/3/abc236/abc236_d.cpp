#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll ans = INT64_MIN, cc = 0;
vector<vector<ll>> A(20, vector<ll>(20, 0));
vector<bool> v(20, false);

void dfs(ll n, ll p)
{
  ll fir = -1;
  for (int i = 0; i < n; i++)
    if (!v[i])
    {
      fir = i;
      break;
    }
  if (fir == -1)
  {
    ans = max(ans, p);
    return;
  }

  v[fir] = true;
  for (int i = 0; i < n; i++)
  {
    if (!v[i])
    {
      v[i] = true;
      dfs(n, p ^ A[fir][i]);
      v[i] = false;
    }
  }
  v[fir] = false;
}

int main()
{
  ll n, N;
  cin >> N;
  n = 2 * N;
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      cin >> A[i][j];
      A[j][i] = A[i][j];
    }
  }
  dfs(n, 0);
  cout << ans << endl;
  return 0;
}
