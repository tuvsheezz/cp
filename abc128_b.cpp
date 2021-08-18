#include <bits/stdc++.h>
using namespace std;
#define FAST                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define ll long long
#define dd double
#define ull unsigned long long
#define str string
#define ivec vector<ll>
#define dvec vector<double>
#define repa(i, s, e) for (ll i = s; i < e; i++)
#define repd(i, s, e) for (ll i = s; i >= e; i--)
#define repin(a, n)          \
  for (ll i = 0; i < n; i++) \
  cin >> a[i]
#define vsorta(v) sort(v.begin(), v.end())
#define vsortd(v) sort(v.begin(), v.end(), greater<>())
#define sort_arr(v, n) sort(v, v + n)
#define MOD2 998244353
#define MAX_N 100100

int main()
{
  FAST;
  int n, x;
  string q;
  map<string, map<int, int>> mp;
  map<string, priority_queue<int, vector<int>, less<int>>> m;
  cin >> n;
  repa(i, 0, n)
  {
    cin >> q >> x;
    mp[q][x] = i + 1;
    m[q].push(x);
  }
  for (auto const &xx : m)
    while (!xx.second.empty())
    {
      x = xx.second.top();
      xx.second.pop();
      cout << mp[xx.first][x] << endl;
    }
  return 0;
}