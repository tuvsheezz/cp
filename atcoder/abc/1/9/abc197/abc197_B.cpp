#include <bits/stdc++.h>
using namespace std;
#define FAST                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define ll long long
#define dd double
#define ull unsigned long long
#define str string
#define ivec vector<ll>
#define dvec vector<double>
#define repa(i, s, e) for (ll i = s; i < e; i++)
#define repd(i, s, e) for (ll i = s; i >= e; i--)
#define repin(a, n)          \
  for (ll i = 0; i < n; i++) \
  cin >> a[i]
#define vsorta(v) sort(v.begin(), v.end())
#define vsortd(v) sort(v.begin(), v.end(), greater<>())
#define sort_arr(v, n) sort(v, v + n)
#define MOD2 998244353
#define MAX_N 100100

int main()
{
  FAST;
  ll h, w, x, y, ans = 0;
  char a[110][110];
  cin >> h >> w >> x >> y;
  x--;
  y--;
  repa(i, 0, h)
  {
    repa(j, 0, w)
    {
      cin >> a[i][j];
    }
  }
  repd(i, y, 0)
  {
    if (a[x][i] == '#')
      break;
    ans++;
  }
  repd(i, x, 0)
  {
    if (a[i][y] == '#')
      break;
    ans++;
  }
  repa(i, y, w)
  {
    if (a[x][i] == '#')
      break;
    ans++;
  }
  repa(i, x, h)
  {
    if (a[i][y] == '#')
      break;
    ans++;
  }
  cout << ans - 3 << '\n';
  return 0;
}