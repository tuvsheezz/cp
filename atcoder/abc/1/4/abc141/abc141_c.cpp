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
#define sort_vec(v) sort(v.begin(), v.end())
#define sort_arr(v, n) sort(v, v + n)
#define MOD2 998244353
#define MAX_N 100100

int main()
{
  FAST;
  ll n, k, q, a;
  cin >> n >> k >> q;
  vector<ll> vec(n + 10, 0);
  repa(i, 0, q)
  {
    cin >> a;
    vec[a] += 1;
    vec[a + 1] -= 1;
  }
  repa(i, 1, n + 1)
  {
    vec[i] += vec[i - 1];
    (k + vec[i] - q > 0) ? cout << "Yes\n" : cout << "No\n";
  }
  return 0;
}