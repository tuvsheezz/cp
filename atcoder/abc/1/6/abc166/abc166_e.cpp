#include <bits/stdc++.h>
using namespace std;
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

str cyesno(bool cond)
{
  return cond ? "Yes" : "No";
}
str uyesno(bool cond)
{
  return (cond) ? "YES" : "NO";
}

map<string, bool> ng;
ll n;
string s;
char t;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  cin >> s;
  ng[s] = true;
  t = s[s.size() - 1];
  repa(i, 1, n)
  {
    cin >> s;
    if (t != s[0] || ng[s])
    {
      cout << ((i & 1) ? "WIN" : "LOSE") << endl;
      return 0;
    }
    ng[s] = true;
    t = s[s.size() - 1];
  }

  cout << "DRAW" << endl;
  return 0;
}