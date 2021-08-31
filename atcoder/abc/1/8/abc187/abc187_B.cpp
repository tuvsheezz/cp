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
#define MOD2 998244353
#define MAX_N 100100

int main()
{
  FAST;
  ll n, a[2][1010], c = 0;
  cin >> n;
  repa(i, 0, n) cin >> a[0][i] >> a[1][i];

  repa(i, 0, n)
  {
    repa(j, i + 1, n)
    {
      if (abs(a[0][i] - a[0][j]) >= abs(a[1][i] - a[1][j]))
        c++;
    }
  }
  cout << c << '\n';
  return 0;
}