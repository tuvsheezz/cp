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
  map<string, bool> mp;
  string s;
  ll n;
  cin >> n;
  while (n--)
  {
    cin >> s;
    if (s[0] == '!')
    {
      string tm = "";
      repa(i, 1, s.size())
      {
        tm += s[i];
      }
      if (mp[tm] == true)
      {
        cout << tm << '\n';
        return 0;
      }
      else
      {
        mp[s] = true;
      }
    }
    else
    {
      if (mp["!" + s] == true)
      {
        cout << s << '\n';
        return 0;
      }
      else
      {
        mp[s] = true;
      }
    }
  }
  cout << "satisfiable" << '\n';
  return 0;
}