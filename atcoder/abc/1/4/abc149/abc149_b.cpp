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
  ll n = 0, m = 0;
  string s;
  cin >> s;
  n = (s[0] - '0') * 10 + s[1] - '0';
  m = (s[2] - '0') * 10 + s[3] - '0';

  if (0 < n && n < 13 && m > 0 && m < 13)
    cout << "AMBIGUOUS\n";
  else if (n < 13 && n > 0)
    cout << "MMYY\n";
  else if (m < 13 && m > 0)
    cout << "YYMM\n";
  else
    cout << "NA\n";

  return 0;
}