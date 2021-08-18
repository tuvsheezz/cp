#include <bits/stdc++.h>
using namespace std;

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
#define MAX_N 100100

ll n, a, c = 0;
map<ll, ll> m;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  repa(i, 0, n)
  {
    cin >> a;
    m[a]++;
  }

  for (auto const &x : m)
    c += x.second >= x.first ? x.second - x.first : x.second;

  cout << c << endl;
  return 0;
}