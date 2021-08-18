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
#define MAX_N 200200

int main()
{
  FAST;
  ll n, s[MAX_N], t[MAX_N];
  map<ll, priority_queue<int, vector<int>, greater<int>>> mp;
  cin >> n;
  repa(i, 0, n) cin >> s[i];
  repa(i, 0, n)
  {
    cin >> t[i];
    mp[i].push(t[i]);
    mp[(i + 1 + n) % n].push(t[i] + s[i]);
    mp[(i + 1 + n) % n].push(mp[i].top() + s[i]);
  }

  repa(i, 0, n)
  {
    mp[(i + 1 + n) % n].push(mp[i].top() + s[i]);
  }

  repa(i, 0, n)
  {
    cout << mp[i].top() << endl;
  }

  return 0;
}