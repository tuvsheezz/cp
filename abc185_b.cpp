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
  ll n, m, t, g, prev = 0, a, b;
  cin >> n >> m >> t;
  g = n;
  repa(i, 0, m)
  {
    cin >> a >> b;
    if (a > prev + g - 1)
    {
      cout << "No\n";
      return 0;
    }
    g = min(n, prev + b - a);
    prev = b;
  }
  if (t > prev + g - 1)
    cout << "No\n";
  else
    cout << "Yes\n";

  return 0;
}