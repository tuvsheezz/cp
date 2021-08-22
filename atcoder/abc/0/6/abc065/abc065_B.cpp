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
  ll n, a[MAX_N] = {}, haha = 1;
  vector<ll> path;
  cin >> n;
  repa(i, 0, n)
  {
    cin >> a[i + 1];
  }
  path.push_back(1);
  while (1)
  {
    path.push_back(a[path[haha - 1]]);
    if (a[path[haha - 1]] == 2)
      break;
    if (haha > n)
    {
      cout << "-1\n";
      return 0;
    }
    haha++;
  }
  cout << haha << '\n';
  return 0;
}