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

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  LL rd(deg, dis);
  LL a = (deg * 32) / 3600;
  DD b = (DD)dis / 6;

  if (round(b) <= 2)
  {
    pr("C 0\n");
    Ret;
  }
  if (a < 1)
    pr("N");
  else if (a < 3)
    pr("NNE");
  else if (a < 5)
    pr("NE");
  else if (a < 7)
    pr("ENE");
  else if (a < 9)
    pr("E");
  else if (a < 11)
    pr("ESE");
  else if (a < 13)
    pr("SE");
  else if (a < 15)
    pr("SSE");
  else if (a < 17)
    pr("S");
  else if (a < 19)
    pr("SSW");
  else if (a < 21)
    pr("SW");
  else if (a < 23)
    pr("WSW");
  else if (a < 25)
    pr("W");
  else if (a < 27)
    pr("WNW");
  else if (a < 29)
    pr("NW");
  else if (a < 31)
    pr("NNW");
  else
    pr("N");
  PS;
  if (round(b) < 16)
    pr("1");
  else if (round(b) < 34)
    pr("2");
  else if (round(b) < 55)
    pr("3");
  else if (round(b) < 80)
    pr("4");
  else if (round(b) < 108)
    pr("5");
  else if (round(b) < 139)
    pr("6");
  else if (round(b) < 172)
    pr("7");
  else if (round(b) < 208)
    pr("8");
  else if (round(b) < 245)
    pr("9");
  else if (round(b) < 285)
    pr("10");
  else if (round(b) < 327)
    pr("11");
  else
    pr("12");
  PN;
  Ret;
}
