// https://atcoder.jp/contests/abc132/tasks/abc132_c

#include <iostream>
#include <algorithm>
#include <vector>
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

str cyesno(bool cond)
{
  return cond ? "Yes" : "No";
}
str uyesno(bool cond)
{
  return (cond) ? "YES" : "NO";
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  ll n, m;
  ll a[1000000];
  cin >> n;
  repin(a, n);
  sort_arr(a, n);

  m = n / 2;

  if (a[m] == a[m - 1])
  {
    cout << 0 << endl;
  }
  else
  {
    cout << a[m] - (a[m - 1] + 1) + 1 << endl;
  }

  return 0;
}