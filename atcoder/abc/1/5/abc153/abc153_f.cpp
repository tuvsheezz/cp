#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll n, d, a, x, h, cur = 0, ans = 0;
  cin >> n >> d >> a;
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
  for (int i = 0; i < n; i++)
  {
    cin >> x >> h;
    pq.push(make_pair(x, -h));
  }

  while (!pq.empty())
  {
    if (pq.top().second < 0LL)
    {
      if (pq.top().second + cur < 0)
      {
        x = (-cur - pq.top().second + a - 1) / a;
        ans += x;
        cur += x * a;
        pq.push(make_pair(pq.top().first + 2 * d, x * a));
      }
    }
    else
      cur -= pq.top().second;
    pq.pop();
  }
  cout << ans << endl;
  return 0;
}
