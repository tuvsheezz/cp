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
#define MAX_N 1001000

int main()
{
  FAST;
  ll q, l, r, m = 0;
  cin >> q;
  vector<ll> vec(MAX_N, 0);
  repa(i, 0, q)
  {
    cin >> l >> r;
    vec[l] += 1;
    vec[r + 1] -= 1;
  }
  repa(i, 0, MAX_N)
  {
    vec[i + 1] += vec[i];
    m = max(m, vec[i]);
  }
  cout << m << endl;
  return 0;
}