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

void solve()
{
  LL rd(n);
  n = 2 * n - 1;
  V<LL> rdv(a, n);
  vsorta(a);
  LL ans = INF;
  if (n == 1)
  {
    prn(1);
    return;
  }

  // a0 a1 a2 ... an-2 an-1
  // 1. sum = a0 + an-1
  {
    LL sum = a[0] + a[n - 1];
    MLL mp;
    rep(i, n) mp[a[i]]++;
    LL tmp = INF, cnt = 0;
    rep(i, n)
    {
      if (mp.find(a[i]) != mp.end() && mp[a[i]] > 0)
      {
        if (mp.find(sum - a[i]) != mp.end() && mp[sum - a[i]] > 0)
        {
          mp[sum - a[i]]--;
          mp[a[i]]--;
          cnt++;
        }
        else
          tmp = sum - a[i];
      }
    }
    if (cnt == n / 2)
      ans = min(ans, tmp);
  }
  // 2. sum = a0 + an-2
  {
    LL sum = a[0] + a[n - 2];
    bool f = true;
    rep(i, n / 2) f = f && (a[i] + a[n - 2 - i] == sum);
    if (f && sum - a[n - 1] > 0)
      ans = min(ans, sum - a[n - 1]);
  }
  // 3. sum = a1 + an-1
  {
    LL sum = a[1] + a[n - 1];
    bool f = true;
    rep(i, n / 2) f = f && (a[i + 1] + a[n - 1 - i] == sum);
    if (f)
      ans = min(ans, sum - a[0]);
  }
  if (ans == INF)
    prn(-1);
  else
    prn(ans);
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
