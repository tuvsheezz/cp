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
#define MAX_N 100100

int main()
{
  FAST;
  string s;
  cin >> s;
  repa(i, 0, s.size())
  {
    if (s[i] == 'D' || s[i] == 'O')
      s[i] = '0';
    if (s[i] == 'I')
      s[i] = '1';
    if (s[i] == 'Z')
      s[i] = '2';
    if (s[i] == 'S')
      s[i] = '5';
    if (s[i] == 'B')
      s[i] = '8';
  }
  cout << s << endl;
  return 0;
}