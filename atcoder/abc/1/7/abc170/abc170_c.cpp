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
  ll x, n, a[444] = {0}, g, mn = 2 * MAX_N, ans = 0;
  cin >> x >> n;
  repa(i, 0, 444)
  {
    a[i] = abs(x - (i - 200));
  }
  repa(i, 0, n)
  {
    cin >> g;
    a[g + 200] = MAX_N;
  }
  repa(i, 1, 400)
  {
    if (a[i] < mn)
    {
      mn = a[i];
      ans = i;
    }
  }
  cout << ans - 200 << '\n';
  return 0;
}