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
#define sort_vec(v) sort(v.begin(), v.end())
#define sort_arr(v, n) sort(v, v + n)
#define MOD2 998244353

#define MAX_N 100100

void solve()
{
  ll n, k, a[MAX_N], spl = 1, b[MAX_N];
  map<ll, ll> next_map;
  cin >> n >> k;
  repa(i, 0, n)
  {
    cin >> a[i];
    b[i] = a[i];
  }
  cout << endl
       << "-----" << endl;
  repa(i, 0, n)
  {
    cout << a[i] << " ";
  }
  sort(b, b + n);
  cout << endl
       << "-----" << endl;
  repa(i, 0, n)
  {
    cout << b[i] << " ";
  }
  cout << endl
       << "-----" << endl;
  repa(i, 0, n - 1)
  {
    next_map[b[i]] = b[i + 1];
  }
  for (auto const &x : next_map)
  {
    cout << x.first << " " << x.second << endl;
  }
  cout << endl
       << "-----" << endl;
  repa(i, 0, n - 1)
  {
    ll c = next_map[a[i]];
    if (a[i + 1] != c)
      spl++;
    if (a[i + 1] != c)
      cout << i << " ";
  }
  cout << endl;
  cout << "-----" << endl;
  if (spl <= k)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}

int main()
{
  FAST;
  ll t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}