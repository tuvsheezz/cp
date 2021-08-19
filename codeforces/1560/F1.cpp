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
  ll T;
  cin >> T;
  while (T--)
  {
    string s, q = "";
    ll k, f;
    cin >> f;
    cin >> k;
    s = to_string(f);
    ll mx = 0, tmp = f;
    while (tmp > 0)
    {
      mx = max(mx, tmp % 10);
      tmp = tmp / 10;
    }
    if (k == 1)
    {
      ll pp = s.size();
      if (s[0] - '0' == mx)
      {
        while (pp--)
          cout << s[0];
        cout << '\n';
      }
      else
      {
        while (pp--)
          cout << s[0] + 1;
        cout << '\n';
      }
    }
    else
    {
      vector<char> hh;
      ll i = 0;
      ll mx = 0, tmp = f;
      while (tmp > 0)
      {
        mx = max(mx, tmp % 10);
        tmp = tmp / 10;
      }
      while (s[i] == s[i + 1])
      {
        hh.push_back(s[i]);
        i++;
      }
      if (i < s.size())
      {
        if (s[i] > s[0])
        {
          if (s[i] == '9')
          {
            hh.pop_back();
            hh.push_back(s[0] + 1);
            while (i < s.size())
            {
              hh.push_back(s[0] + 1);
              i++;
            }
          }
          else
          {
            if (s[i] - '0' == mx)
            {
              while (i < s.size())
              {
                hh.push_back(s[0] + 1);
                i++;
              }
            }
            else
            {
              while (i < s.size())
              {
                hh.push_back(s[0] + 1);
                i++;
              }
            }
          }
        }
        else
        {
          ll mx2 = 0, tmp2 = f;
          while (tmp2 > 0)
          {
            if (tmp2 % 10 != s[0] - '0')
              mx2 = max(mx, tmp2 % 10);
            tmp2 = tmp2 / 10;
          }
          if (s[i] == mx2)
          {
            while (i < s.size())
            {
              hh.push_back(mx2);
              i++;
            }
          }
          else
          {
            char c = s[i];
            while (i < s.size())
            {
              hh.push_back(c + 1);
              i++;
            }
          }
        }
      }
      for (auto const &x : hh)
      {
        cout << x;
      }
      cout << '\n';
    }
  }
  return 0;
}