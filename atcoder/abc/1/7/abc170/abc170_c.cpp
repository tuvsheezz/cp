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

ll n, q, a, b;
map<ll, ll> inf;
map<ll, multiset<ll, greater<ll>>> kin;
map<ll, ll> inf_kin;
multiset<ll> mx;

int main()
{
  FAST;
  cin >> n >> q;
  repa(i, 0, n)
  {
    cin >> a >> b;
    inf[i + 1] = a;
    if (!kin[b].empty())
      mx.erase(mx.lower_bound(*kin[b].begin()));
    kin[b].insert(a);
    inf_kin[i + 1] = b;
    mx.insert(*kin[b].begin());
  }
  repa(i, 0, q)
  {
    cin >> a >> b;
    // remove
    mx.erase(mx.lower_bound(*kin[inf_kin[a]].begin()));
    kin[inf_kin[a]].erase(kin[inf_kin[a]].lower_bound(inf[a]));
    if (!kin[inf_kin[a]].empty())
      mx.insert(*kin[inf_kin[a]].begin());
    // add
    if (!kin[b].empty())
      mx.erase(mx.lower_bound(*kin[b].begin()));
    kin[b].insert(inf[a]);
    mx.insert(*kin[b].begin());
    inf_kin[a] = b;
    cout << *mx.begin() << endl;
  }
  return 0;
}