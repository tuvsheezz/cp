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
#define MOD2 998244353

#define MAX_N 1000000

str cyesno(bool cond)
{
  return cond ? "Yes" : "No";
}
str uyesno(bool cond)
{
  return (cond) ? "YES" : "NO";
}

ll h, w, n, a, b;
vector<pair<ll, ll>> cards;
set<ll> hh;
set<ll> ww;
map<ll, ll> hhh;
map<ll, ll> www;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> h >> w >> n;
  repa(i, 0, n)
  {
    cin >> a >> b;
    cards.push_back(make_pair(a, b));
    hh.insert(a);
    ww.insert(b);
  }
  std::set<ll>::iterator it;
  ll ind = 1;
  for (it = hh.begin(); it != hh.end(); ++it)
  {
    hhh[*it] = ind;
    ind++;
  }
  ind = 1;
  for (it = ww.begin(); it != ww.end(); ++it)
  {
    www[*it] = ind;
    ca
        ind++;
  }

  for (auto const &x : cards)
  {
    cout << hhh[x.first] << " " << www[x.second] << endl;
  }

  return 0;
}