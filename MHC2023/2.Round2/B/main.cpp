#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

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
#define INF (1LL << 60)
#define MOD1 1000000007
#define MOD2 998244353
#define MAX_N 100100

template <class T>
struct Compression
{
  unordered_map<T, int> coor;
  long long n;

  Compression(vector<T> aa)
  {
    n = aa.size();
    sort(aa.begin(), aa.end());
    int ind = 1;
    for (int i = 0; i < n; i++)
    {
      if (coor.find(aa[i]) != coor.end())
        continue;
      coor[aa[i]] = ind++;
    }
  }

  int query(T val) { return coor[val]; }
};

long long big_pow(long long a, long long b, long long mod)
{
  long long d = 1;
  while (b > 0)
  {
    if (b % 2 == 1)
      d = d * a % mod;
    b /= 2;
    a = a * a % mod;
  }
  return d;
}

void solve()
{
  LL rd(n);
  V<LL> rdv(a, n);
  V<LL> rdv(b, n);
  rep(i, n)
  {
    a.push_back(b[i]);
    b.push_back(a[i]);
  }
  rep(i, n)
  {
    a.push_back(a[i]);
    b.push_back(b[i]);
  }
  rep(i, n)
  {
    a.push_back(b[i]);
    b.push_back(a[i]);
  }
  LL N = 4 * n;

  Compression<LL> com(a);
  rep(i, N)
  {
    a[i] = com.query(a[i]);
    b[i] = com.query(b[i]);
  }

  V<LL> ca(N + 1, 0);
  V<LL> cb(N + 1, 0);
  V<LL> eq(N + 1, 0);

  rep(i, N)
  {
    ca[i + 1] = ca[i] + (a[i] < b[i]);
    cb[i + 1] = cb[i] + (a[i] > b[i]);
  }

  LL p = 4000043;
  V<LL> g(3 * n, 0), h(3 * n, 0);
  LL p_pow = 1;

  rep(i, n)
  {
    g[0] = (g[0] + a[i] * p_pow) % MOD1;
    h[0] = (h[0] + b[n - 1 - i] * p_pow) % MOD1;
    p_pow = (p_pow * p) % MOD1;
  }

  repa(i, 1, 3 * n)
  {
    LL tmph = (h[i - 1] - (big_pow(p, n - 1, MOD1) * b[i - 1]) % MOD1 + MOD1) % MOD1;
    tmph = tmph * p % MOD1;
    h[i] = (tmph + b[i + n - 1]) % MOD1;

    LL tmp = (g[i - 1] + MOD1 - a[i - 1]) % MOD1;
    tmp = tmp * big_pow(p, MOD1 - 2, MOD1) % MOD1;
    g[i] = (tmp + a[i + n - 1] * big_pow(p, n - 1, MOD1) % MOD1) % MOD1;
  }

  rep(i, 3 * n)
  {
    bool f1 = (ca[i + n / 2] - ca[i]) == n / 2;
    bool f2 = (n % 2 == 0) ? true : (a[i + n / 2] == b[i + n / 2]);
    bool f3 = (cb[i + n] - cb[i + n / 2 + n % 2]) == n / 2;
    bool f4 = (g[i] == h[i]);
    if (f1 && f2 && f3 && f4)
    {
      prn(i);
      return;
    }
  }
  prn(-1);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  LL rd(T);
  rep(i, T)
  {
    cout << "Case #" << i + 1 << ": ";
    solve();
  }
  return 0;
}
