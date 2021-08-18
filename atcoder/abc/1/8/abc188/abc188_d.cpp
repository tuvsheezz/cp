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
#define vsorta(v) sort(v.begin(), v.end())
#define vsortd(v) sort(v.begin(), v.end(), greater<>())
#define sort_arr(v, n) sort(v, v + n)
#define MOD2 998244353
#define MAX_N 100100

int main()
{
  FAST;
  ll n, c, a, b, p, t = 0, c_fee = 0, c_time = 0;
  vector<pair<ll, ll>> vec;
  cin >> n >> c;
  repa(i, 0, n)
  {
    cin >> a >> b >> p;
    vec.push_back(make_pair(a, p));
    vec.push_back(make_pair(b + 1, -p));
  }
  vsorta(vec);
  for (auto const &x : vec)
  {
    t += min(c, c_fee) * (x.first - c_time);
    c_time = x.first;
    c_fee += x.second;
  }

  cout << t << endl;
  return 0;
}