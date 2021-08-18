#include <bits/stdc++.h>
using namespace std;
#define FAST                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define ll long long
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
  ll n, m, t, a, b, c = 0;
  vector<ll> hei;
  map<ll, vector<ll>> path;
  cin >> n >> m;
  repa(i, 0, n)
  {
    cin >> t;
    hei.push_back(t);
  }

  repa(i, 0, m)
  {
    cin >> a >> b;
    path[a].push_back(b);
    path[b].push_back(a);
  }

  repa(i, 0, n)
  {
    bool f = true;
    for (auto const &x : path[i + 1])
    {
      if (hei[x - 1] >= hei[i])
        f = false;
    }
    if (f)
      c++;
  }
  cout << c << endl;

  return 0;
}