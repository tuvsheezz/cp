#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
template <class T>
using IS = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
template <class T>
using PQA = priority_queue<T, V<T>, greater<T>>;
template <class T>
using PQD = priority_queue<T, V<T>, less<T>>;
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
#define prs(x) cout << x << ' '
#define prn(x) cout << x << '\n'
#define prd() cout << fixed << setprecision(50);
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
#define MAX_N 2001000

// Sieve of Eratosthenes
struct Sieve
{
  V<LL> f, primes;
  void init(int n)
  {
    f.resize(n + 1, 0);
    f[0] = f[1] = -1;
    repa(i, 2, n + 1)
    {
      if (f[i] > 0)
        continue;
      primes.PB(i);
      f[i] = i;
      for (LL j = i * i; j <= n; j += i)
      {
        if (f[j] == 0)
          f[j] = i;
      }
    }
  }
  bool is_prime(LL n) { ret f[n] == n; }
  V<LL> prime_factors(LL n)
  {
    V<LL> r;
    while (n != 1)
    {
      r.PB(f[n]);
      n /= f[n];
    }
    ret r;
  }
  V<PLL> prime_factors_count(LL n)
  {
    V<LL> l = prime_factors(n);
    if (l.size() == 0)
      ret{};
    V<PLL> r(1, MP(l[0], 0));
    repauto(x, l)
    {
      if (r.back().F == x)
        r.back().S++;
      else
        r.emplace_back(x, 1);
    }
    ret r;
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  LL rd(n);
  Sieve sv;
  sv.init(MAX_N);

  LL ans = sqrtl(n);

  repa(i, 2, n + 1)
  {
    auto x = sv.prime_factors_count(i);
    LL j = 1;
    repauto(y, x)
    {
      if (y.S % 2 == 1)
      {
        j *= y.F;
      }
    }
    LL l = 1, r = n + 1, m;
    while (l + 1 < r)
    {
      m = l + (r - l) / 2;
      if (m * m * j > n)
        r = m;
      else
        l = m;
    }
    ans += l;
  }
  prn(ans);
  Ret;
}
