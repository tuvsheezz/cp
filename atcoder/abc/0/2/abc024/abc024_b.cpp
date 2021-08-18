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
#define MAX_N 2001000

int main()
{
  FAST;
  ll n, t, a;
  cin >> n >> t;
  vector<ll> vec(MAX_N, 0);
  repa(i, 0, n)
  {
    cin >> a;
    vec[a] += 1;
    vec[a + t] -= 1;
  }
  ll c = 0;
  repa(i, 1, MAX_N)
  {
    vec[i] += vec[i - 1];
    if (vec[i] > 0)
      c++;
  }
  cout << c << endl;
  return 0;
}