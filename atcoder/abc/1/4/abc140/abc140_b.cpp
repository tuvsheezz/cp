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
  ll n, ans = 0;
  cin >> n;
  vector<ll> a(n, 0), b(n, 0), c(n - 1, 0);
  repa(i, 0, n) { cin >> a[i]; };
  repa(i, 0, n) { cin >> b[i]; };
  repa(i, 0, n - 1) { cin >> c[i]; }
  repa(i, 0, n)
  {
    ans += b[a[i] - 1];
    if (i < n - 1)
      if (a[i + 1] == a[i] + 1)
        ans += c[a[i] - 1];
  }
  cout << ans << endl;
  return 0;
}