#include <bits/stdc++.h>
using namespace std;
#define FAST                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define dd double
#define ll unsigned long long
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

vector<string> po2;

int main()
{
  FAST;
  ll k = 1;
  po2.push_back(to_string(k));
  repa(i, 0, 63)
  {
    k *= 2;
    po2.push_back(to_string(k));
  }

  ll T;
  string y;
  cin >> T;
  while (T--)
  {
    ll mn = 10000000;
    cin >> y;
    for (auto const &x : po2)
    {
      ll g = 0, i = 0, j = 0, xs = x.size(), ys = y.size();
      while (i < xs && j < ys)
      {
        if (x[i] == y[j])
        {
          i++;
          j++;
        }
        else
        {
          j++;
          g++;
        }
      }
      mn = min(mn, g + xs - i + ys - j);
    }
    cout << mn << '\n';
  }
  return 0;
}