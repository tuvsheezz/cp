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
  ll n, r = 0, g = 0, b = 0, a;
  cin >> n;
  string s;
  cin >> s;
  repa(i, 0, n)
  {
    if (s[i] == 'R')
      r++;
    if (s[i] == 'G')
      g++;
    if (s[i] == 'B')
      b++;
  }
  a = r * b * g;

  repa(i, 0, n)
  {
    repa(j, i + 1, n)
    {

      ll k = j + j - i;
      if (k < n && s[j] != s[i] && s[k] != s[i] && s[k] != s[j])
      {
        a--;
      }
    }
  }
  cout << a << endl;

  return 0;
}