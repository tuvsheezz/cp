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
map<ll, priority_queue<int, vector<int>, greater<int>>> mp;
stack<ll> bk;

void dfs(ll v)
{
  if (print_space)
    cout << " ";
  print_space = true;
  bool print_bk = false;
  cout << v;
  vs[v] = true;
  while (!mp[v].empty())
  {
    if (!vs[mp[v].top()])
    {
      dfs(mp[v].top());
      bk.push(v);
    }
    mp[v].pop();
    if (!bk.empty())
    {
      cout << " " << bk.top();
      bk.pop();
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  n--;
  while (n--)
  {
    cin >> a >> b;
    mp[a].push(b);
    mp[b].push(a);
    vs[a] = false;
    vs[b] = false;
  }

  dfs(1);
  cout << endl;
  return 0;
}