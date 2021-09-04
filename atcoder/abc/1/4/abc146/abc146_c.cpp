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

ll digits(ll n)
{
  ll d = 1;
  while (n >= 10)
  {
    d++;
    n /= 10;
  }
  return d;
}

int main()
{
  FAST;
  ll a, b, x, l = 0, r = 1e09 + 1;
  cin >> a >> b >> x;

  while (l < r - 1)
  {
    ll mid = (l + r) / 2;
    if (x < a * mid + b * digits(mid))
      r = mid;
    else
      l = mid;
  }

  cout << l << '\n';

  return 0;
}