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
  ll n, x, sum = 0, mx = 0;
  cin >> n >> x;
  vector<ll> am(n + 1, 0);
  repa(i, 0, n)
  {
    cin >> am[i];
    sum += am[i];
  }
  x = min(x, sum);

  vsortd(am);
  vector<pair<ll, ll>> mp;

  repa(i, 1, n + 1)
  {
    mp.push_back(make_pair(am[i - 1], am[i]));
  }

  ll ind = 0;

  while (x > 0)
  {
    if (x >= (mp[ind].first - mp[ind].second) * (ind + 1))
    {
      ll right = mp[ind].second + 1;
      mx += (mp[ind].first + right) * (mp[ind].first - right + 1) / 2 * (ind + 1);
      x -= (mp[ind].first - mp[ind].second) * (ind + 1);
    }
    else
    {
      ll rr = x / (ind + 1);
      ll tt = x % (ind + 1);
      ll right = mp[ind].first - rr + 1;
      if (rr > 0)
        mx += (mp[ind].first - right + 1) * (mp[ind].first + right) / 2 * (ind + 1);
      mx += tt * (right - 1);
      x = 0;
    }
    ind++;
  }
  cout << mx << '\n';
  return 0;
}