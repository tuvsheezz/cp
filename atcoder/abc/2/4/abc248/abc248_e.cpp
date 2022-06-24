#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll n, k, x, y;
  cin >> n >> k;
  vector<pair<ll, ll>> p;
  for (int i = 0; i < n; i++)
  {
    cin >> x >> y;
    p.push_back(make_pair(x, y));
  }
  if (k == 1)
  {
    cout << "Infinity" << '\n';
    return 0;
  }

  map<vector<ll>, ll> mp;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i == j)
        continue;
      vector<ll> cur = {i, j};
      for (int l = 0; l < n; l++)
      {
        if (i == l || j == l)
          continue;
        ll y1 = p[i].second;
        ll y2 = p[j].second;
        ll y3 = p[l].second;
        ll x1 = p[i].first;
        ll x2 = p[j].first;
        ll x3 = p[l].first;
        ll s = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);

        if (s == 0)
          cur.push_back(l);
      }
      if (cur.size() >= k)
      {
        sort(cur.begin(), cur.end());
        mp[cur]++;
      }
    }
  }
  cout << mp.size() << '\n';
  return 0;
}
