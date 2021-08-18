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

#define MAX_N 100100

vector<vector<ll>> vp(MAX_N, vector<ll>());
ll n, m, a, b, t = 0;
priority_queue<ll, vector<ll>, less<ll>> pq;
int main()
{
  FAST;
  cin >> n >> m;
  repa(i, 0, n)
  {
    cin >> a >> b;
    if (a <= m)
      vp[a - 1].push_back(b);
  }
  repa(i, 0, m)
  {
    for (auto const &k : vp[i])
      pq.push(k);

    if (!pq.empty())
    {
      t += pq.top();
      pq.pop();
    }
  }

  cout << t << endl;
  return 0;
}