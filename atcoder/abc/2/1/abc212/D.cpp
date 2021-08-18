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
#define MAX_N 100100

ll q, p, x, pl = 0;
priority_queue<ll, vector<ll>, greater<ll>> pq;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> q;
  repa(i, 0, q)
  {
    cin >> p;
    if (p == 3 && !pq.empty())
    {
      cout << pq.top() + pl << endl;
      pq.pop();
    }
    else if (p != 3)
    {
      cin >> x;
      if (p == 1)
        pq.push(x - pl);
      else
        pl += x;
    }
  }
  return 0;
}