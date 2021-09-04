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
#define iv vector<ll>
#define dv vector<double>
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i, e) for (ll i = 0; i < e; i++)
#define repa(i, s, e) for (ll i = s; i < e; i++)
#define repd(i, s, e) for (ll i = s; i >= e; i--)
#define vsorta(v) sort(v.begin(), v.end())
#define vsortd(v) sort(v.begin(), v.end(), greater<>())
#define sort_arr(v, n) sort(v, v + n)
#define pr(x) cout << x;
#define prd(x) cout << setprecision(50) << x;
#define pn() cout << '\n';
#define ps() cout << ' ';
#define MOD2 998244353
#define MAX_N 100100
ll zero = 0;

ll rl()
{
  ll n;
  cin >> n;
  return n;
}
str rs()
{
  str n;
  cin >> n;
  return n;
}
iv rv(ll n)
{
  iv a(n, 0);
  rep(i, n) { cin >> a[i]; }
  return a;
}

int main()
{
  FAST;
  ll Q = rl();
  priority_queue<int, vector<int>, greater<int>> sorted;
  queue<ll> not_sorted;

  while (Q--)
  {
    ll c = rl();
    if (c == 1)
    {
      ll x = rl();
      not_sorted.push(x);
    }
    else if (c == 2)
    {
      if (!sorted.empty())
      {
        pr(sorted.top());
        sorted.pop();
        pn();
      }
      else
      {
        pr(not_sorted.front());
        not_sorted.pop();
        pn();
      }
    }
    else
    {
      while (!not_sorted.empty())
      {
        sorted.push(not_sorted.front());
        not_sorted.pop();
      }
    }
  }
  return 0;
}
