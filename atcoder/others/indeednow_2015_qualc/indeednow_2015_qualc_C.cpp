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
ll n, a, b;
bool print_space = false;
map<ll, bool> vs;
map<ll, vector<ll>> mp;
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  n--;
  while (n--)
  {
    cin >> a >> b;
    mp[a].push_back(b);
    mp[b].push_back(a);
    vs[a] = false;
    vs[b] = false;
  }

  pq.push(1);
  while (true)
  {
    if (pq.empty())
    {
      cout << endl;
      return 0;
    }
    ll pq_top = pq.top();
    pq.pop();
    if (print_space)
      cout << " ";
    cout << pq_top;
    print_space = true;
    vs[pq_top] = true;
    for (auto const x : mp[pq_top])
    {
      if (!vs[x])
        pq.push(x);
    }
  }
}