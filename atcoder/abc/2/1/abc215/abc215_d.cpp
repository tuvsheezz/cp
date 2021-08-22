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
#define MAX_N 1010101

vector<bool> is_prime(MAX_N, true);
vector<bool> is_coprime(MAX_N, true);
vector<ll> prime_numbers;

void pre()
{
  is_prime[0] = false;
  is_prime[1] = false;
  repa(i, 2, MAX_N + 1)
  {
    if (!is_prime[i])
      continue;
    ll mult = 2;
    while (i * mult <= MAX_N)
    {
      is_prime[i * mult] = false;
      mult++;
    }
  }
  repa(i, 0, MAX_N + 1)
  {
    if (is_prime[i])
      prime_numbers.push_back(i);
  }
}

vector<ll> prime_divisors(ll n)
{
  vector<ll> res;
  ll tmp = n;
  for (auto const &x : prime_numbers)
  {
    if (x * x > n)
      break;
    while (n % x == 0)
    {
      res.push_back(x);
      n /= x;
    }
  }
  if (n > 1)
    res.push_back(n);
  sort(res.begin(), res.end());
  return res;
}

void coprime_table(ll n, ll m)
{
  repa(i, 1, MAX_N + 1)
  {
    if (n * i > m)
      break;
    if (i * n <= m)
      if (i * n != 1)
        is_coprime[i * n] = false;
  }
}

int main()
{
  FAST;
  pre();
  ll n, m, t;
  map<ll, bool> checked;
  vector<ll> ans;
  cin >> n >> m;
  repa(i, 0, n)
  {
    cin >> t;
    auto divs = prime_divisors(t);
    for (auto const &x : divs)
    {
      if (checked[x])
        continue;
      coprime_table(x, m);
      checked[x] = true;
    }
  }
  repa(i, 1, m + 1)
  {
    if (is_coprime[i])
      ans.push_back(i);
  }
  cout << ans.size() << '\n';
  for (auto const &x : ans)
  {
    cout << x << '\n';
  }
  return 0;
}