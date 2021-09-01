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
#define vsorta(v) sort(v.begin(), v.end())
#define vsortd(v) sort(v.begin(), v.end(), greater<>())
#define sort_arr(v, n) sort(v, v + n)
#define MOD1 1000000007
#define MOD2 998244353
#define MAX_N 100100

int main()
{
  FAST;
  ll n, ans;
  cin >> n;
  ll t1 = 1;
  ll t2 = 1;
  ll t3 = 1;
  while (n--)
  {
    t1 = (t1 * 10) % MOD1;
    t2 = (t2 * 9) % MOD1;
    t3 = (t3 * 8) % MOD1;
  }
  cout << (t1 + t3 + 2 * MOD1 - t2 * 2) % MOD1 << '\n';
  return 0;
}