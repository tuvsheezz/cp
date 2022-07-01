#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  ll n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  n = min(n, 10LL);
  map<ll, ll> mp;

  for (int bit = 1; bit < (1 << n); bit++)
  {
    ll s = 0;
    for (int i = 0; i < n; i++)
    {
      if ((bit >> i) & 1)
        s = (s + a[i]) % 200;
    }
    if (mp.find(s) != mp.end())
    {
      vector<ll> p, q;
      for (int i = 0; i < n; i++)
        if ((bit >> i) & 1)
          p.push_back(i + 1);

      for (int i = 0; i < n; i++)
        if ((mp[s] >> i) & 1)
          q.push_back(i + 1);

      cout << "Yes\n";
      cout << p.size();
      for (auto &x : p)
        cout << " " << x;
      cout << '\n';
      cout << q.size();
      for (auto &x : q)
        cout << " " << x;
      cout << '\n';
      return 0;
    }
    else
      mp[s] = bit;
  }
  cout << "No\n";
  return 0;
}
