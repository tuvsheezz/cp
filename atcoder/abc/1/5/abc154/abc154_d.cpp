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
#define MAX_N 200100

int main()
{
  FAST;
  ll n, k;
  dd a[MAX_N], s = 0, mx = 0;
  cin >> n >> k;
  repa(i, 0, n)
  {
    cin >> a[i];
    if (i < k)
    {
      s += (1 + a[i]) / 2;
    }
  }
  mx = s;
  repa(i, 0, n - k)
  {
    s += (a[k + i] + 1) / 2 - (a[i] + 1) / 2;
    if (s > mx)
      mx = s;
  }
  cout << setprecision(10) << mx << endl;
  return 0;
}