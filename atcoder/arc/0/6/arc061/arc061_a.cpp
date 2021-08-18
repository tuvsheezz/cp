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

ll dfs(queue<ll> digits, ll sum, ll current)
{
  if (digits.empty())
  {
    return sum + current;
  }
  ll digit = digits.front();
  digits.pop();
  return dfs(digits, sum + current, digit) + dfs(digits, sum, current * 10 + digit);
}

int main()
{
  string s;
  queue<ll> digits;

  cin >> s;
  repa(i, 0, s.size())
  {
    digits.push(s[i] - '0');
  }
  cout << dfs(digits, 0, 0) / 2 << endl;
  // ll R = 0, len = s.size();
  // repa(t, 0, 1 << (len - 1))
  // {
  //   ll g = s[0] - '0';
  //   repa(i, 0, len - 1)
  //   {
  //     if (t & (1 << i))
  //     {
  //       R += g;
  //       g = 0;
  //     }
  //     g = g * 10 + s[i + 1] - '0';
  //   }
  //   R += g;
  // }
  // cout << R << endl;
  return 0;
}