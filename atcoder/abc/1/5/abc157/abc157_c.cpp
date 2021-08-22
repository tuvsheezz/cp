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
  ll n, m, s, c;
  cin >> n >> m;
  vector<ll> num(n, -1);

  while (m--)
  {
    cin >> s >> c;
    if (num[s - 1] != -1)
      if (num[s - 1] != c)
      {
        cout << "-1\n";
        return 0;
      }
    num[s - 1] = c;
  }

  if (num[0] == 0 && n != 1)
  {
    cout << "-1\n";
    return 0;
  }

  repa(i, 0, n)
  {
    if (num[i] == -1)
      if (i == 0 && n == 1)
        cout << num[i] + 1;
      else if (i == 0)
        cout
            << num[i] + 2;
      else
        cout << num[i] + 1;
    else
      cout << num[i];
  }
  cout << "\n";
  return 0;
}