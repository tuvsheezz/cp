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
#define vsorta(v) sort(v.begin(), v.end())
#define vsortd(v) sort(v.begin(), v.end(), greater<>())
#define sort_arr(v, n) sort(v, v + n)
#define MOD2 998244353
#define MAX_N 100100

int main()
{
  FAST;
  ll n, k, d, ans = 0;
  cin >> n >> k;
  map<ll, bool> mp;
  repa(i, 0, k)
  {
    cin >> d;
    repa(j, 0, d)
    {
      ll g;
      cin >> g;
      mp[g] = true;
    }
  }
  repa(i, 0, n)
  {
    if (!mp[i + 1])
      ans++;
  }
  cout << ans << '\n';
  return 0;
}