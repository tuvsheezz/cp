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

#define MAX_N 1000000

int main()
{
  FAST;
  ll n, m, a, b, c, d;
  cin >> n >> m;
  vector<pair<ll, ll>> st;
  vector<pair<ll, ll>> cp;
  repa(i, 0, n)
  {
    cin >> a >> b;
    st.push_back(make_pair(a, b));
  }
  repa(i, 0, m)
  {
    cin >> a >> b;
    cp.push_back(make_pair(a, b));
  }
  repa(i, 0, n)
  {
    ll mn = abs(cp[0].first - st[i].first) + abs(cp[0].second - st[i].second);
    ll ind = 0;
    repa(j, 0, m)
    {
      if (mn > abs(cp[j].first - st[i].first) + abs(cp[j].second - st[i].second))
      {
        mn = abs(cp[j].first - st[i].first) + abs(cp[j].second - st[i].second);
        ind = j;
      }
    }
    cout << ind + 1 << endl;
  }
  return 0;
}