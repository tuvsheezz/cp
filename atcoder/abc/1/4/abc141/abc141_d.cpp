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
str cyesno(bool cond)
{
  return cond ? "Yes" : "No";
}
str uyesno(bool cond)
{
  return (cond) ? "YES" : "NO";
}

ll n, m, s = 0, t, x;
priority_queue<ll, vector<ll>, less<ll>> pq;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;

  repa(i, 0, n)
  {
    cin >> t;
    pq.push(t);
  }

  while (m--)
  {
    x = pq.top();
    pq.pop();
    pq.push(x / 2);
  }

  while (!pq.empty())
  {
    s += pq.top();
    pq.pop();
  }

  cout << s << endl;
  return 0;
}