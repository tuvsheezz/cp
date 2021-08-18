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
#define MOD2 998244353

#define MAX_N 1000000

str cyesno(bool cond)
{
  return cond ? "Yes" : "No";
}
str uyesno(bool cond)
{
  return (cond) ? "YES" : "NO";
}

priority_queue<pair<int, int>> pq;
ll n, k, g;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  repa(i, 0, k)
  {
    cin >> g;
    pq.push(make_pair(g, i));
  }
  cout << pq.top().second + 1 << endl;
  repa(i, k, n)
  {
    cin >> g;
    pq.push(make_pair(g, i));
    pq.pop();
    cout << pq.top().second + 1 << endl;
  }
  return 0;
}