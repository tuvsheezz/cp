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
#define vsorta(v) sort(v.begin(), v.end())
#define vsortd(v) sort(v.begin(), v.end(), greater<>())
#define sort_arr(v, n) sort(v, v + n)
#define MOD2 998244353
#define MAX_N 100100

int main()
{
  FAST;
  ll n, m, removed, k, t, rab[2][MAX_N];
  ll ind[MAX_N] = {0};
  cin >> n >> m;
  removed = 2 * n;
  repa(i, 0, n)
  {
    rab[0][i] = 0;
    rab[1][i] = 1;
  }
  vector<stack<ll>> vs(m);

  repa(i, 0, m)
  {
    cin >> k;

    repa(j, 0, k)
    {
      cin >> t;
      vs[i].push(t);
      if (i == k - 1)
      {
        ll c = i;
        while (rab[0][c] == 1)
        {
        }
      }
    }
  }

  return 0;
}