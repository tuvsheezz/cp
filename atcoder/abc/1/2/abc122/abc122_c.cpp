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
  ll n, q, l, r;
  string s;
  cin >> n >> q;
  vector<ll> a(n + 2, 0);
  cin >> s;
  repa(i, 1, n)
  {
    a[i] = a[i - 1];
    if (s[i] == 'C' && s[i - 1] == 'A')
      a[i]++;
  }

  repa(i, 0, q)
  {
    cin >> l >> r;
    cout << a[r - 1] - a[l - 1] << endl;
  }

  return 0;
}