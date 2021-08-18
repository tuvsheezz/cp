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
#define sort_arr(v, n) sort(v, v + n)

ll gcd(ll a, ll b)
{
  return a % b == 0 ? b : gcd(b, a % b);
}
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

str cyesno(bool cond)
{
  return cond ? "Yes" : "No";
}
str uyesno(bool cond)
{
  return (cond) ? "YES" : "NO";
}

ll n, a[100100], b[100100];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  repa(i, 0, n) cin >> a[i], b[a[i] - 1] = i + 1;
  repa(i, 0, n) cout << b[i] << " ";
  return 0;
}