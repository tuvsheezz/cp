#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793238462643383279502884L
#define LL long long
#define DD double
#define ULL unsigned long long
#define STR string
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;
#define MLL map<LL, LL>
#define MSL map<STR, LL>
#define MLB map<LL, bool>
#define PQA priority_queue<LL, V<LL>, greater<LL>>
#define PQD priority_queue<LL, V<LL>, less<LL>>
#define IT iterator
#define F first
#define S second
#define PB push_back
#define PLL pair<LL, LL>
#define MP make_pair
#define rep(i, e) for (LL i = 0; i < e; i++)
#define repa(i, s, e) for (LL i = s; i < e; i++)
#define repd(i, s, e) for (LL i = s; i >= e; i--)
#define repauto(x, s) for (auto x : s)
#define rd(...) \
  __VA_ARGS__;  \
  read(__VA_ARGS__)
#define rdv(value, ...) \
  value(__VA_ARGS__);   \
  cin >> value
template <class T>
auto &operator>>(istream &is, vector<T> &xs)
{
  for (auto &x : xs)
    is >> x;
  return is;
}
template <class T>
auto &operator<<(ostream &os, vector<T> &xs)
{
  int sz = xs.size();
  rep(i, sz) os << xs[i] << " \n"[i + 1 == sz];
  return os;
}
template <class T, class Y>
auto &operator<<(ostream &os, pair<T, Y> &xs)
{
  os << "{" << xs.first << ", " << xs.second << "}";
  return os;
}
template <class T, class Y>
auto &operator>>(istream &is, vector<pair<T, Y>> &xs)
{
  for (auto &[x1, x2] : xs)
    is >> x1 >> x2;
  return is;
}
template <class... Args>
auto &read(Args &...args) { return (cin >> ... >> args); }
#define vsorta(v) sort(v.begin(), v.end())
#define vsortd(v) sort(v.begin(), v.end(), greater<>())
#define sort_arr(v, n) sort(v, v + n)
#define rev(v) reverse(v.begin(), v.end())
#define pr(x) cout << x
#define prd(x) cout << fixed << setprecision(50) << x
#define Yes cout << "Yes\n"
#define YES cout << "YES\n"
#define No cout << "No\n"
#define NO cout << "NO\n"
#define PN cout << '\n'
#define PS cout << ' '
#define Ret return 0
#define ret return
#define INF (1LL << 60)
#define MOD1 1000000007
#define MOD2 998244353
#define MAX_N 100100

vector<bool> is_prime(MAX_N, true);
V<LL> prime_numbers;

void prepare_prime_numbers()
{
  is_prime[0] = false;
  is_prime[1] = false;
  repa(i, 2, MAX_N + 1)
  {
    if (!is_prime[i])
      continue;
    LL mult = 2;
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

V<LL> prime_divisors(LL n)
{
  V<LL> res;
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
  ret res;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  prepare_prime_numbers();
  LL rd(n);
  LL ans = 1;
  V<LL> div(n + 1, 0);
  repa(i, 2, n + 1)
  {
    V<LL> tmp = prime_divisors(i);
    repauto(x, tmp) { div[x]++; }
  }

  rep(x, div)
  {
  }
  repauto(x, div)
  {
    pr(x);
    PS;
  }
  PN;
  Ret;
}
