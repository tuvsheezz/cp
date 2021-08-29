#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long
#define dd double
#define ull unsigned long long
#define str string
#define ivec vector<ll>
#define dvec vector<double>
#define repa(i, s, e) for (ll i = s; i < e; i++)
#define repd(i, s, e) for (ll i = s; i >= e; i--)
#define vsorta(v) sort(v.begin(), v.end())
#define vsortd(v) sort(v.begin(), v.end(), greater<>())
#define sort_arr(v, n) sort(v, v + n)
#define MOD2 998244353
#define MAX_N 100100

ll rl() { ll n; cin >> n; return n; }

int main()
{
  FAST;
  vector<ll> pa;
  ll n = rl();
  repa(i, 0, n) {
    ll a = rl(), p = rl(), x = rl();
    if(x > a) pa.push_back(p);
  }
  if(pa.empty()) { cout << "-1\n"; return 0; }

  vsorta(pa);
  cout << pa[0] << endl;
  return 0;
}
