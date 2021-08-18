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

#define MAX_N 1000000

int main()
{
  FAST;
  deque<ll> dq;
  ll n, x;
  cin >> n;
  repa(i, 0, n)
  {
    cin >> x;
    if (i & 1)
      dq.push_front(x);
    else
      dq.push_back(x);
  }
  while (!dq.empty())
  {
    if (n & 1)
    {
      cout << dq.back() << " ";
      dq.pop_back();
    }
    else
    {
      cout << dq.front() << " ";
      dq.pop_front();
    }
  }
  cout << endl;
  return 0;
}