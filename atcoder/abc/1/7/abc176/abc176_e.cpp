#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll h, w, m, x, y, mx = 0, my = 0, ans = 0;
  cin >> h >> w >> m;
  vector<ll> a(h, 0), b(w, 0), c, d;
  map<pair<ll, ll>, ll> mp;
  for (int i = 0; i < m; i++)
  {
    cin >> x >> y;
    a[x - 1]++;
    b[y - 1]++;
    mp[make_pair(x - 1, y - 1)]++;
  }
  for (int i = 0; i < h; i++)
    mx = max(mx, a[i]);
  for (int i = 0; i < w; i++)
    my = max(my, b[i]);
  for (int i = 0; i < h; i++)
    if (a[i] == mx)
      c.push_back(i);
  for (int i = 0; i < w; i++)
    if (b[i] == my)
      d.push_back(i);
  for (auto &xx : c)
  {
    for (auto &yy : d)
    {
      if (mp.find(make_pair(xx, yy)) == mp.end())
      {
        cout << mx + my << endl;
        return 0;
      }
    }
  }
  cout << mx + my - 1 << endl;
  return 0;
}
